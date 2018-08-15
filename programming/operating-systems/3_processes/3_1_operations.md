---
layout: default
title: Processes
permalink: /programming/operating-systems/3_processes/3_1_operations
---

<h1 style="text-align: center;">Processes</h1>


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
		   // Do something to busy the CPU just here while you drink a coffee
		   // Be sure this code will not take more than `trigger` ms

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

### Multiple child process creation example:

``` c
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int n;                  // Number of processes.
int id;                 // Process ID
pid_t *pid_children;    // Array of process PIDs

// Function to find the process ID in the pid_children process.
int find_pid(pid_t pid){
    for(int i=0; i<n; i++){
        if(pid == pid_children[i])
            return i;
    }
    return -1;
}

// Function that stops the process execution
// for a while.
int delay_ms(int ms){
    clock_t before = clock();
    int msec = 0;
    do {
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;
    } while ( msec < ms );
}

// Start of the parent process.
int main(int argc, char** argv)
{
    int i; // General use variable

    // Read the number of processes to launch
    if(argc == 2){
        n = atoi(argv[1]);
    }else if(argc == 1){
        n = 5;
    }else{
        printf("[P] Error: Wrong number of arguments.\n");
    }

    // Dynamical assigment of the pid_children array
    printf("[P] %d processes are going to be created.\n", n);
    pid_children = new pid_t[n];

    // Loop for process creation
    for(i=0; i<n; i++){
        // Creation of children
        pid_children[i] = fork();
        if(pid_children[i] == 0){
            // If it is the children, it breaks the for.
            id = i;
            printf("[C%d] Hijo creado\n", id);
            break;
        }
    }

    // Here there are 1 parent and 'n' processes.

    if(i==n){ // Parent
        // Loop to wait all the launched processes
        for(i=0; i<n; i++){
            int status, wid;
            pid_t wpid;
            // Get the pid and status of the finished process
            wpid = wait(&status);
            // Find the id of the finished process
            wid = find_pid(wpid);
            // Show the correspondent message
            if(status==0)
                printf("[P] Hijo %d finalizado satisfactoriamente.\n", wid);
            else
                printf("[P] Hijo %d finalizado con error.\n", wid);
        }
        // Finish the parent process
        printf("[P] Proceso padre finalizado\n");
        return 0;
    }else{ // Children
        // Set the seed
        srand (time(NULL)*id);
        // Get a pseudo random number between 1000 and 5000.
        int ms = rand() % 4000 + 1000;
        // Wait for ms miliseconds
        delay_ms(ms);
        // Return sucess code if the id is even
        // and error if the id is odd.
        return id%2;
    }
}
```


# References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
