#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigkillHandler(int);
void sigstopHandler(int);
void sigusr1Handler(int);

int main(){
	signal(SIGKILL, sigkillHandler);
	signal(SIGSTOP, sigstopHandler);
	signal(SIGUSR1, sigusr1Handler);
	
	printf("Have I been interrupted?\n");
	while(1){
		printf("Maybe now?\n");
		sleep(1);
	}
	return 0;
}

void sigkillHandler(int signal){
	printf("%s%d\n%s", "SIGKILL found: ", signal, "Thanks to firefox");
	exit(1);
}

void sigstopHandler(int signal){
	printf("%s%d\n%s", "SIGSTOP found: ", signal, "Thanks to firefox");
	exit(1);
}

void sigusr1Handler(int signal){
	printf("%s%d\n%s", "SIGUSR1 found: ", signal, "Thanks to firefox");
	kill(getpid(), SIGUSR1);
	exit(1);
}

