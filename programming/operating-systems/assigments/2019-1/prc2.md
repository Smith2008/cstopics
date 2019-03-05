---
layout: default
title: Practice 2
permalink: /programming/operating-systems/assigments/2019-1/prc2
---

# Practice 2

Your billionary uncle's bank has expanded!. You are to create a program *mainBank* that, when running, it is a process that represents a bank (only one), so you must execute it including the name of the bank as argument:

``` bash
$ ./mainBank "bancarota"
...
```

You can launch as many banks (processes) as you want, but they can not have the same name. Suppose you launch 2 banks more:

``` bash
$ ./mainBank "bancomer"
...
```

``` bash
$ ./mainBank "banquito"
...
```

And then you try to *open* "bancomer" again, the program must show the corresponding error and close itself:

``` bash
$ ./mainBank "bancomer"
ERROR: This bank is already open.
$
```

When the bank opens, it starts empty (without accounts or clients). And it must show the interface to interact with it (as in the [Practice 1](/cstopics/programming/operating-systems/assigments/2019-1/prc1)).

If you close a bank (i.e. pressing Ctrl+C), you could open it again (with the same name).

You must **add** a functionality to transfer money to account of another **opened** banks. When you do it, the balance of the two account must be updated instantly (e.i. you do not need to select an *update* option, or something like that).

The transfer between banks must show error when:

* The target bank is not open.
* The target account does not exists in the target bank.
* The target account is locked.

### Topics to use:

* [Shared memory](/cstopics/programming/operating-systems/3_processes/3_2_communication)

Create the files and classes you consider necessary. The Makefile must create the *mainBank* binary when you execute *make*.

## Submitting

Create a new **private** GitHub repository named *"2019_1_d3_prc2_Lastname1Firstname1_Lastname2Firstname2"* (E.g. *"2018_2_d3_prc2_CamachoCamilo_PerezPepito"*), and add as collaborators to all your team partners, and the account *edgarcamilocamacho*. The repository must contain:

* cpp and h files.
* Makefile: with rules to compile each class, and the complete project, all (by default), run and clean.
* README.md: The report

Then, download it as *zip* and upload it to the corresponding *moodle* task. **Important**: when submitting the task to moodle, include the *github* repository link, and the name of all the members of the team.

Deadline: Mar 14 / Mar 15
