#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h> 

void handler(int signal){
	printf("Stopped!");
}

int main(){
	// create subprocess
	int pid = fork();
	system("touch local.txt");
	system("cat /dev/urandom > local.txt");
	// press Ctrl + C here
	signal(SIGTERM, handler);
	
	// get first 20 symbols (actually, 20 + 1 since of \0 hitting chance)
	FILE * ptr = fopen("local.txt", "r");
	char buf[255];
	fgets(buf, 21, ptr);
	
	// print it and close
	printf("%s", buf);
	fclose(ptr);
	system("rm local.txt");
	return 0;
}
