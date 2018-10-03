#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

void* m_realloc(void* ptr, int new_size);

int main(){
	// testing a bit
	int length=4, i;
	int *ptr, *ptr2;
	ptr = (int*) malloc(sizeof(int)*length);
	for(i=0;i<length;i++){
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}
	printf("\n");
	
	length +=4;
	ptr2 = (int*) m_realloc(ptr, sizeof(int)*length);
	for(i=0;i<length;i++){
		printf("%d ", ptr2[i]);
	}
	return 0;
}

void* m_realloc(void* ptr, int new_size){
	// declare locals
	int old_length, i, k, min;
	// deal 4 cases
	void *new_ptr, *input_ptr;
	
	// return null or throw error
	if(ptr==NULL && new_size == 0)	new_ptr = NULL;
	
	// free memory
	if(ptr!=NULL && new_size == 0){
		free(ptr);
		new_ptr = ptr;
	}
	
	// provide some default
	if(ptr==NULL && new_size != 0)	new_ptr = malloc(new_size);
	
	if(ptr!=NULL && new_size != 0){
		
		old_length = malloc_usable_size(ptr);
		new_ptr = malloc(new_size);
		
		// copy elements, byte by byte
		min = (old_length <= new_size) ? old_length : new_size;
		memcpy(new_ptr, (void*) ptr, min);
		
		// clear memory
		free(ptr);
	}
	
	// finish and return	
	return new_ptr;
}

