#include <stdio.h>
#include <limits.h> //needed for UINT_MAX

/*
 * This "fixed" version of the bank deposit program simply will 
 * not update the balance int variable if the user input is either
 * larger than the maxDeposit, or is a negative value. 
 * 
 * 
 * I should also note that I am aware that its possible for
 * a user to enter a non-int value. However, scanf will return
 * 0 if it the value isn't numerical. The deposit variable will
 * not be updated. This program and the vulnerable version
 * only deal with demonstrating or preventing int overflow based
 * on user input.
 * 
 */


int main(void) {
	
	unsigned int balance = 4294966835;
	unsigned int deposit = 0;
	
	unsigned int maxDeposit = UINT_MAX - balance;
	
	printf("This fixed version attempts to prevent an integer overflow.\n");
	
	printf("While the balance is still approaching the UINT_MAX value,\n");
	
	printf("the user input is tested to ensure it is less then the maxDeposit.\n");
	
	printf("The deposit also must be positive!.\n\n");
	
	printf("Your current balance is: %u\n", balance);
	printf("Your maximum safe deposit is: %u\n", maxDeposit);
	
	printf("Enter deposit total:\n");
	scanf("%u", &deposit);
	
	if (deposit > maxDeposit || deposit < 0) {
		printf("FAIL: Cannot process this deposit. Please try again!\n");
	} else {
		balance = balance + deposit;
		printf("SUCCESS: Your new balance is: %u\n", balance);
	}
	
	/*
	 * If the deposit goes beyond the maxDeposit, or if it is
	 * negative, it will be rejected by this program. Of course,
	 * it would be possible to simply change data type and avoid
	 * the int size problem, but this exercise is about preventing
	 * the overflow with a fix rather than changing data type
	 * entirely.
	 * 
	 */
	 
	
	return 0;

}
