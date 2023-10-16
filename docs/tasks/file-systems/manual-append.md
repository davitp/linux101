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

- Write a C/C++ program that gets the filepath with the first argument and opens it.
- File **should not** be opened with the O_APPEND file. 
- You are not allowed to use seek/lseek to move the cursor to the end.
- The program writes two lines: "first line" and "second line". Each line is written in a different descriptor.
- After write, the file should contain both lines in the same file.

Hint: you may use dup/dup2.

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
