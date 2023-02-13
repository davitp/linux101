---
layout: default
title: Reading the file
nav_order: 3
parent: Samples
---

# Reading file contents
{: .no_toc }

This sample demonstrates how to read a text file using **read()** function.

```c
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

/**
 * @brief main The program entry point
 * @param argc The number of arguments
 * @param argv The command line arguments
 * @return Returns exit code
 */
int main(int argc, char* argv[]){

    // if not enough parameters supplied
    if(argc < 2){
        printf("File name was not given by arguments\n");
        exit(1);
    }

    // we expect the input file name to be provided as the 1st command-line argument 
    const char* filename = argv[1];

    // open file in read-only mode, expecting that file already exists
    int file = open(filename, O_RDONLY);

    // something went wrong (file does not exist, user does not have read access to the file, etc.)
    // function strerror(errno) gets the standard error corresponding to the given error code 
    if(file == -1){
        printf("Something went wrong while opening the file. Error %s\n", strerror(errno));
        exit(errno);
    }

    // allocate a buffer of a given size + 1 byte for appending termination character \0
    char* buffer = malloc(BUFFER_SIZE + 1);

    // the variable will be used to count number of bytes we could read from the file overall
    long overallBytes = 0;

    // the variable will be used to capture number of read bytes in every read iteration
    long readBytes = 0;

    // repeat until we want to stop
    while(1 == 1){

        // try reading the next BUFFER_SIZE bytes from the file into a buffer
        readBytes = read(file, buffer, BUFFER_SIZE);

        // we may get some errors while reading the file for various reasons, so the case needs to be handled
        if(readBytes == -1){
            printf("Something went wrong while reading the file. Error %s\n", strerror(errno));
            exit(errno);
        }

        // if we receive 0 bytes from the read operation, then there is no more data to read
        if(readBytes == 0){
            break;
        }

        // increase number of overall bytes
        overallBytes += readBytes;

        // (only for printing purposes) 
        // in order to print the read data to the console, we need to terminate the next read chunk with \0 symbol  
        buffer[readBytes] = '\0';

        // print next chunk of read data
        printf("%s", buffer);
    }

    // close the file as we don't need it anymore
    close(file);

    // release allocated memory
    free(buffer);

    // report success
    printf("Completed reading file. Overall bytes: %ld\n", overallBytes);

    return 0;
}
```

The file can be compiled with the following command:
```sh
gcc read.c -o read
```

Running the resulting application **./read some-file.txt** will print the contents of the given file to the console.