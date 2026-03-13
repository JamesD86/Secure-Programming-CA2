#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program attempts to demonstrate how to prevent a heap overflow
 * caused by user input.
 * 
 * A struct is used. It is allocated on the heap with a small char
 * buffer (size 8), and an integer to store a privilege level.
 * 
 * In the vulnerable version, oversized input can overflow the copied array
 * and corrupt the privilegeLevel variable.
 * 
 * This "fixed" version prevents the heap overrun from the vulnerable 
 * version with two main changes. Firstly, while user input is not
 * restricted to fewer characters than the vulnerable version, the
 * length is checked with strlen(). If the length is greater than 7, 
 * the program will print an error and exit with a non-zero return 
 * value.
 * 
 * Secondly, for redundancy, the program also uses strncpy() this time,
 * which does take the length into account when copying to a
 * destination array. 
 * 
 */

struct Helper {
    char copied[8];
    int privilegeLevel;
};

/*
 * Above defines a structure called Helper, with the small char
 * array that could overflow when written to and potentially
 * corrupt the privilegeLevel variable.
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
     * sizeof(struct Helper) determines the number of bytes needed,
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
    
    printf("This program demonstrates avoiding a heap overflow with C\n");
    printf("It contains an 8-byte character array that your input is copied into with strncpy()\n");
    printf("It also contains a privilege level variable, initially set to '1'\n");
    printf("The 4-byte privilegeLevel int variable should be stored immediately after the char array in the struct layout\n");
    printf("Below are the memory addresses for the beginning of the char array, and privilegeLevel int.\n\n");

    printf("Memory Address of 8 byte char array: %p\n", (void *)helper->copied);
    printf("Memory Address of privilegeLevel int variable: %p\n", (void *)&helper->privilegeLevel);
    
    /*
     * The memory address of the first byte of each variable is printed
     * just so we can confirm if the variables are adjacent in
     * memory. This should usually show that privilegeLevel begins
     * 8 bytes after the copied[] array. 
     * 
     */

    printf("Enter a string to copy into an 8-byte heap buffer (shouldn't overflow):\n");
    scanf("%99s", input); // write user typed input to large local buffer (input)
    
    /*
     * Technically, the input length could be changed to 7 to avoid the
     * possibility of overflow, but the goal of this program is to fix
     * the issue of bad user input causing overflow, so I decided to leave
     * the 99 limit as it is from the vulnerable version.
     * 
     */
    
    if(strlen(input) > 7) {
		printf("ERROR: Input is too large for destination buffer. Exiting.\n");
		free(helper); //releases memory allocated by malloc() 
		return 1;
	}
    

    strncpy(helper->copied, input, sizeof(helper->copied) -1);
    helper->copied[sizeof(helper->copied) - 1] = '\0';
    
    /*
     * strncpy() can limit the maximum number of characters copied.
     * In this case we also include the -1 because
     * strncpy() will not automatically include the null terminator
     * in all cases like strcpy() will. The next line, we manually
     * add the null terminator to the 8th element on the destination
     * array (index number 7). 
     * 
     */

    printf("Copied string: %s\n", helper->copied);
    printf("privilegeLevel = %d\n\n", helper->privilegeLevel);

    if (helper->privilegeLevel != 1) {
        printf("FAIL: Heap overflow has corrupted the privilege level.\n");
    } else {
		printf("SUCCESS: No corruption of privilegeLevel detected.\n");
	}

    free(helper); // releases heap memory allocated by malloc(). 
    return 0;
}
