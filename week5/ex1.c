#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* threadIntro(void* id){
	// parse input
	int step = *((int*) id);
	// print some text
	printf("%s%d%s%d%s","Thread # ", (int) pthread_self(), " on step ", step, "\n");
	// exit
	pthread_exit(NULL);
}

int main(){
	// OK. Read input param N:
	char inputN[2];
	fgets(inputN, 2, stdin);
	int i, n;
	n = atoi(inputN);

	// and build N threads:
	pthread_t threads[n];
	int thread_code;
	void (*fptr)(void*);
	fptr = &threadIntro;
	for(i=0;i<n;i++){
		thread_code = pthread_create(&threads[i], NULL, &threadIntro, (void*) &i);
		if(thread_code){
			printf("%s\n", "Not success!");
		} else {
			printf("Thread # %d : new thread %d on step %d\n", (int) pthread_self(), (int) threads[i], i);
		}
		sleep(1);
	}
	return 0;
	
	// Two variants now. Either I didn't get the task or it's already fixed to be sequential
}
