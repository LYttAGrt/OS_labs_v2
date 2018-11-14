#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <sys/mman.h>

// Looks like it is necessary to check the size of both files in order to avoid smth like 
// (not enough space, segmantation fault). One of the solutions - malloc enough space and 
// provide it to the file. This time - make it easier and fill the dst file initially.  

int main(){
	struct stat file_stats;
	size_t file_size_src, file_size_dst;
	int opened_src, opened_dst;
	int src_size, dst_size;
	char *map_src, *map_dst;
	char* src_name = "ex1.txt", *dst_name = "ex1_memcpy.txt";
	
	// Open and map source file
	opened_src = open(src_name, O_RDWR);
	stat(src_name, &file_stats);
	src_size = file_stats.st_size;
	if(opened_src == -1 || src_size == 0){
		perror(src_name);
		exit(1);
	}
	map_src = mmap(NULL, src_size, PROT_READ, MAP_SHARED, opened_src, 0);
	if(map_src == MAP_FAILED){
		perror("src map failed");
	}
	
	// Open and map destination file 
	opened_dst = open(dst_name, O_RDWR);
	stat(dst_name, &file_stats);
	dst_size = file_stats.st_size;
	if(opened_dst == -1){
		perror(dst_name);
		exit(1);
	}
	// Since we need to copy the stuff, we don't actually care about dst-file size
	map_dst = mmap(NULL, src_size, PROT_READ | PROT_WRITE, MAP_SHARED, opened_dst, 0);
	if(map_dst == MAP_FAILED){
		perror("dst map failed");
	}	
	
	printf("%d %d", src_size, dst_size);
	int act_size = (dst_size < src_size) ? dst_size : src_size;
	memcpy((void*) map_dst, (const void*) map_src, act_size);
	
	munmap(map_src, src_size);
	munmap(map_dst, dst_size);
	return 0;
}
