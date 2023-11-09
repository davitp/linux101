---
layout: default
title: 'PS-2: Interactive shell'
parent: Processes
grand_parent: Tasks
nav_order: 2
---

# PS-2: Interactive shell

### Requirements 

- Write a C++ program that implements an interactive shell with an infinite loop waiting for a command.
- On every iteration of the loop a command string is passed to the shell program. 
- A command can be either a name of command or a path (relative or absolute).
- After command is entered, program should create a new process to run the command.
- The current directory of the shell program should be temporarily added to the PATH variable of every new process. 
- If "exit" command is entered, shell program should stop and exit with a success code. 
- If entered command starts with word "silent", the executing command should redirect the standard output and error streams into the PID.log file where PID is the process id of the child process. 

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./interactive-shell
```

User may enter commands as follows:
```
ls
```
or
```
/bin/ls
```
or
```
./other-program
```
and the command should print the output to the console. 

Also user may want to enter commands as follows
```
silent ls -al
```
and the output of program ls should be redirected into the file PID.log where PID is the identifier of the child process.

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
