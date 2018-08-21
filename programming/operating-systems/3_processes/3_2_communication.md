---
layout: default
title: Processes
permalink: /programming/operating-systems/3_processes/3_2_communication
---

<h1 style="text-align: center;">Processes</h1>

# Interprocess Communication (IPC)

When you launch children processes and you do not share information with/between them, it is called ***independent processes***. But when you want to launch multiple processes to perform specific tasks, you usually do not know only the final status, you want also send information from the children to the parent, in order to collect the data of all the children and process it. In this case it is called ***cooperative processes***, and have the following advantages:

* Access to important common information
* Computing speedup
* Modularity

##  Shared memory

Processes can read and write the same memory section:



Usually, the operating system ensures that a process can't access a memory address associated to other processes, so when you create a new shared memory section, the OS makes the exceptions, allowing this behavior.

You can create a section of shared memory in this way:

``` c++
#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap

const int SIZE = 4096; // Size in bytes of the shared memory section
const char *name = "OS"; // Name of the shared memory section
const char *messsage_0 = "Hello "; // Beginning ot the string to be shared
const char *messsage_1; // End or the string to be shared

int main(int argc, char** argv){
    if(argc==2){
        messsage_1 = argv[1];
    }else if(argc==1){
        messsage_1 = "World!\n";
    }else{
        printf("[P] Error. Incorrect number of parameters.\n");
        return 1;
    }

	int shm_fd; // Descriptor of shared memory
	void *ptr; // Pointer to shared memory*

	// shm_open creates the shared memory and return the descriptor
	// name: must be known by all the processes that are goint to access the shared memory
	// acess memory: O_CREAT (creates the shared memory if it does not exists)
	// 				 OR
	// 				 O_RDWR (R/W access)
	// 0666 permisions
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	// ftruncate configures the shared memory size
	ftruncate(shm_fd, SIZE);
	// mmap returns the ponter to the shared memory
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	// Write the first message on the shared memory
	sprintf((char *)ptr, "%s", messsage_0); //*
	// Move the pointer to the end of the first message + 1
	ptr += strlen(messsage_0);
	// Srite the second message
	sprintf((char *)ptr, "%s", messsage_1); //*
	// Move the pointer to the end of the second message + 1
	ptr += strlen(messsage_1);

	return 0;
}
```

And read it with:

``` c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

const int SIZE = 4096; // Size in bytes of the shared memory
const char *name = "OS"; // Name of the shared memory

int main(int argc, char** argv){

	int shm_fd; // Descriptor of the shared memory
	void *ptr; // Pointer to the shared memory

	// Open the shared memory with only read permissions
	shm_fd = shm_open(name, O_RDONLY, 0666);
	if(shm_fd==-1){
		printf("The shared memory does not exists.\n");
		exit(1);
	}
	// Get the pointer
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	// Show the content
	printf("%s", (char *)ptr);

	// If there are arguments, remove the shared memory
	if(argc>1){
		shm_unlink(name);
	}
	return 0;

}

```

### Parallel Implementations with Processes

One of the advantages of using multiple processes for one unique application is to speedup tasks. For example, consider the following program that calculates &pi; through iterations:

``` c++
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    int i, numInters;

    if(argc==2){
        numInters = atoi(argv[1]);
    }else if(argc==1){
        numInters = 1000000000;
    }else{
        printf("[P] Error. Número incorrecto de parámetros.\n");
        return 1;
    }

    double calcPi = 0.0;

    for(i=0; i<numInters; i++){
        calcPi += 1.0/((double)(i*4+1));
        calcPi -= 1.0/((double)(i*4+3));
    }

    calcPi *= 4.0;
    printf("Pi = %.30f\n",calcPi); //*
}
```

You could parallelize it as below:

``` c++
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/types.h>

pid_t *pidChildren;
int n, id;
void *smem;

int find_child(pid_t pid){
    for(int i=0; i<n; i++){
        if(pid == pidChildren[i])
            return i;
    }
    return -1;
}

int main(int argc, char** argv)
{
    int i, numInters;

    if(argc==3){
        numInters = atoi(argv[1]);
        n = atoi(argv[2]);
        printf("[P] Iniciando con %d iteraciones y %d procesos.\n", numInters, n);
    }else if(argc==1){
        numInters = 1000000000;
        n = 4;
        printf("[P] Iniciando con %d iteraciones y %d procesos.\n", numInters, n);
    }else{
        printf("[P] Error. Número incorrecto de parámetros.\n");
        return 1;
    }

    smem = mmap(NULL, n*sizeof(float), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    printf("[n] Creando %d hijos.\n\n", n);
    pidChildren = new pid_t[n];

    for(i=0; i<n; i++){
        pidChildren[i] = fork();
        if(pidChildren[i] == 0){
            id = i;
            printf("[C%d] Hijo creado.\n", id);
            break;
        }
    }

    if(i==n){
        double totalPi = 0.0;
        printf("[P] Esperando finalización de hijos.\n");
        for(i=0; i<n; i++){
            int status;
            pid_t wpid = wait(&status);
            int wid = find_child(wpid);
            printf("[P] Finalizado el hijo %d\n", wid);
        }
        for(i=0; i<n; i++){
            totalPi += *(((double*)smem)+i);
        }
        totalPi *= 4.0;
        printf("[C%d] Pi = %.30f\n", id, totalPi);
        munmap(smem, n*sizeof(float));
        printf("[P] Fin de proceso padre.\n");
        return 0;
    }else{
        double calcPi = 0.0;
        int start = (numInters/n)*id;
        int stop = (numInters/n)*(id+1);
        for(i=start; i<stop; i++){
            calcPi += 1.0/((double)(i*4+1));
            calcPi -= 1.0/((double)(i*4+3));
        }
        *(((double*)smem)+id) = calcPi;
        // calcPi *= 4.0;
        // printf("[C%d] Pi = %.30f\n", id, calcPi);
        return 0; //*
    }
}
```

### Producer-Consumer Schema

One way to share information between two processes is to use the Producer-Consumer schema. Imagine the production line of doors in a car factory with three stages: assembling, painting and testing. The first one completes its task and passes the product to the second stage, and so on. If the second stage finishes painting all the doors in its queue, it has to wait to the fists stage finishing to continue.

The next example shows the working of this schema.

***Producer***: When user press enter, the program generates a random number and send it to the queue.

***Consumer***: When user press enter, the program reads the last number from the queue (if it is possible), and show it.
