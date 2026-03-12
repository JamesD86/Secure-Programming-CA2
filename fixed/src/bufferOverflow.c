#include <stdio.h>
#include <string.h>

/*
 * This is an attempt to fix the buffer overflow caused by the copying
 * of a long string into an array too small to store it.
 * 
 * The vulnerable version of this program used strcpy() to copy
 * the user's input into the "copied" array. strcpy() is vulnerable
 * because it will copy out of bounds and write to memory beyond the
 * allocated space.
 * 
 * In this fix, I use strncpy() instead, which allows for bounded copying
 * of a string. I also manually add the null terminator at the end of the
 * "copied" array.
 * 
 * Whatever is copied from the input is pasted, and the privilege
 * level integer is shown. Finally, a message is printed based on
 * wherher or not corruption has occurred.
 * 
 */
 
struct Helper {
	 char copied[8];
	 int privilegeLevel;
};

int main(void) {
    char input[100];
    struct Helper helper;
    
    helper.privilegeLevel = 1;

    printf("Enter a string to copy into an 8-byte buffer:\n");
    scanf("%99s", input);
    
    strncpy(helper.copied, input, sizeof(helper.copied) - 1); // size set
    helper.copied[sizeof(helper.copied) - 1] = '\0'; // adding null terminaator


    printf("Copied string: %s\n", helper.copied);
    printf("privilegeLevel = %d\n", helper.privilegeLevel);

    if (helper.privilegeLevel != 1) {
        printf("WARNING: Corruption of privilege level has occurred.\n");
    } else {
		printf("No corruption detected!\n");
	}

    return 0;
}
