---
layout: default
title: C++ with Linux
permalink: /programming/c-c++/1_basic_structure
---

<h1 style="text-align: center;">Basic C++ Program Structure</h1>

When you compile and execute a C++ application, the operating system finds and calls the function ***main()***, so you must **always** define it, and only **once**. As follows:

``` c++
// main.cpp
#include <iostream>

int main(int argc, char** argv){
  std::cout << "Hello World" << std::endl;
  return 0;
}
```

Notice that *main* function must have two parameters: *argc* is the number of arguments that OS passes to the program, and *argv* are those arguments (as we are going to learn, a double pointer to *char* can be seen as an array of *strings*).

### Bad Practices

Do not return anything:

``` c++
#include <iostream>

int main(int argc, char** argv){
  // Your Code
}
```

Return *void* type:

``` c++
#include <iostream>

void main(int argc, char** argv){
  // Your Code
}
```

Do not receive parameters:

``` c++
#include <iostream>

int main(){
  // Your Code
  return 0;
}
```

Using namespace *std*. When you add this namespace to your context, you are adding thousands of names, not only *cout* and *endl*.

``` c++
#include <iostream>

using namespace std;

int main(int argc, char** argv){
  cout << "Hello World" << endl;
  return 0;
}
```

And all their terrible combinations:

``` c++
#include <iostream>

using namespace std;

void main(){
  cout << "Hello World" << endl;
}
```

# Compiling in Linux

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
Hello World
```

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


That is all!. for now...
