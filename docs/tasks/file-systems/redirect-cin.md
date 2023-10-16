---
layout: default
title: 'FS-5: Redirect standard input'
parent: File Systems
grand_parent: Tasks
nav_order: 5
---

# FS-5: Redirect standard input

### Description
By default, program gets standard input waiting for the keyboard input. Your task is to make any program to read input from the file instead of waiting for the keyboard input without changing usages of std::cin or scanf.

### Requirements

- Write a C++ program named "redirect-cin" that accepts a path to a file as a command-line argument.
- Implement the function `initialize(int argc, char** argv)` to start reading from the given file with a proper error handling.
- Implement a simple logic for `main()` function to read string from the standard input (std::cin) and print the reversed string to the cosnsole (std::out).
- If there is an error with given file, the program should terminate with the proper error code.

The program's main source file should look like:
```cpp
void initialize(int argc, char** argv)
{
  // put your implementation here 
  // ............................
}

int main(int argc, char** argv)
{
  // initialize the program based on the requirements
  initialize(argc, argv);

  // read the string 
  std::string input;
  std::cin >> input;
  
  // logic to get the reversed string
  std::string reversed;
  
  // put your reversing logic here
  // .............................

  // print to the console
  std::cout << s;

  return 0
}
```

Hint: you can use one of `dup()` functions.


### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./redirect-cin input-file
```

And, assuming input file contains the text "123456789", the program should output the following:
```sh
987654321
```


The final solution should contain a **Makefile** for the multi-stage build. The Makefile should also contain targets **all** and **clean**. It's recommended to have compiler and compiler flags to be declared as a Makefile variables. Alternatively, **cmake** could also be used instead of make. 