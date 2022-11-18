---
layout: default
title: Compilation
parent: Guides
---

# Compilation and build process
{: .no_toc }

The set of samples to showcase different aspects of the compilation process in the Linux environment using various tools such as gcc, make, cmake, etc. 

### Single file compilation
{: .no_toc }

Consider **main.cpp** as a source file containing the whole logic of the application:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```
In order to compile the source code into an executable file execute following line in the source directory:

```sh
g++ main.cpp -o app
```
where parameter **-o app** defines the name of the output file (a.out by default).

If command completes successfully, the source directory will contain a file called **app** that is ready to execute as follows:

```sh
./app
```