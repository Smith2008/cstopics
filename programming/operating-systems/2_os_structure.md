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
```

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

## Process Control
