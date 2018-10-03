// If it works, than it's ok
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void signalHandler(int);

int main(){
	// Declare pipe  
	char buffer[32];
	int pb[2];
	pipe(pb);
	
	int pid2 = fork();	
	printf("%s%d\n", "PID 2: ", getpid());
	// Two kids should be alive, that's why IF is necessary
	if(pid2==0){
		// Push the id
		sprintf(buffer, "%s%d", buffer, getpid());
		write(pb[1], buffer, sizeof(buffer) * sizeof(char));
		
		int pid1 = fork();
		printf("%s%d\n", "PID 1: ", getpid());
		if(pid1==0){
			char str2[32];
			// Get it
			read(pb[0], buffer, sizeof(buffer) * sizeof(char));
			
			sleep(2);
			// Set listener.. i guess so
			signal(SIGSTOP, signalHandler);
			
			// Update the pipe
			sprintf(buffer, "%s%d", buffer, getpid());
			write(pb[1], buffer, sizeof(buffer) * sizeof(char));	
		}
		read(pb[0], buffer, sizeof(buffer) * sizeof(char));	
		printf("%s%s", "Final value: ", buffer);
	}
	
	return 0;	
}

void signalHandler(int sig){
	if(signal==SIGSTOP){
		exit(1);
	}
}

