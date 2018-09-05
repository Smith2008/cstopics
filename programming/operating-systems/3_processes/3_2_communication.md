---
layout: default
title: Processes
permalink: /programming/operating-systems/3_processes/3_2_communication
---

<h1 style="text-align: center;">Processes</h1>

# Interprocess Communication (IPC)

When you launch children processes and you do not share information with/between them, it is called ***independent processes***. But when you want to launch multiple processes to perform specific tasks, you usually do not know only the final status, you want also send information from the children to the parent, in order to collect the data of all the children and process it. In this case it is called ***cooperative processes***, and have the following advantages:

* Access to important common information
* Computing speedup
* Modularity

##  Shared memory

Processes can read and write the same memory section:

<div style="text-align:center">
  <img style="width: 80;" src ="/cstopics/assets/img/programming/os/3_shared_memory.png" />
</div>

Usually, the operating system ensures that a process can't access a memory address associated to other processes, so when you create a new shared memory section, the OS makes the exceptions, allowing this behavior.

You can create a section of shared memory in this way:

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/smem_producer.cpp){:target="blank"}

And read it with:

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/smem_consumer.cpp){:target="blank"}

### Parallel Implementations with Processes

One of the advantages of using multiple processes for one unique application is to speedup tasks. For example, consider the following program that calculates &pi; through iterations:

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/pi.cpp){:target="blank"}

You could parallelize it as below:

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/pi_n_processes.cpp){:target="blank"}

### Producer-Consumer Schema

One way to share information between two processes is to use the Producer-Consumer schema. Imagine the production line of doors in a car factory with three stages: assembling, painting and testing. The first one completes its task and passes the product to the second stage, and so on. If the second stage finishes painting all the doors in its queue, it has to wait to the fists stage finishing to continue.

The next example shows the working of this schema.

***Producer***: When user press enter, the program generates a random number and send it to the queue.

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/queue_producer.cpp){:target="blank"}

***Consumer***: When user press enter, the program reads the last number from the queue (if it is possible), and show it.

[Code here](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/queue_consumer.cpp){:target="blank"}

##  Pipes

Were one of the first methods used by UNIX to perform IPC, and provide one of the simpler ways to communicate two processes.

When designing with pipes, you have to consider:

* Is the communication bidirectional or unidirectional?
* If bidirectional, is it half duplex or full duplex?
* Must a relationship (as *parent-child*) exist between the processes?
* Can pipes communicate between different host machines?

There are two main types of pipes: *ordinary pipes* and *named pipes*.

### Ordinary Pipes

Ordinary pipes are unidirectional, and use the producer-consumer schema. The producer writes the pipe to one end of the pipe (the ***write-end***), and the consumer read from the other end (the ***read-end***). If you need ***bidirectional*** communication, you must create ***two pipes***, one for each direction.\

Pipes are special types of files, when you create a pipe (with the function ***pipe()***), it creates the ***int fd[2]*** array with two file identifier, ***fd[0]*** is the read-end of the pipe, and ***fd[1]*** is the write-end.
In this way, you can use *POSIX* functions to read and write in pipes as files, as *open()*, *close()*, *write()*, *read()*, etc.

Ordinary pipes can only be used by a process and its children (remember that when you do *fork()*, the child
process inherits open files from its parent).

Check the [example](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/ordinary_pipes.cpp){:target="blank"} of using ordinary pipes in Linux.

### Named Pipes

* Allow bidirectional communication
* Parent-child relationship is not required.
* Allow several writers.
* Continue in the system even if the processes finish.

In UNIX:

* It is known as ***FIFO***.
* Bidirectional and half-duplex communication.
* It behaves as a file.
* Communicate processes in the same host system.

Check the *chat* example, based on two processes. [User1](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/5namedPipe_p11.cpp){:target="blank"} and [User2](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/5namedPipe_p22.cpp){:target="blank"}
