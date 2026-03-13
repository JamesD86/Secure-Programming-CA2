#include <stdio.h>
#include <string.h>

/*
 * Buffer Overflow example based on past lab submission.
 * 
 * The goal here is to write too many characters into a char array
 * and cause it to corrupt an int variable. Earlier versions of
 * this program simply put the char array and variable in the main
 * method, but it was actually rare to produce the intended overflow
 * and corruption. Therefore, this one utiizes a struct called Helper
 * as the fields should be stored together in order.
 * 
 * scanf() is used to read in a string and save it to a
 * char array "input" of size 100.
 * 
 * strcpy is used to duplicate the user-entered string into
 * a char array "copied", of size 8. If the user enters more than
 * 8 characters (technically 7 + null terminator) bytes will be written
 * beyond the end of the array, and will very likely corrupt
 * an int variable called "privilegeLevel". 
 * 
 * Once copied, the string is printed to the console.
 * 
 * int variable "privilegeLevel" (initial value of 1)
 * is then printed to console. If it has been corrupted,
 * a warning of the corruption is then printed after.
 * 
 */
 
struct Helper {
	 char copied[8];
	 int privilegeLevel;
};

/*
 * Using this helper struct greatly improved the chances of
 * an overflow successfully corrupting the privilegeLevel int
 * varaible value.
 * 
 */

int main(void) {
    char input[100]; // local large buffer for user input
    struct Helper helper; //creates new helper struct
    
    helper.privilegeLevel = 1;
    
    printf("The current value of privilege level is: %d\n\n", helper.privilegeLevel);
    
    printf("Vulnerable array memory address: %p\n", (void *)helper.copied);
    printf("INT variable privilegeLevel memory address: %p\n",  (void *)&helper.privilegeLevel);
    printf("Distance between fields: %ld bytes\n\n", (char *)&helper.privilegeLevel - (char *)helper.copied);
    

    printf("Enter a string to copy into an 8-byte buffer (>7 will overflow):\n");
    scanf("%99s", input);

    strcpy(helper.copied, input);  // vulnerable as there is no bounds check!

    printf("Copied string: %s\n", helper.copied);
    printf("privilegeLevel value is = %d\n", helper.privilegeLevel);

    if (helper.privilegeLevel != 1) {
        printf("SUCCESS: Corruption of privilege level has occurred.\n");
    } else {
		printf("FAIL: No corruption of privilege level detected.\n");
	}

    return 0;
}
