---
layout: default
title: Practice 5
permalink: /programming/operating-systems/assigments/2018-2/prc5
---

# Practice 5

Figure the customer support hall of a company (for example, the telephone company), there are N consultants that people ask for questions about the service, present complaints, and so on. The first K people can use the K chairs in the hall, but if they are full, they have to wait in the queue. As a consultant is free, a customer from the chairs can pass to his desk, and as a chair is free, the first person in the queue can use it.

Simulate this process in a Qt GUI. The GUI has to show:

* The N consultants and their state {BUSY, FREE}, if they are busy, you must show the client who is being attended.
* The K chairs {FULL, EMPTY}, if they are busy, you must show the client who is on the chair.
* The queue of clients, and the state {QUEUING, SITTING, CONSULTING} of each client .

The N consultants must to be assumed as a unique resource, controlling the access to it with a semaphore. The same case must be assumed with the K chairs (you can not create a semaphore per chair or consultant).

The clients are implemented as threads. A new client must be created every TA milliseconds (TA is a random number in the range [TA0, TA1]), and will wait for a chair in the queue, when a chair is free, the client will use it, and when a consultant is free, the client will go to its desk. The consult takes TB milliseconds (TB is a random number in the range [TB0, TB1]). When the consult finishes,  the client (thread) must be deleted.

The GUI must start with numeric inputs that allow you to choose the values of N, K, TA0, TA1, TB0 and TB1, and a START button to start the simulation. When the window is closed, all the threads must be deleted.

Evaluation items:

* To be continued...

## Submit

Create a new **private** Bitbucket repository named *"2018_2_d3_prc5_LastnameFirstname"* (E.g. *"2018_2_d3_prc5_CamachoCamilo"*), share it with the account *"camilocamachousta"*, and add practice files.

When the repository is ready, download it as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Nov 15, in class.
