---
layout: default
title: 'FS-4: Secure File Deletion'
parent: File Systems
grand_parent: Tasks
nav_order: 4
---

# FS-4: Secure File Deletion

### Requirements 
Your task is to write a C++ program called "hacker_rm" that takes a path to a file as input, replaces every byte in that file with the null character ('\0'), and then removes the file.
hint: Use write/stat/fstat/lseek/seek/unlink/remove POSIX functions.

- Write a C++ program named "hacker_rm" that accepts a path to a file as a command-line argument.
- Implement proper error handling to check if the file exists and if the input path is valid.
- Open the file for writing and replace every byte with the null character ('\0').
- Remove the file from the file system after overwriting its content.
- Ensure that your program works for various file sizes and types.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./hacker_rm file_to_be_completely_removed
```
