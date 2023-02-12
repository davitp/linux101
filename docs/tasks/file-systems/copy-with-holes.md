---
layout: default
title: 'FS-3: Copy a file accounting holes'
parent: File Systems
grand_parent: Tasks
nav_order: 3
---

# FS-3: Copy a file accounting holes

### Requirements 

- Write a C++ program accepting two command line arguments representing source file path and destination file path. 
- Implement proper error handling to account if not all arguments are passed or if one of arguments is not a valid one. 
- Copy the content of the **source** file into a **destination** file. If **destination** file already exists, it should be overwritten.  
- If source file contains **holes**, the destination file should also contain hole as is.
- Print overall amount of bytes copied to the destination file including total amount of physical data and total amount of holes if any.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./copy source-file destination-file
```

After copy is completed, program should print following message to the console:

```
Successfully copied X bytes (data: M, hole: N).
```

The logical and physical sizes of source and destination files should match exactly.

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
