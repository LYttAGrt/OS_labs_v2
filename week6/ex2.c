#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int main(){
	char str1[] = "Lopen ipsum blabla";
	char* str2 = (char*) malloc(sizeof(char) * 32);
	char buf[32]; 
	pthread_t threads[4];
	
	// fill buffer
	int i=0;
	for(;i<sizeof(buf)*sizeof(char);i++){
		buf[i] = str1[i];
	}
	
	// pipe[0]: reading, pipe[1]: writing
	int pb[2];
	pipe(pb);	
	write(pb[1], buf, sizeof(buf) * sizeof(char));
	
	int id = fork();
	if (id==0){
		printf("Success\n");
		read(pb[0], str2, sizeof(buf) * sizeof(char));
		printf("%s%s\n%s%s\n", "Line 1: ", str1, "Line 2: ", str2);
	} else return 1;
	return 0;
}

