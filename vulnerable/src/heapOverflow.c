#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program attempts to demonstrate a heap overflow.
 * 
 * A struct is used. It is allocated on the heap with a small char
 * buffer (size 8), and an integer to store a privilege level.
 * 
 * The idea is to corrupt the privilege level integer with user input.
 * 
 * This demonstration relies on the privilegeLevel int being stored
 * after the 8 byte char array within the struct layout in memory.
 * 
 * strcpy() will copy user input from a larger local buffer [100] into
 * the smaller copied array [8] inside the heap-allocated struct. Since 
 * strcpy() does not check the length of the string it will copy, 
 * it should be possible to overrun and corrupt the privilegeLevel 
 * integer if you enter more than 7 characters when prompted 
 * (7 because strcpy() will automatically add the null terminator).
 * 
 */

struct Helper {
    char copied[8];
    int privilegeLevel;
};

/*
 * Above defines a structure called Helper, with the small char
 * array intended to be used to cause overflow, and the privilegeLevel
 * the program is intended to corrupt.
 * 
 * Since the struct will be allocated using malloc(), both of these
 * fields will be on the heap!
 * 
 */

int main(void) {
    char input[100]; //local array on the stack, for user input!
    
    struct Helper *helper = malloc(sizeof(struct Helper));
    
    /*
     * Above allocates memory for a struct Helper and returns
     * its address.
     * 
     * sieof(struct Helper) determines the number of bytes needed,
     * malloc reserves that number of bytes, and helper stores the 
     * return address (as helper is a pointer to a struct)
     * 
     */
    
    if (helper == NULL) { //if so, program would crash anyway!
    printf("Memory allocation with malloc() failed.\n");
    return 1; //exits with non-0 code.
	}

    helper->privilegeLevel = 1; // stores value of '1' in privilegeLevel variable on heap.
    
    
    printf("Current value of privilege level is %d\n\n", helper->privilegeLevel);
    
    printf("This program demonstrates a heap overflow with C\n");
    printf("It contains an 8-byte character array that your input is copied into with strcpy()\n");
    printf("It also contains a privilege level variable, initially set to '1'\n");
    printf("The 4-byte privilegeLevel int variable should be stored immediately after the char array in memory\n");
    printf("Below are the memory addresses for the beginning of the char array, and privilegeLevel int.\n\n");

    printf("Memory Address of 8 byte char array: %p\n", (void *)helper->copied);
    printf("Memory Address of privilegeLevel int variable: %p\n", (void *)&helper->privilegeLevel);
    
    /*
     * The memory address of the first byte of each variable is printed
     * just so we can confirm if the variables are adjacent in
     * memory (should be a difference of 8).
     * 
     */

    printf("Enter a string to copy into an 8-byte heap buffer (>7 will overflow):\n");
    scanf("%99s", input); // write user typed input to large local buffer (input)
    
    //99 leaves room for null terminator.

    strcpy(helper->copied, input);   // strcpy does not check input length when copying!

    printf("Copied string: %s\n", helper->copied);
    printf("privilegeLevel = %d\n\n", helper->privilegeLevel);

    if (helper->privilegeLevel != 1) {
        printf("SUCCESS: Heap overflow has corrupted the privilege level.\n");
    } else {
		printf("FAIL: No corruption of privilegeLevel detected\n");
	}

    free(helper); // releases heap memory allocated by malloc(). 
    return 0;
}
