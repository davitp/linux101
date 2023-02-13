---
layout: default
title: Redirect the output
nav_order: 5
parent: Samples
---

# Redirect standard output and error
{: .no_toc }

This sample demonstrates how to redirect standard output and standard error into a file (using **dup/dup2**) while keeping possibility to write to the console when needed.

```c
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
 * @brief main The program entry point
 * @return Returns exit code
 */
int main()
{
    // copy the file descriptor 1 (standard output) to a new descriptor for the future use
    int newStdout = dup(1); 

    // could not duplicate the file descriptor 1
    if(newStdout == -1){
        std::cerr << "Could not duplicate stdout" << std::endl;
        exit(errno);
    }

    // close file descriptor of stdout
    int closed = close(1);

    // stdout not closed
    if(closed == -1){
        std::cerr << "Cloud not close stdout" << std::endl;
        exit(errno);
    }

    // open/create a new file where standard output and standard error will be redirected to 
    int file = open("output.log", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

    // something went wrong while opening the file
    if(file == -1){
        std::cerr << "Cloud not open/create a file for redirecting standard output in" << std::endl;
        exit(errno);
    }
    
    // duplicate the standard output into descriptor 2
    // this will result descriptor 1 and 2 to point to the same file
    int cerrDescriptor = dup2(1, 2);

    // make sure we could successfully duplicate the descriptor
    if(cerrDescriptor == -1){
        std::cerr << "Cloud not redirect standard error into standard output stream" << std::endl;
        exit(errno);
    }

    // perform cout to write into standard output and cerr to write into the standard error
    // as we redirected both 1 and 2 descriptors into the file output.log, the following text
    // will not appear on the console screen, but will be written into the file
    std::cout << "Writing some text" << std::endl;
    std::cerr << "Other error text" << std::endl;

    // finally print text on the console using plain write operation into the copied stdout stream 
    write(newStdout, "Hello\n", 6); 

    // close file
    close(file);

    return 0;
}
```

The file can be compiled with the following command:
```sh
g++ redirect.cpp -o redirect
```

Running the resulting application **./redirect** is supposed to print "Hello" on the console screen and create a file output.log containing cout and cerr text.