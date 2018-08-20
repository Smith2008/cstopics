---
layout: default
title: Processes
permalink: /programming/operating-systems/assigments/prc1
---

<h1 style="text-align: center;">Processes</h1>

## Practice 1

Create a new **private** Bitbucket repository named *"2018_2_d3_prc1_Lastname1Firstname1_Lastname1Firstname1"* (E.g. *"2018_2_d3_prc1_CamachoCamilo"*),  share it with the account *"camilocamachousta"*, and add the files below:

* programFirstname1Firstname2.cpp, a program that prints 'hello world' and the student's names.
* Makefile: with rules to compile (default) and clean.
* install.sh: explained below.

When the cpp file is compiled, an output file called 'programFirstname1Firstname2' (without extension), this file is going to be named 'the program' for this guide.

The installation script must:
* Compilate the source, generating the program.
* Create an empty folder in the user's home called 'FirstName1_FirstName2', and install (copy) the program there.
* Create a text file called 'licence.txt', and in write in it the following: "Licensed to [user]"
* Ask the user if he/she wants to create a copy of the programa in its home folder, if yes, create it.

The installer must operate regardless of the directory where it is executed, and must stop and show the corresponding error when one of the commands does not finish successfully.

Deadline: Aug 23
