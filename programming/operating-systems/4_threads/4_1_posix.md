---
layout: default
title: Threads with Posix
permalink: /programming/operating-systems/4_threads/4_1_posix
---

<h1 style="text-align: center;">Threads with Posix</h1>

You must include:

``` c++
#include <pthread.h>
```

Suppose you have a function (defined as a pointer):

``` c++
//funcion del hilo
void *runner(void *param){
	int i, N;
	stringstream ss((char*)param);
	ss >> N;
	sum = 0; //inicializa variable global
	for(i=1; i<=N; i++){
		sum += sin((double)i);
	}
	pthread_exit(0);
}
```

the first line sets the return value of the thread. You always send the parametes as a pointer to *void*, and you *cast* it in the function.

You have to create the *id* and *attributes* structures for the thread:

``` c++
pthread_t tid;
pthread_attr_t attr;
```

You can initialize the *attributes* with the default value.

``` c++
pthread_attr_init(&attr);
```

To launch the thread, you use the *pthread_create* function, passing as arguments the pointers to the *id* and the *attributes* structures, the pointer to the function to execute in the thread, and the *void* pointer to the thread arguments.

``` c++
pthread_create(&tid, &attr, runner, argv[1]);
```

You can wait for the finishing of the thread:

``` c++
pthread_join(tid, NULL);
```

Check the [one thread example](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/crear_hilo.cpp){:target="blank"}.

If you want to launch more that one thread, you could do it creating arrays for *ids* and *attributes*, and launch them *one by one*. Check the [multiple threads example](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/crear_Nhilos.cpp){:target="blank"}
