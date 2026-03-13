# Secure Programming & Scripting Assignment 2
C Vulnerabilities and Overflows

Name:		James Delahunty
StudentID: 	20111312

## Description

This repo contains three examples of overflow vulnerabilities written in C.
These are:

- Stack Buffer Overflow
- Integer Overflow
- Heap Overflow

For each vulnerability there is a vulnerable version, fixed version, and
shell script.

## Structure

CA2
|
|__	vulnerable/src
|	|--	bufferOverflow.c
|	|--	bufferOverflow.o
|	|--	bufferOverflow.sh
|	|--	integerOverflow.c
|	|--	integerOverflow.o
|	|--	integerOverflow.sh
|	|--	heapOverflow.c
|	|--	heapOverflow.o
|	|--	heapOverflow.sh
|
|__	fixed/src
	|--	bufferOverflow.c
	|--	bufferOverflow.o
	|--	bufferOverflow.sh
	|--	integerOverflow.c
	|--	integerOverflow.o
	|--	integerOverflow.sh
	|--	heapOverflow.c
	|--	heapOverflow.o
	|--	heapOverflow.sh
	
## Requirements

- Linux recommended (tested on Debian)
- GCC

## Running Programs

Open the appropriate directory and run the shell script corresponding
to which vulnerable or fixed program you want to test.

## Notes

Programs and theory behind them is explained in the CA2 Report document.
