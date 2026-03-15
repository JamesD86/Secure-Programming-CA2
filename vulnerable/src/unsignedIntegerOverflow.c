#include <stdio.h>
#include <limits.h> //needed for UINT_MAX

/*
 * This simple bank deposit program has a problem. It uses
 * an int variable to store an account balance. However, this 
 * particular account belongs to a billionaire.
 * 
 * The balance is already approaching the maximum value an unisgned int
 * variable can store (4294967295).
 * 
 * If the balance int goes beyond this value, overflow occurs. The
 * result is the value will be incorrect or will wrap to a negative.
 * 
 * This program warns about the max deposit before it is made.
 * 
 * The program will also determine what the value of the total balance
 * should be after the deposit, using long variables to store and
 * perform arithmetic operations on. This won't work correctly if 
 * the input is larger than the max value of an int. 
 * 
 */


int main(void) {
	
	unsigned int balance = 4294966835;
	unsigned int deposit = 0;
	long long longdeposit;
	long long longtotal;
	
	unsigned int maxDeposit = UINT_MAX - balance;
	
	printf("This program demonstrates an unsigned integer overflow with C.\n");
	printf("You are a billionaire with a very high balance in your account.\n");
	printf("The balance is so high it is approaching the max positive unsigned int value.\n");
	printf("The program tells you the maximum safe value you can enter.\n");
	printf("You may destroy your wealth if you attempt to deposit a higher value.\n");
	printf("NOTE: Be sure your input can fit in an int variable\n\n");
	
	printf("Your current balance is: %u\n", balance);
	printf("Your maximum safe deposit is: %u\n", maxDeposit);
	
	printf("Enter deposit total:\n");
	scanf("%u", &deposit);
	
	longdeposit = deposit;
	longtotal = (long)balance + longdeposit;
	
	balance = balance + deposit; // PROBLEM! Overflow risk!
	
	
	printf("Your new balance is: %u\n", balance);
	printf("The correct total should be: %ld\n\n", longtotal);
	
	if ((long)balance != longtotal) {
		printf("SUCCESS: Integer overflow has resulted in corrupted balance!\n");
	} else {
		printf("FAIL: No corruption of balance detected!\n");
	}
	
	return 0;

}
