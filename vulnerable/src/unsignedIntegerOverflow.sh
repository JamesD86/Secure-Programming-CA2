#!/bin/bash
gcc -fno-stack-protector -o unsignedIntegerOverflow.o unsignedIntegerOverflow.c
./unsignedIntegerOverflow.sh
