---
layout: default
title: Copy the file
nav_order: 4
parent: Samples
---

# Copy the source file 
{: .no_toc }

This sample demonstrates how to implement a basic copy program using **read** and **write** functions.

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

    // we expect the user to provide at least 2 arguments: source and destination files
    // handling, if less arguments are passed
    if(argc < 3){
        printf("Please provide source and destination files\n");
        exit(1);
    }

    // use 1st argument as a source file path
    const char* source = argv[1];

    // open file for reading only, as we are not going to modify it
    int sourceFd = open(source, O_RDONLY);

    // make sure that the source file could be successfully opened in the read-only mode
    if(sourceFd == -1){
        printf("Something went wrong while opening the source file. Error %s\n", strerror(errno));
        exit(errno);
    }

    // use 2nd argument as a destination file path
    const char* destination = argv[2];

    // open file for writing only, create if not exist (O_CREAT) and truncate (O_TRUNC) once opened
    int destinationFd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

    // make sure we could open/create a destination file in write-only mode
    if(destinationFd == -1){
        printf("Something went wrong while opening the destination file. Error %s\n", strerror(errno));
        exit(errno);
    }

    // allocate a buffer for storing and writing next read chunk of the data
    char* buffer = malloc(BUFFER_SIZE);

    // count overall bytes copied
    long overallBytes = 0;

    // number of bytes in last read
    long readBytes = 0;

    // repeat until we want to stop
    while(1 == 1){

        // reading BUFFER_SIZE bytes from the file into the buffer
        readBytes = read(sourceFd, buffer, BUFFER_SIZE);

        // make sure the read operation completed with success 
        if(readBytes == -1){
            printf("Something went wrong while reading the file. Error %s\n", strerror(errno));
            exit(errno);
        }

        // stop reading if no more bytes to read
        if(readBytes == 0){
            break;
        }

        // increase number of overall bytes
        overallBytes += readBytes;

        // writing the last read chunk (readBytes bytes) from the buffer to the destination file
        long writeBytes = write(destinationFd, buffer, (size_t)readBytes);

        // check if error happened during writing
        if(writeBytes == -1){
            printf("Something went wrong while writing to destination file. Error %s\n", strerror(errno));
            exit(errno);
        }
    }

    // close files as no longer needed
    close(sourceFd);
    close(destinationFd);

    // release memory
    free(buffer);

    // report success
    printf("Completed copying file. Overall bytes copied: %ld\n", overallBytes);

    return 0;
}
```

The file can be compiled with the following command:
```sh
gcc copy.c -o copy
```

Running the resulting application **./copy source-file.txt new-file.txt** make a duplicate of source-file.txt with name new-file.txt.