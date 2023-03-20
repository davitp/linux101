---
layout: default
title: 'IPC-1: Signal Echo'
parent: IPC
grand_parent: Tasks
nav_order: 1
---

# IPC-1: Signal echo

### Requirements 

- Write a C++ program that prints its PID and registers a signal handler for **SIGUSR1**. 
- The handler of the signal **SIGUSR1** is suppose to react by printing the following information:
    - The PID of the sender process,
    - The UID and the user name of the sender,
    - The current values of the EIP, EAX, EBX registers.
- Program should enter an infinite loop and perform a sleeping delay on each iteration (example: sleep for 10 seconds). 

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./signal-echo
```

Then, once any other process sends **SIGUSR1** signal to our process, it should print the following information: 
```
Received a SIGUSR1 signal from process [PID] executed by [UID] ([username]).
State of the context: EIP = [value of EIP], EAX = [value of EAX], EBX = [value of EBX]. 
```

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
