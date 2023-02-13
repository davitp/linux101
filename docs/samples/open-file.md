---
layout: default
title: Opening a file
nav_order: 2
parent: Samples
---

# Opening a file
{: .no_toc }

This sample demonstrates usage of functions **open** and **close**. 

```c
#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <unistd.h>
 
int main() 
{      
    // open the file with a given relative path "foo.txt" 
    // the file should be open only for reading (O_RDONLY) and should be created if missing (O_CREAT)
    // when created, the file should have following permissions: read and write by the owner (S_IRUSR and S_IWUSR) and read only for the group (S_IRGRP) 
    int fd = open("foo.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);  

    // printing the number of the descriptor
    printf("Returned Value = %d\n", fd); 

    // validating the result of the open operation      
    if (fd == -1) 
    { 
        // print which type of error have in a code (stored in the global errno variable)
        printf("Error Number %d\n", errno);  
          
        // print error details 
        perror("main");       
        
        // exit program as cannot continue
        return errno;           
    } 

    printf("Successfully opened a file. Doing some reading...\n");

    // close file
    int closed = close(fd);

    // if closed
    if(closed == -1)
    {
        printf("Error while closing file %d\n", errno);
        
        return errno; 
    }
    
    printf("File closed successfully \n");
    return 0; 
} 
```

The file can be compiled with the following command:
```sh
gcc open.c -o open
```

Running the resulting application **./open** should create a file named **foo.txt** and print the following result:
```sh
Returned Value = 3
Successfully opened a file. Doing some reading...
File closed successfully
```