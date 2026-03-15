#!/bin/bash
echo "WARNING: THE COMPILER MAY SHOW WARNINGS ABOUT THIS PROGRAM."
echo "IT STILL COMPILED CORRECTLY WITH GCC IN DEBIAN LINUX!"
gcc -o fgetsHeapOverflow.o fgetsHeapOverflow.c
./fgetsHeapOverflow.o
