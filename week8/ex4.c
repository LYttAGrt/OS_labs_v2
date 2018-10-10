#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define TEN_MB 1024*1024*10

int main(){
	int i=0, n=10, k=TEN_MB;
	void* ptr[n];
	struct rusage struct_ptr;
	for(;i<n;i++){
		ptr[i] = malloc(TEN_MB);
		memset(ptr[i], 0, TEN_MB);
		k = getrusage(RUSAGE_SELF, &struct_ptr);
		// Copypasted from http://www.cs.tufts.edu/comp/111/examples/Time/getrusage.c
		if(k==0){
			printf("user seconds without microseconds: %ld\n", struct_ptr.ru_utime.tv_sec); 
    	printf("user microseconds: %ld\n", struct_ptr.ru_utime.tv_usec); 
    	printf("total user seconds: %e\n", 
	  	 (double) struct_ptr.ru_utime.tv_sec + (double) struct_ptr.ru_utime.tv_usec / (double) 1000000); 
	  	printf("shared memory size, KB: %ld\n", struct_ptr.ru_maxrss);
		}
		//printf("%s%d%s", "Allocated ", TEN_MB*i, " bytes\n");
		sleep(1);
	}
	return 0;
}
