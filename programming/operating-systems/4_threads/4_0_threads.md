---
layout: default
title: Threads
permalink: /programming/operating-systems/4_threads/4_0_threads
---

<h1 style="text-align: center;">Threads</h1>

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

So, parallel programming take advantage of the new computing systems, but implies more work and experience from the developer.

### Parallelism Types

* ***Data parallelism***: There are one task to be performed, and the data to be processes dis distributed in the threads.

Example: Calculate the sum of an array *vec* of size *N*.

*Thread A*: Sums from *vec[0]* to *vec[N/2-1]*.

*Thread B*: Sums from *vec[N/2]* to *vec[N-1]*.

* ***Taks parallelism***: There are multiple taks, that are distributed in the threads.

Example: Calculate the mean and standard deviation of an array *vec*.

*Thread A*: Calculate the mean of *vec*.

*Thread B*: Calculate de standard deviation of *vec*.

# Multithreading Models

When threads are used, there are two ways to see the problem, based on the level where they are managed:

* ***User threads:*** Are managed without the kernel support, in the user level.
* ***Kernel threads:*** Managed directly by the operating system.

There are different models to link the user and kernel threads:

### Many-to-One model

All the threads of the process are mapped to the same kernel thread, and the management is performed by libraries in the user space. It is efficient because the new threads are created without the intervention of the operating system, but it see all the threads as only one, so if one of them uses a blocking system call, all the threads will be halted, so the parallelism is lost, so in multicore systems this is not a good model.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_many_to_one.png" />
  <div>[Silberschatz12]</div>
</div>

### One-to-One model

This model maps each user thread to a kernel thread, allowing the execution of multiple thread in multiple cores, and the using of blocking system calls. The unique drawback is that the creation of kernel threads takes more time, affecting the application performance. Linux and Windows use this model.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_one_to_one.png" />
  <div>[Silberschatz12]</div>
</div>

### Many-to-Many model

This model creates user level threads, but when it is necessary to use blocking system calls, the system schedules it as a independent kernel thread, so you can create as many threads as you want, without affecting the performance so much.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_many_to_many.png" />
  <div>[Silberschatz12]</div>
</div>

## References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
