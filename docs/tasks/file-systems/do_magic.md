---
layout: default
title: 'FS-5: Magic "cin"'
parent: File Systems
grand_parent: Tasks
nav_order: 5
---

# FS-5: Completely remove a file

### Requirements
In this assignment, you will create a C++ program that defines a function called `do_magic()`. The purpose of this function is to read a string from a regular file named "new_pts" and display it on the console. The main part of the program is already provided for you in the `main()` function, and you are responsible only for implementing the `do_magic()` function.
hint: Use dup/dup2/dup3
 ```cpp
   void do_magic();

   int main()
   {
       do_magic();
       std::string s;
       std::cin >> s;
       std::cout << s;
   }
 ```

- Write a C++ program that defines a function `do_magic()` responsible for manipulating the `stdin`.
- Ensure proper error handling to check if the "new_pts" file exists and if the file can be successfully opened.

### Expected result

The resulting application should be able to build and execute from command line as follows:

```sh
make
./do_magic
```
