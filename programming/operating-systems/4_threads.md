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
  <div>[Silberschatz12]</div>
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


## Multicore programming

* ***Concurrency***: Ability to perform more that one task, managing them to allow the execution and progress of all of them.
* ***Parallelism***: Multiple task can be performed simultaneously.

On a system with a single core, the concurrency is based in scheduling or tasks, where are interleaved to be executed in the core. But in multicore systems, the concurrency is performed executing different tasks to each core parallelly.

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/4_singlecore.png" />
  <img style="width: 55%;" src ="/cstopics/assets/img/programming/os/4_multicore.png" />
  <div>[Silberschatz12]</div>
</div>

### Programming Challenges

There are five areas that present challenges in parallel programming:

* ***Identifying tasks***: Which task, or section of tasks, can be parallelized, for example:

``` c
// Can be parallelized:
for(i=0; i<N; i++){
    z[i] = z*x[i] + y[i];
}

// Can NOT be parallelized:
for(i=0; i<N; i++){
    z[i] = z*x[i] + z[i-1];
}
```

* ***Balance***: Is it worth to parallelize?

``` c
// It could be worth it.
for(i=0; i<10e8; i++){
    z[i] = z*x[i] + y[i];
}

// It maybe not worth it.
for(i=0; i<100s; i++){
    z[i] = z*x[i] + y[i];
}
```

* ***Data splitting***: How are you going to divide and assign the information to the threads.

* ***Data dependency***: You must analyze if more than one thread uses the same information, if yes, you have to sync them.

* ***Testing and debugging*** could be more difficult.

So, parallel programming take advantage of the new computing systems, bit implies more

## References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
