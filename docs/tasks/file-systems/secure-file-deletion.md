---
layout: default
title: 'FS-3: Secure file deletion'
parent: File Systems
grand_parent: Tasks
nav_order: 3
---

# FS-3: Secure file deletion

### Description
Your task is to implement a C++ program that deletes the file from the filesystem along with its content by replacing every byte in the files with '\0' character.

### Requirements 

- Write a C++ program named "hacker-rm" that accepts a path to a file as a command-line argument.
- Implement proper error handling to check if the file exists and if the input path is valid.
- Open the file for writing and replace every byte with the null character ('\0').
- Remove the file from the file system after overwriting its content.
- Ensure that your program works for various file sizes and types.

Hint: you can use write, stat, lseek, unlink function to solve the problem.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./hacker-rm file-to-erase
```


The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 