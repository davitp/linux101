#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <unistd.h>
 
int main() 
{      
    // open file for reading only.  
    int fd = open("foo.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);  
      
    // print file descriptor info
    printf("Returned Value = %d\n", fd); 
      
    if (fd == -1) 
    { 
        // print which type of error have in a code 
        printf("Error Number %d\n", errno);  
          
        // print error details 
        perror("main");       
        
        // exit program as cannot continue
        return errno;           
    } 

    printf("Successfuly opened a file. Reading and Writing...\n");

    // close file
    int closed = close(fd);

    // if closed
    if(closed == -1)
    {
        printf("Error while closing file %d\n", errno);
        
        return errno; 
    }
    
    printf("File closed successfuly\n");
    return 0; 
} 
