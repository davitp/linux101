---
layout: default
title: 'IPC-3: Shared Array'
parent: IPC
grand_parent: Tasks
nav_order: 3
---

# IPC-3: Shared array implementation

### Requirements 

- Write a C++ class implementing a module **shared_array** which is an array of integers shared between processes.
- The class is suppose to be initialized as follows: shared_array array("array-name", size);
- The size of the array (number of elements) could be between 1 and 1 000 000 000
- Two shared arrays are same in the system if they have equal name and size, otherwise they are different. 
- The class should provide operator [] for indexing an element with given index i.
- Any process that knows the name and the size of the array should be able to use it.
- Write two infinite programs (first and second) to work with the shared array using cross-process semaphore.

### Expected result

The resulting application should be able to build from command line as follows:

```sh
make first
make second
```
The execution of the program should demonstrate how the array changes from first and second processes.

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
