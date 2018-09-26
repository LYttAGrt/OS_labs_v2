#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalHandler(int);

int main(){
	int pid = fork();
	// 3 secs instead of 10
	sleep(3);
	if (pid==0){
		signal(SIGTERM, signalHandler);
		printf("I'm alive!\n");
		while(1){
			printf("Aha-ha-ha-ha-ha!");
		}
	}
	return 0;
}

void signalHandler(int signal){
	if(signal==SIGKILL){
		kill(getpid(), SIGKILL);
	}
}

