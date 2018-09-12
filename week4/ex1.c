#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 13;
	int id = fork();
	if (id>0){
		printf("Hello from parent %d\n", getppid() - n);
	} else if (id==0){
		printf("Hello from child %d\n", getpid() - n);
	} else return 1;
	return 0;
}
