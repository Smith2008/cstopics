---
layout: default
title: Homework 6
permalink: /programming/operating-systems/assigments/2018-2/hw6
---

## Homework 6

Parallelize the [pi calculation algorithm](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/pi.cpp){:target="blank"} example using [Posix](/cstopics/programming/operating-systems/4_threads/4_1_posix){:target="blank"} and [OpenMP](/cstopics//programming/operating-systems/4_threads/4_2_openmp){:target="blank"}, and create the [SpeedUp Plot](/cstopics/programming/operating-systems/4_threads/4_0_threads#speedup){:target="blank"} of each of them (2 in total). The programs must receive, as in the example,  the number of iterations and the number of threads to be launched.

You must also write two scripts that execute all the tests of the speedup, one of them for Posix (*speedup_posix.sh*) and the other for OpenMP (*speedup_openmp.sh*), the script must receive the maximum number of threads as argument, execute all the tests with 1,000,000,000 of iterations, and generate a text file with the results (*speedup_posix.txt* and *speedup_openmp.txt*), for example:

``` bash
$ ./speedup_openmp.sh 12
# Running pi calculation with OpenMP, with 1 thread and 1,000,000,000 iterations.
...
# Running pi calculation with OpenMP, with 2 threads and 1,000,000,000 iterations.
...
# Running pi calculation with OpenMP, with 3 threads and 1,000,000,000 iterations.
...
...
...
# Running pi calculation with OpenMP, with 12 threads and 1,000,000,000 iterations.
...
```

Generated *speedup_posix.txt* file:

```
1 threads = 75.78s
2 threads = 37.91s
3 threads = 25.42s
4 threads = 19.28s
5 threads = 15.39s
6 threads = 13.68s
7 threads = 13.54s
8 threads = 14.26s
9 threads = 12.78s
10 threads = 13.36s
11 threads = 13.01s
12 threads = 12.93s
```

Create a report PDF file with the two SpeedUp tables and plots, and conclude according to the Amdahl Law.

Create a new **private** Bitbucket repository named *"2018_2_d3_hw6_LastnameFirstname"* (E.g. *"2018_2_d3_hw6_CamachoCamilo"*), share it with the account *"camilocamachousta"*, and add the files below:

* *Makefile*
* *pi_posix.cpp*
* *pi_openmp.cpp*
* *speedup_posix.sh*
* *speedup_openmp.sh*
* *report.pdf*

***Evaluation Items***:

* Name of files, format, etc.
* The repository exists.
* It compiles
* Each implementation (Posix and OpenMP) runs individually with any number of threads and iterations.
* The scripts work for any number of threads.
* The output files have the correct format.
* Quality of the report (quality is not related to the format of the document, it is about the content).

When the repository is ready, download it as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Oct 18
