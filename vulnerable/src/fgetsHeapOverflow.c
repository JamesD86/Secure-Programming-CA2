#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 * This is a modified version of the heapOverflow.c demonstration.
 * 
 * It exists just to show a vulnerability that doesn't rely on strcpy()
 * like the stack overflow example.
 * 
 * This program is very similar, only in this case it uses the fgets()
 * function to write directly to the heap from user input (technically,
 * to the copied[] array buffer in the helper struct on the heap.)
 * 
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
    
    struct Helper *helper = malloc(sizeof(struct Helper));
    
    /*
     * Above allocates memory for a struct Helper and returns
     * its address.
     * 
     * sieof(struct Helper) determines the number of bytes needed,
     * malloc reserves that number of bytes, and helper stores the 
     * address returned by malloc (as helper is a pointer to a struct)
     * 
     */
    
    if (helper == NULL) { //if so, program would crash anyway!
    printf("Memory allocation with malloc() failed.\n");
    return 1; //exits with non-0 code.
	}

    helper->privilegeLevel = 1; // stores value of '1' in privilegeLevel variable on heap.
    
    
    printf("Current value of privilege level is %d\n\n", helper->privilegeLevel);
    
    printf("This program demonstrates a heap overflow with C\n");
    printf("It contains an 8-byte character array written to with fgets()\n");
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

    printf("Enter a string to copy into an 8-byte heap buffer (>6 will overflow):\n");
    fgets(helper->copied, 100, stdin);
   

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
