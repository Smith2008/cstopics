---
layout: default
title: C/C++ with Linux
permalink: /programming/c-c++/c_c++_in_linux
---

<h1 style="text-align: center;">C/C++ in Linux</h1>

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

# Makefiles basics

A *Makefile* allows you to compile, execute, and perform other tasks from simple commands. Create a new file named *Makefile* (this must be the name, pay attention to capital letters), and add this content:

``` sh
rule1:
    echo 'Hello from rule 1'

rule2:
    echo 'Hello from rule 2'
```

The rules have bash commands.

In order to execute the *Makefile*, you only need to enter the command *make [rule]*, and it will show you the lines to execute, and the results. As below:

``` sh
$ make rule1
echo 'Hello from rule 1'
Hello from rule 1
$ make rule2
echo 'Hello from rule 2'
Hello from rule 2
```

If you do not specify the rule, it will execute the first rule as default.

``` sh
$ make
echo 'Hello from rule 1'
Hello from rule 1
```

Replace the *Makefile* content with the following:

``` sh
compile:
    gcc -o main main.c
rule2:
    ./main
```

Using this *Makefile*, you can compile and execute your *hello world* example:

``` sh
$ make
gcc -o main main.c
$ make run
./main
Hello everyone
```

# gcc/g++ Advanced

# Makefiles Advanced

Example of makefile with one rule per file to be generated:

``` sh
all: main1 main2 n_processes pi

main1: main1.cpp
	g++ -o main1 main1.cpp

main2: main2.cpp
	g++ -o main2 main2.cpp

n_processes: n_processes.cpp
	g++ -o n_processes n_processes.cpp

pi: pi.cpp
	g++ -o pi pi.cpp

.PHONY: clean
clean:
	rm -rf main1 main2

# rule: dependents
# 	command
```
