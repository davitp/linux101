---
layout: default
title: IPC with Shared Memory
nav_order: 11
parent: Topics
---

# The inter-process communication with shared memory 
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

The topic covers main concepts and challenges of the **inter-process communication** (IPC), gives an overview of a very basic methods of inter-process communication such as exit codes, arguments of main function, files, as well as gives a basic understanding of **shared memory** and the **memory mapping** in UNIX operating systems.

## Topic Outline

1. What is inter-process communication, main challenges.
2. Basic methods of inter-process communication using exit codes, arguments and file system.
3. Introduction to shared memory, memory mapping and memory-mapped IO.
4. Shared memory using POSIX (shm_open, mmap) and SysV (shmget, shmat) API standards.

## Practice

1. Write a program and map a regular file into memory to demonstrate memory-mapped IO.
2. Write a program that demonstrates usage of shared memory functionality with one of standards. 

