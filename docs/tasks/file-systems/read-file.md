---
layout: default
title: 'FS-1: Read from the file'
parent: File Systems
grand_parent: Tasks
nav_order: 1
---

# FS-1: Read from the file

### Description
You need to implement a program that does the same thing as the **cat** command in the Linux.

### Requirements 

- Write a C++ program **read-file** accepting a file path as an argument. 
- Implement proper error handling to make sure required file path is passed. 
- Open the given file with proper mode and make sure errors are handled.  
- Read the content of the file into a buffer until reaching the end of the file.
- Print every portion of the file read in the iteration.

Hint: if you use printf or std::cin, make sure your strings are terminated with '\0' symbol.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./read-file input.txt
```

The program should output the content of the input.txt file on the screen.

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
