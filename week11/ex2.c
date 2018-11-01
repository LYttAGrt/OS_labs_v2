#include <stdio.h>
#include <stdlib.h>

// what do you want in second task?
int main(){
	char buf[64];
	size_t length = 64;
	char* mword = "Hello";
	for(int i=0; i<5; i++){
		fprintf(stdout, "%c%s", mword[i], "\n");
		// buffer the output here
		setvbuf(stdout, buf, _IOLBF, length);
		sleep(1);
	}
	sleep(3);
	// print all in one moment
	fprintf(stdout, "%s", mword);
	
	return 0;
}

/*
	int length = 6;
	char* ara = "Hello";
	for(int i=0; i < length; i++){
		// line buffer - here
		printf("%c%s", ara[i], "\n");
		sleep(1);
	} 
	sleep(3);
	printf("%s", ara);
*/
