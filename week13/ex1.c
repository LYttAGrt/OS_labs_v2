#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){
	FILE * fptr;
	char * filename = "input_ex1.txt";
	// These 2 constants define all matrices, be advised
	int processes_number = 5;
	int resources_number = 3;
	
	// Open file
	int ex_res[resources_number];
	int av_res[resources_number];
	int c_matrix[processes_number][resources_number];
	int r_matrix[processes_number][resources_number];
	char str[64];
	int buf, size;
	fptr = fopen(filename, "r");
	
	// Read input, fill matrices
	int counter=0, i=0, j=0;
	while( (size = fscanf(fptr, "%s", str)) != EOF){
		buf = atoi(str);
		// Choose matrix, fill selected one
		if(counter < resources_number){
			ex_res[counter] = buf;
		} else if(counter < 2*resources_number){
			av_res[counter - resources_number] = buf;
		}	else if(counter < 2*resources_number + processes_number*resources_number){
			size = counter - 2*resources_number;
			j = size % resources_number;
			i = (size - j) % processes_number;
			c_matrix[i][j] = buf;
		} else if(counter < 2*resources_number + 2*processes_number*resources_number){
			size = counter - 2*resources_number - processes_number*resources_number;
			j = size % resources_number;
			i = (size - j) / resources_number;
			r_matrix[i][j] = buf;
		}
		counter += 1;
	}
	
	// Before the start, check if current resources are valid
	for(i=0; i<resources_number; i++){
		counter = 0;
		for(j=0; j<processes_number; j++)
			counter += c_matrix[j][i];
		counter += av_res[i];
		if(counter > ex_res[i]){
			printf("Error: missing resources used");
			exit(1);
		}
	}
	
	/* Now, let's detect. General idea is the following: 
	On each step, ALL processes that can be provided with resources, will get it and execute. After, resources will be returned.
	This step will be repeated (number of processes) times, as worst-case says.
	*/ 
	int detected_mask[processes_number];
	for(i=0;i<processes_number;i++)
		detected_mask[i]=0;
	int k=0, can_be_satisfied=1;
	
	for(k=0; k<processes_number; k++){
		for(i=0; i<processes_number; i++){
			// Check if process can be shared with resources
			for(j=0; j<resources_number; j++){
				if(r_matrix[i][j] > av_res[j]){
					can_be_satisfied=0;	
					detected_mask[i]=1;
					break;
				}
			}
			// If so, share
			if(can_be_satisfied){
				for(j=0; j<resources_number; j++){
					// provide resources
					av_res[j] -= r_matrix[i][j];
					c_matrix[i][j] += r_matrix[i][j];
					r_matrix[i][j] = 0;		
					// kill the process
					av_res[j] += c_matrix[i][j];
					c_matrix[i][j] = 0;
				}
				// Remove it from WANTED list
				detected_mask[i] = 0;
			}
			can_be_satisfied = 1;
		}
		// Repeat. If this situation stays till the end -> oops, deadlock.
		// Show, who is wanted if necessary 
		printf("%s %d %s", "Processes waiting on step", k, ": ");
		for(i=0; i<processes_number; i++)
			printf("%d ", detected_mask[i]);
		printf("\n");
	}

	// Then, print the result
	counter=0;
	printf("DEADLOCK PROCESSES: ");
	for(i=0; i<processes_number; i++){	
		if(detected_mask[i]){
			printf("look on waiting processes at step 0\n");
			break;
		} else counter += 1;
	}
	if(counter==processes_number) printf("noone\n");
	return 0;
} 
