---
layout: default
title: 'IPC-2: Prime Calculator'
parent: IPC
grand_parent: Tasks
nav_order: 2
---

# IPC-2: Prime calculator

### Requirements 

- Write a C++ program that creates a child process.
- The main process infinitely waits for the user's input integer **m**. 
- Once number **m** is received to the main process, it gets passed to the child process via **anonymous pipe**. 
- The child process takes number m from the anonymous pipe and calculates the m-th prime number. 
- The child process should send the result of the calculation back to the parent process, which, should print it and wait for the next input.  
- If "exit" command is entered, main process should stop it's execution. 

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./prime-calculator
```

Typical execution of the program should look like following:
```
[Parent] Please enter the number: **8**
[Parent] Sending 8 to the child process...
[Parent] Waiting for the response from the child process...
[Child] Calculating 8-th prime number...
[Child] Sending calculation result of prime(8)...
[Parent] Received calculation result of prime(8) = 19...
```

The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 
