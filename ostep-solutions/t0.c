#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

static int data = 0;

void *handle_thread(void* arg) {
	printf("Thread %c Is Running\n", (char*) arg);
	data += 1;
}

int main(int argc, char* argv[]) {
	pthread_t thread_1;
	pthread_t thread_2;
	
	int thread_err;
	
	thread_err = pthread_create(&thread_1, NULL, &handle_thread, "A");
	if (thread_err != 0) {
		exit(EXIT_FAILURE);
	}

	thread_err = pthread_create(&thread_2, NULL, &handle_thread, "B");
	if (thread_err != 0) {
		exit(EXIT_FAILURE);
	}

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

	printf("Static Data: %d\n", data);
	
	printf("Finish work from Main Thread\n");

	return 0;
}
