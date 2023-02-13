---
layout: default
title: Using Makefile
nav_order: 1
parent: Samples
---

# Compiling multiple files using Makefile
{: .no_toc }

In this sample we will compile a program having two modules with Makefile. 

The program will contain two modules:
- main.cpp - the main logic of the application
- message.cpp - a module that can simply print messages

Let's assume the main.cpp contains following logic:
```c
#include "message.h"

int main(){

    // the function printMyMessage is declared in the message.h header file
    // but the implementation is in the other module (message.cpp)
    printMyMessage("Hello");

    return 0;
}
```

The file message.h contains only declaration of the used function:
```c
#ifndef MESSAGE_H
#define MESSAGE_H

// the declaration of the printing function
// no implementation in the header file
void printMyMessage(const char* message);

#endif
```

Then the module message.cpp should implement the mentioned function as follows:
```c
#include <cstdio>

// the implementation of the printMyMessage function 
void printMyMessage(const char* message){
	printf("New Message: %s \n", message);
}
```

We can manually compile the modules one by one as follows:
```
# compile main.cpp module to the object file main.o
g++ -c main.cpp -o main.o

# compile message.cpp module to the object file message.o
g++ -c message.cpp -o message.o
```

Then, having two modules main.o and message.o we can build final executable by linking those together:
```
g++ main.o message.o -o program
``` 

In order to automate the process we could also write a Makefile as follows:
```
all: program

program: main.o message.o
	g++ main.o message.o -o program

main.o: main.cpp message.h
	g++ -c main.cpp -o main.o

message.o: message.cpp
	g++ -c message.cpp -o message.o

clean:
	rm *.o program
```

Now, invoking **make** command will create all the necessary files up to the program.

You may also want to clean the build output with special **clean** target as follows:
```
make clean
``` 