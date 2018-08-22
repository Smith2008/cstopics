#include <stdio.h> //sprintf
#include <stdlib.h>
#include <string.h>	//strlen
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <time.h>

#define BUFFER_SIZE 10

typedef unsigned char uchar;

const int SIZE = 4096; // Size in bytes of the shared memory section
const char *name = "OS"; // Name of the shared memory section

typedef struct{
	int number;
}item;

int shm_fd; // Descriptor of shared memory
void *ptr; // Pointer to shared memory
item *queue;
volatile int *in, *out;

int main(int argc, char** argv){
	srand (time(NULL));

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	if(shm_fd==-1){
		printf("Memory shared could not be created.\n");
	}
	ftruncate(shm_fd, BUFFER_SIZE*sizeof(item) + 2*sizeof(int));
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	queue = (item*)ptr;
	in = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item));
	out = (int*)((uchar*)ptr + BUFFER_SIZE*sizeof(item) + sizeof(int));

	*in = 0;
	*out = 0;

	while(1){
		int x;
		printf("Press Enter to send random number.");
		getchar();
		x = rand();
		printf("x = %d\n",x);
		if( (*in+1)%BUFFER_SIZE == *out ){
			printf("The buffer is full, waiting for a space in the queue...\n");
			while( (*in+1)%BUFFER_SIZE == *out );
		}
		queue[*in].number = x;
		printf("Value sent!\n");
		*in = (*in+1)%BUFFER_SIZE;
	}
}	