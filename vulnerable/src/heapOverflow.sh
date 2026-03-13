#!/bin/bash
gcc -fno-stack-protector heapOverflow.c -o heapOverflow.o
./heapOverflow.o
