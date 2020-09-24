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
    // save stdout to write if needed
    int saveStdout = dup(1);

    // could not save stdout
    if(saveStdout == -1){
        std::cerr << "Could not duplicate stdout" << std::endl;
        exit(errno);
    }

    // close stdout, now 1 is free
    int closed = close(1);

    // stdout not closed
    if(closed == -1){
        std::cerr << "Cloud not close stdout" << std::endl;
        exit(errno);
    }

    // open a stdout log file to redirect
    int file = open("stdout.log", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);

    // something went wrong
    if(file == -1){
        std::cerr << "Cloud not open/create a file for writing stdout stream in" << std::endl;
        exit(errno);
    }

    // write text (will appear in file and not in console)
    std::cout << "Writing some text" << std::endl;

    // close file
    close(file);

    return 0;
}
