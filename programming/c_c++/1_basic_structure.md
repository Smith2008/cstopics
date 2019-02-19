---
layout: default
title: C++ with Linux
permalink: /programming/c-c++/1_basic_structure
---

<h1 style="text-align: center;">Basic C++ Program Structure</h1>

When you compile and execute a C++ application, the operating system finds and calls the function ***main()***, so you must **always** define it, and only **once**. As follows:

``` c++
#include <iostream>

int main(int argc, char** argv){
  std::cout << "Hello World" << std::endl;
  return 0;
}
```

Notice that *main* function must have two parameters: *argc* is the number of arguments that OS passes to the program, and *argv* are those arguments (as we are going to learn, a double pointer to *char* can be seen as an array of *strings*).
