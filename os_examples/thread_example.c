// create 3 threads
// 1 thread prints all odd numbers from 1 to 100
// 1 thread prints all even numbers from 1 to 100
// 1 thread  prints all prime numbers from 1 to 100

#include <pthread.h>
#include <stdio.h>

void *ALL_IS_OK = (void *)123456789L;
char *mess[3] = {"thread1", "thread2", "thread3"};
void *writer(void *arg)
{
	if ((char *)arg == "thread1") {
		int i, j;
		for (i = 1; i <= 100; i+=2)
		{
			printf("I'm odd %d\n", i);
			j = 800000;
			while (j != 0)
				j--;
		}
	}
	else if ((char *)arg == "thread2") {
		int i, j;
		for (i = 2; i <= 100; i+=2)
		{
			printf("I'm even %d\n", i);
			j = 800000;
			while (j != 0)
				j--;
		}
	}
	else {
		int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
		int i, j;
		for (i = 0; i < 25; i++)
		{
			printf("I'm prime %d\n", primes[i]);
			j = 800000;
			while (j != 0)
				j--;
		}
	}

	return ALL_IS_OK;
}

int main(void)
{
	void *status;
	pthread_t writer1_pid, writer2_pid, writer3_pid;
	pthread_create(&writer1_pid, NULL, writer, (void *)mess[0]);
	pthread_create(&writer2_pid, NULL, writer, (void *)mess[1]);
	pthread_create(&writer3_pid, NULL, writer, (void *)mess[2]);
	pthread_join(writer1_pid, &status);
	if (status == ALL_IS_OK)
		printf("Thread %lx completed ok.\n", writer1_pid);	
	pthread_join(writer2_pid, &status);
	if (status == ALL_IS_OK)
		printf("Thread %lx completed ok.\n", writer2_pid);
	pthread_join(writer3_pid, &status);
	if (status == ALL_IS_OK)
		printf("Thread %lx completed ok.\n", writer3_pid);
	return 0;
}