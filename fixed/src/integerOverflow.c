#include <stdio.h>
#include <limits.h> //needed for INT_MAX

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
	
	int balance = 2147482691;
	int deposit = 0;
	
	int maxDeposit = INT_MAX - balance;
	
	printf("Your current balance is: %d\n", balance);
	printf("Your maximum safe deposit is: %d\n", maxDeposit);
	
	printf("Enter deposit total:\n");
	scanf("%d", &deposit);
	
	if (deposit > maxDeposit || deposit < 0) {
		printf("Cannot process this deposit. Please try again!\n");
	} else {
		balance = balance + deposit;
		printf("Your new balance is: %d\n", balance);
	}
	return 0;

}
