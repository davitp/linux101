---
layout: default
title: 'FS-6: Exclusive Log'
parent: File Systems
grand_parent: Tasks
nav_order: 6
---

# FS-4: Exclusive Log

### Requirements 

In this assignment, you will write a C/C++ program to write two lines of text into the file "exclusive_file.log" using two separate file descriptors. The challenge is to perform this task without explicitly or implicitly changing the offset of the file descriptor (e.g., using "seek" or "open" with "O_APPEND" mode).
hint: use dup/dup2

- Write a C/C++ program that creates and opens the file "exclusive_file.log".
- Ensure proper error handling for file creation and opening.
- The two lines of text should be written to the file without changing the offset of the file descriptor.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./hacker_rm file_to_be_completely_removed
```
