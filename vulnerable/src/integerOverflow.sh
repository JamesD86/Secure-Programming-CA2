#!/bin/bash
gcc -fno-stack-protector integerOverflow.c -o integerOverflow.o
./integerOverflow.o
