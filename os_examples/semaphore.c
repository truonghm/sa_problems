// semaphore implementation

#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void* arg) {
	sem_wait(&semaphore);
	sleep(1);;
	printf("Hello from thread %d\n", *(int*)arg);
	sem_post(&semaphore);
	free(arg);
}

int main(int argc, char** argv) {
	pthread_t th[THREAD_NUM];
	// increase to 2 to have 2 threads running at the same time
	// sem_init(&semaphore, 0, 2);
	sem_init(&semaphore, 0, 1);
	int i;
	for (i = 0; i < THREAD_NUM; i++) {
		int* a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, routine, a) != 0) {
			perror("Failed to create thread");
		}
	}

	for (i = 0; i < THREAD_NUM; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}
	sem_destroy(&semaphore);
	return 0;
}
