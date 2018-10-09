---
layout: default
title: Threads
permalink: /programming/operating-systems/4_threads/4_0_threads
---

Previous pages:

- [Operating Systems](/cstopics/programming/operating-systems)
    - [Threads](/cstopics/programming/operating-systems/4_threads)

Table of contents:

- [Threads](#threads)
    - [Benefits of using multithread](#benefits)
    - [Multicore programming](#multicore)
    - [Programming Challenges](#challenges)
- [Parallelism Types](#parallelism)
- [Multithreading Models](#models)
    - [Many-to-One model](#many2one)
    - [One-to-One model](#one2one)
    - [Many-to-Many model](#many2many)
- [SpeedUp](#speedup)
    - [Amdahl Law](#amdahllaw)
- [References](#references)



<a name='threads'></a>
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

<a name='benefits'></a>
### Benefits of using multithread

* ***Responsiveness***: A program can launch long tasks with threads, and the GUI, for example, can continue working for the user.

* ***Resource sharing***: Taking advantage of the fact that threads share data section, it's easier to communicate them that independent processes.

* ***Economy***: Most of the operating systems take more time in the creation of a new process than with a new thread.

* ***Scalability***: With multi core systems, a process can run in more than one core.

<a name='multicore'></a>
## Multicore programming

* ***Concurrency***: Ability to perform more that one task, managing them to allow the execution and progress of all of them.
* ***Parallelism***: Multiple task can be performed simultaneously.

On a system with a single core, the concurrency is based in scheduling or tasks, where are interleaved to be executed in the core. But in multicore systems, the concurrency is performed executing different tasks to each core parallelly.

<div style="text-align:center">
  <img style="width: 80%;" src ="/cstopics/assets/img/programming/os/4_singlecore.png" />
  <img style="width: 55%;" src ="/cstopics/assets/img/programming/os/4_multicore.png" />
  <div>[Silberschatz12]</div>
</div>

<a name='challenges'></a>
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

<a name='parallelism'></a>
### Parallelism Types

* ***Data parallelism***: There are one task to be performed, and the data to be processes dis distributed in the threads.

Example: Calculate the sum of an array *vec* of size *N*.

*Thread A*: Sums from *vec[0]* to *vec[N/2-1]*.

*Thread B*: Sums from *vec[N/2]* to *vec[N-1]*.

* ***Taks parallelism***: There are multiple taks, that are distributed in the threads.

Example: Calculate the mean and standard deviation of an array *vec*.

*Thread A*: Calculate the mean of *vec*.

*Thread B*: Calculate de standard deviation of *vec*.

<a name='models'></a>
# Multithreading Models

When threads are used, there are two ways to see the problem, based on the level where they are managed:

* ***User threads:*** Are managed without the kernel support, in the user level.
* ***Kernel threads:*** Managed directly by the operating system.

There are different models to link the user and kernel threads:

<a name='many2one'></a>
### Many-to-One model

All the threads of the process are mapped to the same kernel thread, and the management is performed by libraries in the user space. It is efficient because the new threads are created without the intervention of the operating system, but it see all the threads as only one, so if one of them uses a blocking system call, all the threads will be halted, so the parallelism is lost, so in multicore systems this is not a good model.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_many_to_one.png" />
  <div>[Silberschatz12]</div>
</div>

<a name='one2one'></a>
### One-to-One model

This model maps each user thread to a kernel thread, allowing the execution of multiple thread in multiple cores, and the using of blocking system calls. The unique drawback is that the creation of kernel threads takes more time, affecting the application performance. Linux and Windows use this model.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_one_to_one.png" />
  <div>[Silberschatz12]</div>
</div>

<a name='many2many'></a>
### Many-to-Many model

This model creates user level threads, but when it is necessary to use blocking system calls, the system schedules it as a independent kernel thread, so you can create as many threads as you want, without affecting the performance so much.

<div style="text-align:center">
  <img style="width: 60%;" src ="/cstopics/assets/img/programming/os/4_many_to_many.png" />
  <div>[Silberschatz12]</div>
</div>

<a name='speedup'></a>
## SpeedUp

SpeedUp measures how fast is the parallelized implementation of an algorithm compared with its serial implementation:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  speedup_{N} = \frac{t_s}{t_{pN}}
"/>

Where <img src=" https://latex.codecogs.com/gif.latex? speedup_N "/> is the SpeedUp with <img src=" https://latex.codecogs.com/gif.latex? N "/> threads, <img src=" https://latex.codecogs.com/gif.latex? t_s "/> is the execution time with the serial implementation, and <img src=" https://latex.codecogs.com/gif.latex? t_{pN} "/> is  the execution time with <img src=" https://latex.codecogs.com/gif.latex? N "/> threads.

You could think that SpeedUp is always proportional to the number of threads, i.e., with 2 threads you should have a <img src=" https://latex.codecogs.com/gif.latex? speedup=2 "/>, with 3 threads <img src=" https://latex.codecogs.com/gif.latex? speedup=3 "/>, and so on. But it is not completely true, consider the following SpeedUp table, where the [pi calculation algorithm](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/pi.cpp){:target="blank"} was parallelized via threads, and tested with up to 12 cores. The real columns contain the measures, and the ideal columns have the expected values.

<div class="picture">
    <img style="width:50%;" src ="/cstopics/assets/img/programming/os/4_speedup_table.png" />
</div>

<div class="picture">
    <img style="width:50%;" src ="/cstopics/assets/img/programming/os/4_speedup_plot.png" />
</div>

As we can see, the real measures follow the ideal behavior, but it "saturates" in about 6.

<a name='amdahllaw'></a>
### Amdahl Law

It says that your SpeedUp will be truncated by the following equation:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  speedup_{N} \leq \frac{1}{S + \frac{(1-S)}{N} }
"/>

Where <img src=" https://latex.codecogs.com/gif.latex? S "/> is the portion of the algorithm that is not implemented (serial), so, <img src=" https://latex.codecogs.com/gif.latex? (S-1) "/> is the section that is parallel.

For <img src=" https://latex.codecogs.com/gif.latex? S=25\% "/> and <img src=" https://latex.codecogs.com/gif.latex? (1-S)=75\% "/>, you get:

<div class="picture">
    <img style="width:80%;" src ="/cstopics/assets/img/programming/os/4_amdahllaw.png" />
</div>

Note that the SpeedUp tends to be:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  \lim_{N \to \infty } speedup_{N} = \frac{1}{S}
"/>

That indicates that for our example of pi calculation, <img src=" https://latex.codecogs.com/gif.latex? 1/6 = 16.7\% "/> of the implementation was parallel. It was probably the section of the program where we distributed the charge, and where the final sum was performed.

<a name='references'></a>
## References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
