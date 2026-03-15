# Secure Programming & Scripting Assignment 2
C Vulnerabilities and Overflows

Name:		James Delahunty
StudentID: 	20111312

## Description

This repo contains three examples of overflow vulnerabilities written in C.
These are:

- Stack Buffer Overflow
- Integer Overflow (Signed and Unsigned)
- Heap Overflow (strcpy() and fgets() examples)

For each vulnerability there is a vulnerable version, fixed version, and
shell script.

## Structure

CA2<br>
|<br>
|__	vulnerable/src<br>
|	|--	bufferOverflow.c<br>
|	|--	bufferOverflow.o<br>
|	|--	bufferOverflow.sh<br>
|	|--	integerOverflow.c<br>
|	|--	integerOverflow.o<br>
|	|--	integerOverflow.sh<br>
|	|--	unsignedIntegerOverflow.c<br>
|	|--	unsignedIntegerOverflow.o<br>
|	|--	unsignedIntegerOverflow.sh<br>
|	|--	heapOverflow.c<br>
|	|--	heapOverflow.o<br>
|	|--	heapOverflow.sh<br>
|	|--	fgetsHeapOverflow.c<br>
|	|--	fgetsHeapOverflow.o<br>
|	|--	fgetsHeapOverflow.sh<br>
|<br>
|__	fixed/src<br>
	|--	bufferOverflow.c<br>
	|--	bufferOverflow.o<br>
	|--	bufferOverflow.sh<br>
	|--	integerOverflow.c<br>
	|--	integerOverflow.o<br>
	|--	integerOverflow.sh<br>
	|--	unsignedIntegerOverflow.c<br>
	|--	unsignedIntegerOverflow.o<br>
	|--	unsignedIntegerOverflow.sh<br>
	|--	heapOverflow.c<br>
	|--	heapOverflow.o<br>
	|--	heapOverflow.sh<br>
	|--	fgetsHeapOverflow.c<br>
	|--	fgetsHeapOverflow.o<br>
	|--	fgetsHeapOverflow.sh<br>
	
## Requirements

- Linux recommended (tested on Debian)
- GCC

## Running Programs

Open the appropriate directory and run the shell script corresponding
to which vulnerable or fixed program you want to test.

## Notes

Programs and theory behind them is explained in the CA2 Report document.
