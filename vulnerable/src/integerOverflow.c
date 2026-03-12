#include <stdio.h>
#include <limits.h> //needed for INT_MAX

/*
 * This simple bank deposit program has a problem. It uses
 * an int variable to store an account balance. However, this 
 * particular account belongs to a billionaire.
 * 
 * The balance is already approaching the maximum positive value an int
 * variable can store (2147483647).
 * 
 * If the balance int goes beyond this value, overflow occurs. The
 * result is the value will be incorrect or will wrap to a negative.
 * 
 * This program warns about the max deposit before it is made.
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
	
	balance = balance + deposit; // PROBLEM! Overflow risk!
	
	printf("Your new balance is: %d\n", balance);

}
