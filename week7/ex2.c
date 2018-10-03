#include <stdio.h>
#include <stdlib.h>

int main(){
	// get N
	char inputLine[2];
	fgets(inputLine, 3, stdin);
	int i, n;
	n =	atoi(inputLine);
	
	printf("%s%d%s", "Input is: ", n, "\n"); 
	
	// declare array
	int* arr = (int*) malloc(sizeof(int)*n);
	
	// fill it
	for(i=0; i<n; i++){
		arr[i] = i;
	}
	
	// print it
	for(i=0; i<n; i++){
		printf("%d%s", arr[i], " ");
	}
	
	// free it
	free(arr);
	return 0;
}
