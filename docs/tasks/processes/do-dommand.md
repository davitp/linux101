---
layout: default
title: 'PS-1: Do command'
parent: Processes
grand_parent: Tasks
nav_order: 1
---

# PS-1: Do command


### Description
Your task is to implement a C++ program that accepts a command name and command arguments with command-line arguments and executes it in a new process.

### Requirements 

- Write a C++ program called "do-command" that takes N arguments as an input.
- Assume that first argument is command name and others are arguments for the given command.
- A program should contain a special function do_command(char** argv), where argv is null-terminated vector of arguments.
- The function "do_command" should create a new process, execute the given command with the given arguments and wait for its completion.
- After program execution is done, do_function should print exit status of the command and the duration of the command execution.
- The "main" function of the program is responsible for building proper argument vector and using do_command function to execute the command.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./do-command ls -al
```

The command is expected to print program output to the console and a line as follows:
```sh
drwxr-xr-x   8 user  user    256 Oct 21 15:45 .
drwxr-xr-x   3 user  user     96 Oct 16 16:45 ..
drwxr-xr-x  15 user  user    480 Nov  9 23:53 .git
-rw-r--r--   1 user  user    591 Oct 16 16:45 .gitignore
-rw-r--r--@  1 user  user  11357 Oct 21 15:45 LICENSE
-rw-r--r--   1 user  user     18 Oct 16 16:45 README.md
drwxr-xr-x  17 user  user    544 Oct 21 15:45 docs
drwxr-xr-x  16 user  user    512 Oct 16 16:45 samples

Command completed with X exit code and took Y seconds.
```

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
