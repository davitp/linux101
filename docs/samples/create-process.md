---
layout: default
title: Creating a process
nav_order: 8
parent: Samples
---

# Creating a process
{: .no_toc }

The sample demonstrates how to create a process using **fork()** function.

```c
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <cerrno>
#include <sys/wait.h>

int main(){

    // starting a parent process
    std::cout << "Parent process started... " << std::endl;

    // create a child process by cloning the current one 
    pid_t child = fork();

    // make sure we did not fail while creating a process
    if(child == -1){
        return errno;
    }

    // if the return value of the fork() is 0, then we are now running in the child process
    // if the return value of the fork() is positive, then we are running inside the parent process
    if(child == 0){
        // this will be printed ONLY from the child process
        std::cout << "Child process says hello. PID: " << getpid() << std::endl;
    }
    else if(child > 0){
        // this will be printed ONLY from the parent process
        std::cout << "This will only be executed in parent process. PID: " << getpid() << std::endl;
    }

    // this message will be printed twice: from both parent and child processes
    std::cout << "General hello from " << getpid() << std::endl;

    // wait for child only in parent
    if(child > 0){
        
        // a variable to keep exit code of the child process once it finishes
        int childStatus = -1;

        // wait for the completion of the child process
        pid_t waitingChildPid = waitpid(child, &childStatus, 0);

        // child process completes its execution with a "childStatus" exit code
        std::cout << "Child process is over, we can complete parent as well. Child process exit code " << childStatus << std::endl;
    }

    // process completion message from both processes
    std::cout << "Completing process " << getpid() << std::endl;

    return 0;
}
```

The file can be compiled and executed as follows:
```sh
g++ fork.cpp -o fork
./fork
```

The program is suppose to start a process and clone itself printing appropriate messages as follows:

```
Parent process started...
This will only be executed in parent process. PID: 328
General hello from 328
Child process says hello. PID: 329
General hello from 329
Completing process 329
Child process is over, we can complete parent as well. Child process exit code 0
Completing process 328
```
