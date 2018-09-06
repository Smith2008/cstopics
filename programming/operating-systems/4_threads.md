---
layout: default
title: Threads
permalink: /programming/operating-systems/4_threads
---

# Threads

A thread is the basic unit of CPU using. Each thread has:

* Thread ID
* Program counter
* Register set
* Stack

And the threads of the same process share:

* Code section
* Data section
* Files, signals, and other operating system resources

By default, a process has a unique thread, even you can create more, allowing the process to execute various tasks at the same time.

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/4_multithread.png" />
</div>

Some examples of multi thread utilization:

* A word processor could use a thread to display graphics, another one to check and process the key pressing, and a third one to check grammar and spelling.
* A web browser may have a thread to display images, and another one to receive network information.
* In a web server, a thread could be launched to listen each client.

### Benefits of using multi thread

* ***Responsiveness***: A program can launch long tasks with threads, and the GUI, for example, can continue working for the user.

* ***Resource sharing***: Taking advantage of the fact that threads share data section, it's easier to communicate them that independent processes.

* ***Economy***: Most of the operating systems take more time in the creation of a new process than with a new thread.

* ***Scalability***: With multi core systems, a process can run in more than one core.


## References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
