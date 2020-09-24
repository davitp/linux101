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
    if(argc < 3){
        printf("Please input source and desitnation files\n");
        exit(1);
    }

    // use 1st argument as a filename
    const char* source = argv[1];

    // open file for reading only
    int sourceFd = open(source, O_RDONLY);

    // something went wrong
    if(sourceFd == -1){
        printf("Something went wrong while opening the source file. Error %s\n", strerror(errno));
        exit(errno);
    }

    // use 1st argument as a filename
    const char* destination = argv[2];

    // open file for writing only, create if not exist and truncate once opened
    int destinationFd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

    // something went wrong
    if(destinationFd == -1){
        printf("Something went wrong while opening the destination file. Error %s\n", strerror(errno));
        exit(errno);
    }

    // a buffer to read data
    char* buffer = malloc(BUFFER_SIZE + 1);

    // count overall bytes printed
    long overallBytes = 0;

    // number of bytes in last read
    long readBytes = 0;

    // repeat until we want to stop
    while(1 == 1){

        // try read buffer size
        readBytes = read(sourceFd, buffer, BUFFER_SIZE);

        // error while reading
        if(readBytes == -1){
            printf("Something went wrong while reading the file. Error %s\n", strerror(errno));
            exit(errno);
        }

        // stop if no more bytes to read
        if(readBytes == 0){
            break;
        }

        // increase number of overall bytes
        overallBytes += readBytes;

        // write to destination file
        long writeBytes = write(destinationFd, buffer, (size_t)readBytes);

        // check if error happened during writing
        if(writeBytes == -1){
            printf("Something went wrong while writing to destination file. Error %s\n", strerror(errno));
            exit(errno);
        }
    }

    // close files
    close(sourceFd);
    close(destinationFd);

    // release memory
    free(buffer);

    // report success
    printf("Completed copying file. Overall bytes copied: %ld\n", overallBytes);

    return 0;
}
