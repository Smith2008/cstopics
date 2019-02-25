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

That is all!. for now...
