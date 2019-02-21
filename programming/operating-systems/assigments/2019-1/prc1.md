---
layout: default
title: Practice 1
permalink: /programming/operating-systems/assigments/2019-1/prc1
---

# Practice 1

You are to create the database for the bank of you billionary uncle, and you decided to create 3 classes to order it:

**BankClient:**

Members to store:

* Last name
* First name
* Age
* Identification
* Array of pointers to the accounts

Methods to:

* Update data
* Beans for names and age

**BankAccount:**

Members to store:

* Account number
* State (locked or not locked)
* Key (4 digits)
* Balance
* Pointer to the owner's object

Methods to:

* Beans for account number, key, balance.
* Block
* Unblock
* Check key
* Deposit
* Withdrawal
* Consult State
* Consult Balance

**Bank:**

Members to store:

* Name of the bank
* Array with clients
* Array with accounts

Methods to:

* Get the name of the bank
* Create client
* Update data of client
* Consult client by: Last name, identification
* Create account
* Consult account: state, balance, owner. (with key)
* Block and Unblock account (with key)
* Deposit
* Withdrawal (with key)
* Transfer between accounts (with key of withdrawal account)

You can add the methods and members you consider needed.

Create a *main.cpp* file that creates 2 Banks, and allows you to test ALL the Bank methods using terminal commands.

## Submitting

Create a new **private** GitHub repository named *"2019_1_d3_prc1_Lastname1Firstname1_Lastname2Firstname2"* (E.g. *"2018_2_d3_prc1_CamachoCamilo_PerezPepito"*), and add as collaborators to all your team partners, and the account *edgarcamilocamacho*. The repository must contain:

* Makefile: with rules to compile each class, and the complete project, all (by default), run and clean.
* main.cpp
* bank.cpp & bank.h
* account.cpp & account.h
* client.cpp & client.h
* README.md: The report

Deadline: Feb 28 / Mar 01
