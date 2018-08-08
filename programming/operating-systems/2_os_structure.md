---
layout: default
title: Interruptions and System Calls
permalink: /programming/operating-systems/2_os_structure
---

<h1 style="text-align: center;">Operating Systems Structure</h1>

# Services

<div style="text-align:center">
  <img style="width:80%;" src ="/cstopics/assets/img/programming/os/2_os_structure.png" />
</div>

# User Interface

## Shell

Communication interface between user requests and OS kernel, through commands.

**Bash** is the command interpreter used by Unix, Linux, macOS and newest versions of Windows. Is a GNU project result, written by Brian Fox. It first version was launched in 1989, and includes basic command to navigate in and handle the files system.

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/2_terminal_ubuntu.png" />
  <div style="font-size:70%">Console in Ubuntu.</div>
</div>

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/2_terminal_macos.png" />
  <div style="font-size:70%">Console in macOS.</div>
</div>

The following image presents the basic data flow when using **bash**:

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/2_bash_dataflow.png" />
</div>

## Environment Variables

Environment variables are values stored by the operating system, that can be used, defined or deleted by the bash. In Ubuntu, there are several predefined environment variables, some of there are:

* *HOME*: Home directory of the current user.
* *HOSTNAME*: Machine name.
* *USER*: Name of the current user.

You can check the value of an environment variable with the *echo* command:

```sh
$ echo $HOME
/user/camilo
```/programming/c-c++/c_c++_in_linux

In addition, you can set variables as below:

``` sh
$ export VAR1='SANTOTO'
$ VAR2='SANTOTO'
$ VAR3=SANTOTO
$ echo $VAR1
SANTOTO
$ echo $VAR2
SANTOTO
$ echo $VAR3
SANTOTO
```

And you can also delete variables:

``` sh
$ unset VAR1
```

In order to check all the existing environment variables, you can use the *env* command.

## Prompt

The prompt is the line that indicates that the user can write commands in the console, it's completely customizable. The default prompt format is:

```
userName@machineName:currentDirectory$
```

This format is stored in the *PS1* enviroment variable, and you can check it:

``` sh
$ echo $PS1
\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\03 ...
```

You can set it as any string, or use different identifiers for the user (\u), the working directory (\w), and others.

There is a bash script that is executed when the terminal starts, and includes the definitions of a number of environment variables, such as *PS1*. This file uses to be in the home directory, and it is named *.bashrc* in ubuntu and *.bash_profile* in macOs.

<div style="background-color:rgb(255, 99, 71); color:rgb(255,255,255); padding: 30px;">
<i>'.bashrc'</i> is a system protected and hidden file (files starting with dot are hidden files in Linux). It just can be modified using <i>'sudo'</i>. Modifying this file in a wrong way could damage your Linux terminal.
</div>

<br>

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/2_bashrc.png" />
</div>

## GUI

<div style="text-align:center">
  <img style="width: 100%;" src ="/cstopics/assets/img/programming/os/2_first_gui.png" />
  <div style="font-size:70%">First GUI, 1973, Xerox Alto computer.</div>
</div>

# Systems Calls

System calls are the interface to the available services in the OS.

They are usually predefined C/C++ functions, but there are implementations for other compiled and interpreted languages.

Some system calls examples could be:

* Display messages on the screen.
* Read and write I/O devices.
* Opening/Closing files.
* Reading/Writing files.
* Finishing processes execution.

## APIs

The calls for different systems are standardized by APIs, that are basically functions, and its parameters and return values. API functions perform the system calls instead of the programmers.

Principal APIs are:

* Windows API: https://msdn.microsoft.com/en-us/library/windows/desktop/dn933214(v=vs.85).aspx
* POSIX-API (Linux and maxOS): http://pubs.opengroup.org/onlinepubs/9699919799/
* JAVA API: https://docs.oracle.com/javase/7/docs/api/

## Example

Program that try opening a file from the files system. What must it do?

* Ask to user for the file name. (Showing message on screen).
* Read information provided through the keyboard.
* Try opening the file.
* If file exists:
  * Show successful message.
  * Close file.
  * Finish process normally.
* If file does not exist.
  * Show error message.
  * Finish process with failure.

Needed API functions:

* Show message on screen. *fprint()*
* Read keyboard info: *fscan()*
* Open files: *fopen()*
* Close files: *fclose()*
* Finish process *exit()*

You can check the API functions documentation in Linux with the *man* command (press *Q* to exit).

``` sh
$ man scanf
```

Coding the example in (in C):

{% include code/programming/os/2_calls_example.md %}

## How it works?

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/2_calls_working.png" />
</div>

Advantages of performing system calls through APIs:

* Portability
* User friendly

## Structure of API functions

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/2_api_function.png" />
</div>

# Types of Calls

## 1. Process Control

Control the program execution:

* Creation / Elimination.
* Start / Stop (normal or forzed).
* CPU time assign.
* Waiting for events.
* Assign / Release of memory.
* Assign / Get parameters.

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/2_calls_control.png" />
</div>

Mono-task systems:

<div style="text-align:center">
  <img style="width: 70%;" src ="/cstopics/assets/img/programming/os/2_monotask.png" />
</div>

Multi-task systems:

<div style="text-align:center">
  <img style="width: 70%;" src ="/cstopics/assets/img/programming/os/2_multitask.png" />
</div>

## 2. File Handling

They are the most used system calls used by the user.

* Creation / Elimination
* Opening / Closing
* Writing / Reading
* Attribute edition

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/2_calls_files.png" />
</div>

## 3. Devices Management

Handling of the hardware resources (Similar to file management.).

* Opening / Closing
* Reading / Writing
* Request / Return

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/2_calls_devices.png" />
</div>

## 4. Information Handling

* User - OS information transfer.
* System information.
* Time profiles.
* Debug.
* General information about processes.

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/2_calls_info.png" />
</div>

## 5. Communication

Used to transfer information between processes.

*Through messages:* Direct communication between processes or indirect, through message mailbox.

* Open connection
* hostID, processID
* Read / Write cycles
* Close connection

*Through shared memory:*

* Processes &rarr; Calls &rarr; Access to memory data from other processes.
* Processes with a section of shared memory &rarr; Access Synchronization.

## 6. Security

* Resources access control.
* Files and devices permissions assignment.

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/2_calls_security.png" />
</div>

# OS Structure

## Simple Structure

* MS-DOS did not have a 'gap' between HW and SW through interfaces.
* It could involve security problems and user programs errors.
* The old hardware did not have protection options.

<div style="text-align:center">
  <img style="width: 40%;" src ="/cstopics/assets/img/programming/os/2_msdos.png" />
</div>

* UNIX separated the kernel and system programs.
* The Kernel provides functionality for each HW component.

<div style="text-align:center">
  <img style="width: 55%;" src ="/cstopics/assets/img/programming/os/2_kernel.png" />
</div>

The Kernel has a plenty of functionalities at the same level. *Monolithic Structure*.

## Microkernels

* They remove not essential elements from kernel, and include them as user level programs.
* *Main function:* provide communication (through messages) between programs and services at the user space.
* *Example:* Mach microkernel system, developed in Carnegie Mellon University in the mid-80s.

## Modules

* **Core kernel:** microkernel function.
* Dynamic modules thar offer services to the core.
* Link between kernel and modules &rarr; on boottime or runtime.

# Designing an OS

To consider from technical specs side:

* HW specs (architecture, memory, etc.).
* System type:
    * Multitask / multiprogram
    * Monouser / multiuser
    * Distributed
    * Real time
    * General purpose

<h1 style="color:Tomato;">Homework 1</h1>

Write a *C/C++* program that reads a text file (*hw1.txt*), and generates a new file (*HW1.txt*) with the same content but is capital letters.

Create a new folder in your repository, and upload the files below:

* Pseudocode with the system calls.
* *hw1.c* or *hw1.cpp* with the *c/c++* code.
* An *hw1.txt* sample file.
* A *Makefile* with the rules *compile* and *run*. (Refer to the [C/C++ in Linux](/cstopics/programming/c-c++/c_c++_in_linux) guide)

When the repository is ready, download it as a *.zip* file and upload it to the appropriate link in moodle.
