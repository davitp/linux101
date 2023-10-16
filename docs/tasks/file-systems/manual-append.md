---
layout: default
title: 'FS-6: Manual append'
parent: File Systems
grand_parent: Tasks
nav_order: 6
---

# FS-6: Manaul append

### Description

Your task is to write a program on C/C++ that writes two lines in the files "first line" and "second line".
Writing should happen into two different file descriptors but write into the same file.

### Requirements 

In this assignment, you will write a C/C++ program to write two lines of text into the file "exclusive_file.log" using two separate file descriptors. The challenge is to perform this task without explicitly or implicitly changing the offset of the file descriptor (e.g., using "seek" or "open" with "O_APPEND" mode).
hint: use dup/dup2

- Write a C/C++ program that gets the filepath with the first argument and opens it.
- File **should not** be opened with the O_APPEND file. 
- You are not allowed to use seek/lseek to move the cursor to the end.
- The program writes two lines: "first line" and "second line". Each line is written in a different descriptor.
- After write, the file should contain both lines in the same file.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./manual-append result.txt
```

The output file should contain the following text:
```
first line
second line
```

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
