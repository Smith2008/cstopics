---
layout: default
title: Processes
permalink: /programming/operating-systems/3_processes/3_0_processes
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

# References

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012
