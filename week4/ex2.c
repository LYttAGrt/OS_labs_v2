#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int pid;
	for(int i=0; i<3; i++){
		pid=fork();
		printf("%d\n", pid);
		sleep(3);
	}
}
