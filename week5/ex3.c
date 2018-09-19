#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

unsigned int count;

// Copypasted from lyttagrt
int main(){
	// OK. Read input param N and build N threads:
	char inputN[2];
	fgets(inputN, 2, stdin);
	int i, n;
	n = atoi(inputN);
	pthread_t threads[n];
	
	count = 0;
	// sorry, out of time
	
	return 0;
}

void* threadIntro(void* id){
	// parse input
	int step = *((int*) id);
	// print some text
	printf("%s%d%s%d%s","Thread # ", (int) pthread_self(), " on step ", step, "\n");
	// exit
	pthread_exit(NULL);
}

void m_sleep(){}

void m_wakeup(){}
