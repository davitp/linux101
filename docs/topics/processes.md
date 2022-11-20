---
layout: default
title: Processes
nav_order: 7
parent: Topics
---

# Overview of the concept of process in Unix operating systems 
{: .no_toc }

<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>

The topic is a brief introduction to the concept of **process** in Unix Operating Systems. It covers basic definition of the process as a program in an execution state, tree of process (init process, parent/child relationship), the virtual memory of a process and programmability API for processes such as fork, wait, exec functions.

## Topic Outline

1. The definition of the concept of process, init and process tree.
2. Brief introduction to the virtual memory, page and page table of the process.  
3. Other properties of the process: pid, file descriptor table, etc.
4. The process creation workflow: fork and clone, the process lifecycle. 
5. The execution of the program in a process, using exec* functions.

## Practice

1. Practical overview of the process tree, working with processes from shell using ps.
2. Writing a simple program to demonstrate process lifecycle using fork, wait and exec functions.
3. Demonstrate usage of command line arguments with exec, the environment variables their inheritance.

