#include <stdio.h>
#include <stdlib.h>
#include "task2.h"

int main(){
	int arrLength = 6;
	// make an array
	int* arrPtr = (int*) malloc(sizeof(int)*arrLength);
	int array[arrLength];
	*array = *arrPtr;
	// stupid, but works
	array[0] = 5;
	array[1] = 8;
	array[2] = 3;
	array[3] = 6;
	array[4] = 9;
	array[5] = 8;
	
	// print init array
	int i = 0;
	for(; i<arrLength; i++){
		printf("%d%c", array[i],' ');
	}
	printf("\n");	
	
	// sort
	bubble_sort(&array[0], arrLength);
	// print result
	i = 0;
	for(; i<arrLength; i++){
		printf("%d%c", array[i],' ');
	}
	
	return 0;
}
void bubble_sort(int* inputArr, int length){
	// standby
	int i, k;
	int support[length+1];
	for(i=0; i<length; i++){
		support[i] = *inputArr;
		inputArr += 1;
	}
	support[length] = 0;
	// sort
	for(i = 0; i < length; i++){
		for(k = 0; k < length; k++){
			if(support[i] > support[k]){
				support[length] = support[i];
				support[i] = support[k];
				support[k] = support[length];
			}
		}
	}

	// return the result
	inputArr -= length;
	for(i=0;i<length;i++){
		*inputArr = support[i];
		inputArr += 1;
	}
}


