---
layout: default
title: Threads with OpenMP
permalink: /programming/operating-systems/4_threads/4_2_openmp
---

Previous pages:

- [Operating Systems](/cstopics/programming/operating-systems)
    - [Threads](/cstopics/programming/operating-systems/4_threads)

<h1 style="text-align: center;">Threads with OpenMP</h1>

## What is OpenMP?

* It is not a programming language.
* Works in conjuction with C/C++
* It collects a set of preprocessor directives. Example:

``` c++
#pragma omp parallel
```

## Execution model

1. The program begins in serial mode (a single ***master*** thread).
2. This thread is executed in serial model until a parallel directive is found.
3. The tasks inside the parallel region is executed in multiple threads.
4. After parallel region, serial execution (in master thread) is resumed.

## Environment and Compilation

``` bash
$ export CC=gcc
$ export CFLAGS=-fopenmp
$ export OMP_NUM_THREADS=4
$ gcc -fopenmp foo.c -o foo
```

## OpenMP Functions

* *omp_get_thread_num()*: gets the *number* (starting from 1, not the same that *id*) of the thread. For the master thread it always returns 0.

## Directives

Is always a *pragma* directive. The *omp* word indicates to the compiler that it is a OpenMP directive or construct, to not be ignored.

``` c++
#pragma omp ...
```

### The *parallel* Directive

Defines a parallel region, as follows:

``` c++
// ... serial code ...

#pragma omp parallel
{
    // ...parallel code ...
}

// ... serial code ...
```

A serial *hello world* is like:

``` c++
#include <stdio.h>

int main()
{
    printf("hello world\n");
    return;
}
```

And it parallel implementation:

``` c++
#include <stdio.h>
#include <omp.h>
int main()
{
    #pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        printf("%s %d\n", "hello parallel world from thread #",
        threadID);
    }
    return 0;
}
```

### The *parallel for/do* Directive

Syntaxis:

``` c++
// ... serial code ...

#pragma omp parallel for
for(i = 0; i < N; i++){
    // ... compute stuff ...
}

// ... serial code ...
```

***Example:*** Take a vector of real numbers and map them to exp(x^2) using omp parallel for/do directive.

[x1, x2, x3, ..., XN]

to

[exp(x1^2), exp(x2^2), ..., exp(xN^2)]

Use made up values for vector x, N=1000 and print the sum of the mapping on the screen. Write a serial and parallel version and compare.

``` c++
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
    const int N = 1000;
    float sum = 0.0f;
    float x[N];
    float z[N]; /*the result*/
    int i;

    /* populate x */
    for(i = 0; i < N; i++)
        x[i] = (i+1)*.002;

    /* map */
    #pragma omp parallel for
    for(i = 0; i < N; i++)
    {
        z[i] = exp(x[i]*x[i]);
    }

    /*do a sum*/
    for(i = 0; i < N; i++)
    {
        sum += z[i];
    }

    printf("%f\n", sum);
    return 0;
}
```
