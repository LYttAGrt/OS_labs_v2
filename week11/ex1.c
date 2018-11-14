#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <sys/mman.h>

int main(){
	// open file. Random string was a "Fourteen units shot"
	// For the future - deal cases with different sizes. But not this time    
	char* filename = "ex1.txt";
	int opened_res = open(filename, O_RDWR);
	if(opened_res == -1){
		perror(filename);
		exit(1);
	}
	
	// get stats data
	struct stat file_stats;
	int st = stat(filename, &file_stats);
	size_t file_size = file_stats.st_size;
	const char* new_data = "This is a nice day!";
	int new_data_size = strlen(new_data);
	printf("%lu\n%lu\n", file_size, new_data_size);
		
	// then, map it
	void* map_res = (char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, opened_res, 0);
	memcpy(map_res, (const void*) new_data, new_data_size);
	
	// finally, let all free. Viva la libertad!
	munmap(map_res, file_size);
	return 0;
}
