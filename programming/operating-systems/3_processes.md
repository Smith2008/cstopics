---
layout: default
title: Processes
permalink: /programming/operating-systems/3_processes
---

<h1 style="text-align: center;">Processes</h1>

*Processes* or *jobs* are code running on the CPU.

# Process execution

A process is not the same as a program:
* A program (or executable file) is a *passive* entity, that is usually stored on the hard disk.
* A process is a *active* entity, that is on the main memory and is running on the CPU.
* When you execute a program (double click on desktop or command in terminal), it is created a copy of it on the main memory.

But when a program is executed, not only its code is copied on memory, it is also created a set of sections, as below:

<div style="text-align:center">
  <img style="width: 40%;" src ="/cstopics/assets/img/programming/os/3_process_in_memory.png" />
  <div style="font-size:70%">Process in memory. [Silberschatz12]</div>
</div>

## Sections

The sections are:

* Header (no shown), that contains:
    * Process ID
    * Program counter
    * Processor register snapshot
    * Others OS information
* Text: the program code, copied from some storage device.
* Data: global variables.
* Stack: local variables in functions calls.
* Heap: Dynamically allocated data.

It can exist more than one processes associated to the same program, but they are completely independent execution sequences. Although them text sections are the same, the header, data, stack and heap will probably be different.

## Process state

From the moment a process is launched, it changed its state continually, the basic states are:

* **New**. The process is being created.
* **Running**. Instructions are being executed.
* **Waiting**. The process is waiting for some event to occur (such as an I/O completion or reception of a signal).
* **Ready**. The process is waiting to be assigned to a processor.
* **Terminated**. The process has finished execution.

It important to realize that only one process can be being executed by each core. The state diagram of the changing of state is:

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/3_state_diagram.png" />
  <div style="font-size:70%">Diagram of process state. [Silberschatz12]</div>
</div>

## Header section (Process Control Block PCB)

Most of the information allocated in the header section is part of the Process Control Block (*PCB*). It is used by the OS to store specific information about each process.

* **Process state**.
* **Program Counter**. Memory address of the next instruction to be executed.
* **CPU registers snapshot**. Copy of the accumulator, pointers, general registers, and all the processor register when the process changed to the *waiting* or *ready* states.
* **CPU-scheduling information**. Priority, pointers to scheduling queues, and any other scheduling parameters.
* **Memory-management information**. Page or segment tables, memory limits, and others.
* **Accounting information**. CPU and memory used, cores, etc.
* **I/O status information**. I/O devices or files used.

<div style="text-align:center">
  <img style="width: 35%;" src ="/cstopics/assets/img/programming/os/3_pcb.png" />
  <div style="font-size:70%">Process control block (PCB). [Silberschatz12]</div>
</div>

Below is exposed the process of switching between processes and context:

<div style="text-align:center">
  <img style="width: 80;" src ="/cstopics/assets/img/programming/os/3_switch_process.png" />
  <div style="font-size:70%">Process of switching between processes. [Silberschatz12]</div>
</div>

## Process Scheduling

Scheduling allows the OS to execute multiple process, in order to emulate concurrence, when the processor is actually running only one of these processes.

## Scheduling Queues

Queues are usually implemented as ***linked lists***, and contain PCBs.

When a process is executed, it is put into the ***job queue***, waiting for its passing to the ***ready queue***.

Each process in the ***ready queue*** is executed for a while, and quits. It finish then it is interrupted by the OS or when is waiting for a particular event, for example, the completion of a I/O request. In the last case, the process passes from the ***ready queue*** to the ***device queue*** of the specific I/O device, that implies that each device has a ***device queue***.

Bellow the queueing-diagram representation of process scheduling:

<div style="text-align:center">
  <img style="width: 80;" src ="/cstopics/assets/img/programming/os/3_queuering.png" />
  <div style="font-size:70%">Queueing-diagram representation of process scheduling. [Silberschatz12]</div>
</div>

## Schedulers

* **Long-term scheduler**: Choose the processes that must be on main memory, and move them from the ***job queue*** to the ***ready queue***, and vice versa.

* **Short-term scheduler**: Choose the process that must start executing on CPU when the current process finishes, its assigned time, exits, or enters to a ***device queue***. If this choosing process spend, for example, *10ms*, and the process last 100ms on CPU, that means that means that *10/(100 + 10) = 9* percent of the CPU is being used
(wasted) simply for scheduling the work.

## Context Switch

When OS changes the process the CPU is executing, its necessary to store all PCB information, this process is called *Context Switch*. The time that this process spend depends on the amount of registers and the hardware capabilities (speed and instruction set).

# Operations on Processes

Operating Systems, as UNIX, Linux and Windows, provide mechanisms to manage processes. In this case, we are going to discuss the Linux (and UNIX) ones.

## Process Creation

Processes can create new processes, this fact implies that it is created a tree of processes. In Windows and Linux, processes are identified by a unique Process Identifier (PID), that is a integer number.

Linux uses a unique process tree, and its root is the *init* process with the PID=1:

<div style="text-align:center">
  <img style="width: 80;" src ="/cstopics/assets/img/programming/os/3_process_tree.png" />
  <div style="font-size:70%">Linux process tree. [Silberschatz12]</div>
</div>

The processes in the image are:

* **init**: The first process that Linux launch, always has the PID=1.
* **kthreadd**: Created by *init*. It function is to launch other kernel processes.
* **sshd**: Manages users connected via *ssh*.
* **login**: Manages users connected locally.

You can list all the processes with the *ps* command:

``` sh
$ ps -el
```

In addition, you can filter a specific process by name or pid, using the *grep* command:

``` sh
$ ps -el | grep kthreadd
1 S     0     2     0  0  80   0 -     0 -      ?        00:00:00 kthreadd
$ ps -el | grep 1
...
0 S  1000 29089 24252  0  80   0 -  7607 wait   pts/2    00:00:00 bash
...
```

When a child process is launched, the parent process can specify some parameters for its execution, for example, the *command line parameters* when process is executed from a terminal.

When a process creates a new process, two possibilities for execution exist:
1. The parent continues to execute concurrently with its children.
2. The parent waits until some or all of its children have terminated.

There are also two address-space possibilities for the new process:
1. The child process is a duplicate of the parent process (it has the same
program and data as the parent).
2. The child process has a new program loaded into it

### Process management in Bash

Without arguments, the *ps* command shows the processes launched by the current terminal. Below, some command to manage processes from terminal:

``` sh
$ ps
PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29560 pts/2    00:00:00 ps
$ gedit & # gedit is a text editor, the & character runs the process in background  
$ ps
  PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29660 pts/2    00:00:00 gedit
29667 pts/2    00:00:00 ps
$ nano # starts nano
# When nano is executing, press Ctrl+Z to stop the process.
$ ps
PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29660 pts/2    00:00:00 gedit
29705 pts/2    00:00:00 nano
29706 pts/2    00:00:00 ps
$ kill 29660 # Kills the gedit process, the PID could differ in your PC
$ ps
PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29705 pts/2    00:00:00 nano
29761 pts/2    00:00:00 ps
[1]-  Terminated              gedit
$ top # Execute top process
# When top is executing, press Ctrl+Z to stop the process.
$ fg # Open the last process that you stoped
# Press Ctrl+C to finish the current top process.
$ ps
  PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29705 pts/2    00:00:00 nano
29794 pts/2    00:00:00 ps
$ kill 29705 # Kills the stopped nano process
$ fg
$ ps
  PID TTY          TIME CMD
29528 pts/2    00:00:00 bash
29799 pts/2    00:00:00 ps
$ gedit # Execute gedit again, but lock the terminal
# Press Ctrl+Z to stop the process
$ bg # Continue it but in background (terminal is free again)
```

### Process management in C

Process creation schema with POSIX:

<div style="text-align:center">
  <img style="width: 90;" src ="/cstopics/assets/img/programming/os/3_process_unix.png" />
  <div style="font-size:70%">Linux process tree. [Silberschatz12]</div>
</div>

Coding it in C:

``` c
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Parent process
int main()
{
    // Variable to store the child pid
    pid_t pid;

    // Parent process creates child process.
    pid = fork();
    // From here, the code is execuded by two processes.
    printf("Parent process creates child process. %i \n", pid);

    if(pid < 0 ){
        // pid is less than 0 if child process could not be created
        fprintf(stderr, "Fork failed");
        exit(1);
    }
    else if(pid == 0){
        // pid is 0 for the child
        printf("Executing child process... \n");
        // execlp() creates new process in memory, and delete the original process image
        execlp("/bin/ls", "ls", NULL);
        // the child does not come back to this code
    }
    else{
        // The parent can execute other code, or just wait for the child finishing
        wait(NULL); // Parent process goes to 'fork a child' queue until one of its children finish
        // Parent process return to 'ready' queue
        printf("Child process finished, parent process continues \n");
        exit(0);
    }
}
```

## Process Termination

In C a process finish when the last line of code is executed. With POSIX, you can finish the process with the *exit()* function, sending the error code (as with the return at the end of the *main*). The process can also finish because of signals from the OS or from its parent.

A parent may terminate the execution of one of its children for a variety of reasons, such as these:
* The child has exceeded its usage of some of the resources that it has been allocated. (To determine whether this has occurred, the parent must have a mechanism to inspect the state of its children.)
* The task assigned to the child is no longer required.
* The parent is exiting, and the operating system does not allow a child to continue if its parent terminates (cascading termination).

When you finish a child process, you can send the status, like this:

``` code
/* exit with status 1 */
exit(1);
```

If you want to check the status of the finished child in the parent, you can do the following:

``` c
pid t pid;
int status;
pid = wait(&status);
```

Example:

``` c
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid_parent, pid_child, wpid;
	int a, b, status;
	pid_parent = getpid();
	printf("[P] Parent process with pid %d \n", pid_parent);

	printf("[P] This program creates a child process and performs the division of two numbers\n");
	printf("[P] Operation: a / b\n");
	printf("[P] Enter a: ");
	scanf("%d", &a);
	printf("[P] Enter b: ");
	scanf("%d", &b);

	pid_child = fork();

	if(pid_child == 0){
		// child
		printf("[C] Child process with pid %d \n", getpid());
		if(b!=0){
			printf("[C] %d / %d = %d \n", a, b, a/b);
			exit(EXIT_SUCCESS); // 0
		}else{
			printf("[C] Error: Division by zero can't be performed. \n");
			exit(EXIT_FAILURE); // 1
		}
	}
	else if(pid_child > 0){
		// parent
		wpid = wait(&status);
		if(wpid == pid_child){
			if(status==EXIT_SUCCESS)
				printf("[P] Child exited normally\n");
			else
				printf("[P] Child process aborted\n");
		}
	}
	else
		fprintf(stderr, "Fork failed \n");
		return 1;
}

```

When a child process finishes, all its resources are deallocated from the main memory, but its *pid* will be in the process table of the OS until wait is called. This because the status value has to be stored until the parent read it. When a child process finishes but the parent have not called the *wait()* function yet, the child process goes to the **zombie** status, when parent calls *wait()*, the process disappears.

If a parent process never calls the *wait()* function, and finished with zombie children, these becomes *orphan* processes, and become *init* children. The *init* process execute *wait()* periodically, deleting all the orphans. Run the following example and finish the program before the child finishes, then check if the child pid exists with the command 'ps -p {pid}'.

``` c
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//proceso padre: createProcessUnix
int main()
{
	pid_t pid_parent, pid_child;
	pid_parent = getpid();

	printf("Parent process with pid %d \n", pid_parent);
	pid_child = fork();

	if(pid_child == 0){
		//child
		printf("Child process with pid %d \n", getpid());
		clock_t before = clock();
		int msec = 0, trigger = 5000;
		do {
		  /*
		   * Do something to busy the CPU just here while you drink a coffee
		   * Be sure this code will not take more than `trigger` ms
		   */

		  clock_t difference = clock() - before;
		  msec = difference * 1000 / CLOCKS_PER_SEC;
		} while ( msec < trigger );
		printf("Child finished \n");

	}
	else if(pid_child > 0){
		//parent
		while(1){}
	}
	else
		fprintf(stderr, "Fork failed \n");
		return 1;
}
```

# References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
