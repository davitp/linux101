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

    // use 1st argument as a filename
    const char* filename = argv[1];

    // open file for reading only
    int file = open(filename, O_RDONLY);

    // something went wrong
    if(file == -1){
        printf("Something went wrong while opening the file. Error %s\n", strerror(errno));
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
        readBytes = read(file, buffer, BUFFER_SIZE);

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

        // add termination character to print
        buffer[readBytes] = '\0';

        // print next read portion
        printf("%s", buffer);
    }

    // report success
    printf("Completed reading file. Overall bytes: %ld\n", overallBytes);

    return 0;
}
