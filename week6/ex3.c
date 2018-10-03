#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signalhandler(int);

int main(){
	signal(SIGINT, signalhandler);
	printf("Have I been interrupted?\n");
	while(1){
		printf("Maybe now?\n");
		sleep(1);
	}
	return 0;
}

void signalhandler(int signal){
	printf("%s%d\n%s", "Signal found: ", signal, "Thanks to firefox");
	exit(1);
}
