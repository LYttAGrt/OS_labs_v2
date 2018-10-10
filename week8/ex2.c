#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEN_MB 1024*1024*10

int main(){
	int i=0, n=10;
	void* ptr[n];
	for(;i<n;i++){
		ptr[i] = malloc(TEN_MB);
		memset(ptr[i], 0, TEN_MB);
		printf("%s%d%s", "Allocated ", TEN_MB*i, " bytes\n");
		sleep(1);
	}
	return 0;
}
