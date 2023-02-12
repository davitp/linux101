---
layout: default
title: 'TH-1: Array Summary'
parent: Threads
grand_parent: Tasks
nav_order: 1
---

# TH-1: The array summary

### Requirements 

- Write a C++ program creates an array of N elements (N > 1 000 000).
- Initialize the array with random values at the beginning. 
- Compute summary of the array using a regular for loop and calculate the time spent for the operation.
- Create M threads to sum the same array with multiple threads, considering that every thread gets an equal portion to sum, except, maybe, the last one.
- Wait for all the threads to complete and measure the time spent for summing the array using M threads. 
- Print the durations spent to sum the array with and without threads.
- Note that N and M variables should be passed to the program via command line arguments.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./array-summary 1000000 4
```
and the command should print the output to the console as follows:

```
Time spent without threads: X
Time spent with M threads: Y
```

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
