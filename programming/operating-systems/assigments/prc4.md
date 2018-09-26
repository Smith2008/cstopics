---
layout: default
title: Practice 4
permalink: /programming/operating-systems/assigments/prc4
---

## Practice 4

UOS (Useless Operating System) is a new process manager and interprocess communication mechanism that you are going to write in C/C++. There are two types of processes (the two codes you are going to write), *master* and *node* (*uos_master.cpp* and *uos_node.cpp* respectively).

When you execute a *master* process, you have to include the *master name* in the first argument:

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
...
```

If you does not include *master name*, the program must show an error:

```
$ uos_master
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: You have not entered the master name
[INFO]: Finishing master process
$
```

As you could see, when the master shows general information, add te prompt "[INFO]: ", and when it shows and error, it uses the prompt "[ERROR]: ". When the process is finished, it must be shown a INFO message with the text "Finishing master process" (even if it is finished with *Ctrl+C*).

When you execute a *node* process, you have to include the *node name* in the first argument, and the name of the master you want to subscribe to.

```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node1" subscribed to the master "master1"
>>
```

The previous INFO message is going to be shown only if the "master1" master process exists and is runnin, otherwise, the process must show an error:

```
$ uos_node node1 master2
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: Master "master2" not found.
[INFO]: Finishing master process
$
```

The node process must also show an ERROR message if the user does not enter both node and master names:

```
$ uos_node node1
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: You have not entered both node and master names.
[INFO]: Finishing master process
$ uos_node
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: You have not entered both node and master names.
[INFO]: Finishing master process
$
```

Note that you can create multiple *masters*, and *nodes* can subscribe to any of them.

When a node starts correctly, a prompt ">> " must appear, indicating that you can send messages to other nodes.
There are three types of messages (that must be implemented as google protobuffers):

* String
* Number (double)
* Number array

Consider:

* Creating a shared memory when a master is created.
* Creating one pipe from/to each new subscribed node to the master.
