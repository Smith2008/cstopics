---
layout: default
title: Practice 4
permalink: /programming/operating-systems/assigments/prc4
---

# Practice 4

UOS (Useless Operating System) is a new process manager and interprocess communication mechanism that you are going to write in C/C++. There are two types of processes (the two codes you are going to write), *master* and *node* (*uos_master.cpp* and *uos_node.cpp* respectively).

## Master process

When you execute a *master* process, you have to include the *master name* in the first argument:

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
...
```

### Master errors

If you does not include *master name*, the program must show an error:

```
$ uos_master
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: You have not entered the master name
[INFO]: Finishing master process
$
```

As you could see, when the master shows general information, add te prompt "[INFO]: ", and when it shows an error, it uses the prompt "[ERROR]: ". When the process is finished, it must be shown a INFO message with the text "Finishing master process" (even if it is finished with *Ctrl+C*).

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
^C
[INFO]: Finishing master process
$
```

The master must also show ERROR if there is other *master process* with the same name.

***Terminal 1:***
```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
...
```

***Terminal 2:***
```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: There is another process with the name "master1"
[INFO]: Finishing master process
$
```


## Node process

When you execute a *node* process, you have to include the *node name* in the first argument, and the name of the master you want to subscribe to.

```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node1" subscribed to the master "master1"
>>
```

If everything is okay, the master must show the INFO message too:

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
[INFO]: Node "node1" subscribed
...
```

### Node errors

The previous INFO message is going to be shown only if the "master1" master process exists and is running, otherwise, the process must show an error:

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

The node process must also show an ERROR message if you are trying to subscribe to a master that already has a subscribed node with the same name (you can create same name nodes, but subscribed to different masters):

```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[ERROR]: Master "master2" has already a subscribed node with the name "node1".
[INFO]: Finishing master process
$
```

And the master must show the error too:

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
[ERROR]: A node "node1" wants to subscribe, but there are a "node1" node already subscribed.
...
```

## Internodes messages

Note that you can create multiple *masters*, and *nodes* can subscribe to any of them.

When a node starts correctly, a prompt ">> " must appear, indicating that you can send messages to other nodes.
There are three types of messages (that must be implemented as google protobuffers, one per type):

* String ("str")
* Double number ("num")
* Double number array ("numArray")

The format to send a message is: *"send [destination node] [mesage type] [message content]"*, for example:

***Terminal 1:***
```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
...
```

***Terminal 2:***
```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node1" subscribed to the master "master1"
>>
```

***Terminal 3:***
```
$ uos_node node2 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node2" subscribed to the master "master1"
>>
```

When you send a message from "node1":

***Terminal 2:***
```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node1" subscribed to the master "master1"
>> send node2 str 'hello node 2'
>>
```

The master will show the transfer:

***Terminal 1:***
```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
[INFO]: Node "node1" has sent a message "str" to node "node2"
...
```

And the "node2" node will receive the message instantly:

***Terminal 3:***
```
$ uos_node node2 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node2" subscribed to the master "master1"
>>
[INFO]: Message "str" from "node1": 'hello node 2'
>>
```

Note that when a message is received, it is shown by the INFO message, and the prompt ">> " appears again.

### Current line backup

If you are typing a line in a node, and a message is received, it is shown, but the line you were typing has to be "restored", for the previous example, if you were writing a line when the message was received:

***Terminal 3:***
```
$ uos_node node2 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node2" subscribed to the master "master1"
>> send no
[INFO]: Message "str" from "node1": 'hello node 2'
>> send no
```

### Message errors

If you mistype the line, the node must show error:

```
$ uos_node node1 master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Node "node1" subscribed to the master "master1"
>> send node2 str
[ERROR]: Syntax error
>>
```

And if a node tries to send a message to a non-existent node, the sender node must not show error, but the master must:

```
$ uos_master master1
--- Welcome to UOS, the most useless operating system in the world ---
[INFO]: Master created with the name "master1"
[ERROR]: Node "node1" has tried to send a message "num" to the non-existing "node3" node.
...
```

## Design tips

You should consider:

* Creating a shared memory when a master is created.
* Creating one pipe from/to each new subscribed node to the master.

## Report

You must create a report, where you explain (without code):

* Flow diagrams of master and node
* Structure of shared memories
* Architecture of pipes
* Protobuffers (in this case you can include the protobuffers code)
* Any other thing you think could be usefull

## Score

* Working (40%)
    * The makefile works (in the teacher's computer), and the master and node processes execute without errors.
    * Master shows all the established INFO and ERROR messages
    * Node shows all the established INFO and ERROR messages
    * Processes use correctly the command line arguments, and check associated errors
    * Can't be created multiple masters with the same name
    * Node detects if the master it want to subscribe to does not exist
    * Node and master detects that the master it want to subscribe to already has a node with the same name
    * Master detects and show that a node was subscribed
    * Messages of type "str" are delivered correctly, and the master detects and shows it
    * Messages of type "num" are delivered correctly, and the master detects and shows it
    * Messages of type "numArray" are delivered correctly, and the master detects and shows it
    * Node detects syntax errors in the message line
    * Master detects and shows when a node tries to send a message to a non-existing node
    * (x2 item) Current line backup works correctly
* Report (30%)
* Explanation (30%)

The max score for the report and the explanation is the working one. For example, if you program only works in half, and your report and explanations are excellent. Your score is:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
2.5 \times 40\% + (5.0 \times 50\%) \times 30\% + (5.0 \times 50\%) \times 30\% = 2.5
"/>

## Note

The details that are not explicitly specified in this guide can be assumed to the developer's liking.

## Submit

Create a new **private** Bitbucket repository named *"2018_2_d3_prc4_LastnameFirstname"* (E.g. *"2018_2_d3_prc4_CamachoCamilo"*), share it with the account *"camilocamachousta"*, and add practice files:

* *uos_master.cpp* with the *c++* code for the producer.
* *uos_node.cpp* with the *c++* code for the consumer.
* A *Makefile* with the rules *all*, *uos_master*, *uos_node* and *clean*. (Refer to the [C/C++ in Linux](/cstopics/programming/c-c++/c_c++_in_linux) guide)
* The report in PDF format.

When the repository is ready, download it as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Oct 11, in class.
