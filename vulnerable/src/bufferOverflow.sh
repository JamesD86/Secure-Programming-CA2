#!/bin/bash
gcc -fno-stack-protector bufferOverflow.c -o bufferOverflow.o
./bufferOverflow.o
