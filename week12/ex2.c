#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

int tee(char* args[]){
	int args_length = malloc_usable_size(args);
	// ok, i understand what do i need to do:
	// to make a buffer, to parse the arguments, to call a system()
	// good. but too much low-level.
	//
	// variant 2: very lazy
	char cmd[args_length + 4];
	int counter = 0, ptr_i = 0;
	for(int i=0; i<args_length; i++){
		if(args[counter][ptr_i] != NULL){
			cmd[i+4] = args[counter][ptr_i];
			ptr_i += 1;	
		} else {
			counter += 1;
			ptr_i = 0;
		}
	} 
	cmd[0] = 't';
	cmd[1] = 'e';
	cmd[2] = 'e';
	cmd[3] = ' ';
	int id = system(cmd);
	return id;
}

int main(int argc, char* args[]){
	tee(args);
	return 0;
}
