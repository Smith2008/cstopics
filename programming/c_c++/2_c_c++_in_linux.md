---
layout: default
title: C++ with Linux
permalink: /programming/c-c++/2_c++_in_linux
---

<h1 style="text-align: center;">C++ in Linux</h1>

When you are used to program in Windows, you almost always open a program (called IDE), that allows you to code, press a button, and magically your code are compiled and running. The goal of this tutorial is to teach the process that occurs when you press that button, for that reason, we are not going to use IDEs. You can edit the text files the any text editor (nano, sublime, atom, gedit, etc.).

# gcc / g++ basics

Go to a empty folder (or create it), create a new file named *main.c* (it is not important the file name, but the extension is), and add the following content (a typical hello world exercise written in C).

``` c
#include <stdio.h>

int main(int argc, char** argv){
  printf("Hello everyone\n");
  return 0;
}
```

Save it, and come back to the terminal.

If you have not installed the build tools in Ubuntu, execute the commands below (with internet connection).

``` sh
$ sudo apt-get update
$ sudo apt-get install build-essential
```

This package includes two compilers: *gcc* for *C* and *g++* for *C++*. To compile our example, we must execute the following:

``` sh
$ gcc -o main main.cpp
```

The *-o* flag indicates the output (binary, executable, etc.) file, that means, the compiled program. To execute it, enter:

``` sh
$ ./main
Hello everyone
```

That is all!. for now...
