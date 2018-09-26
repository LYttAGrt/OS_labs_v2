#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char str1[] = "Lopen ipsum blabla";
	char str2[32];
	char buf[32];
	
	// pipe[0]: reading, pipe[1]: writing
	int pb[2];
	pipe(pb);	
	
	// Buffer - two more lines. Suppose buffer exists
	write(pb[1], str1, sizeof(buf) * sizeof(char));
	read(pb[0], str2, sizeof(buf) * sizeof(char));
	
	printf("%s%s\n%s%s\n", "Line 1: ", str1, "Line 2: ", str2);
	return 0;
}

