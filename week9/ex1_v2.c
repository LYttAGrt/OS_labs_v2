#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>

typedef struct PageTable {
	int tableSize;
	int * pageNumbers;
	int * rCounters;
} Page_Table;

int update_r_counter(int old_counter, int add_value, int max_value);
int execute_aging_algo(Page_Table* ptPtr, int tableSize, int nextPage);

int main(){
	// get input param
	printf("%s", "Enter page_frames number: ");
	char inputParam[4], inputVar[4];
	fgets(inputParam, 5, stdin);
	int page_frames =	atoi(inputParam);
	
	// get variant to test (0, 1, 2)
	printf("%s", "Enter test variant: ");
	fgets(inputVar, 3, stdin);
	int test_variant = atoi(inputVar);
	test_variant = test_variant % 3;
	printf("%s%d%s", "Test variant (0 for 10, 1 for 50, 2 for 100): ", test_variant, "\n");
	
	// open input file
	FILE *fptr = fopen("/home/alex/OS_labs/week9/Lab_09_input.txt", "r");
	// choose subsequence
	int i, counter;
	switch(test_variant){
		case 1:
			counter = 50;
			break;	
		case 2:
			counter = 100;
			break;
		default:
			counter = 10;
			break;
	}
	// for simplicity, put file data to some buffer first
	char buffer[16];
	int file_data[counter];
	for(i = 0; i < counter; i++){
		fscanf(fptr, "%s", buffer);
		file_data[i] = atoi(buffer);
	}
	
	// initialize page table via malloc()
	int* pages = (int*) malloc(sizeof(int) * page_frames);
	int* rBits = (int*) malloc(sizeof(int) * page_frames);
	for(i = 0; i < counter; i++){
		pages[i] = -1;
		rBits[i] = 0;
	}
	Page_Table actual_page_table;
	actual_page_table.pageNumbers = pages;
	actual_page_table.rCounters = rBits;
	
	// then, execute aging algo
	int hit = 0, miss = 0, res;
	Page_Table* tablePtr;
	for(i=0; i<counter; i++){
		tablePtr = &actual_page_table;
		res = execute_aging_algo(tablePtr, page_frames, file_data[i]);
		if(res){
			miss += 1;
		} else {
			hit += 1;
		}
	}
	printf("%s%d%s%d%s", "Hit/miss ratio: ", hit, "/", miss, "\n"); 
	fclose(fptr);
	return 0;
}

/* 
	ptPtr: link to the old table
	nextPage: what should be added
	tableSize: size of structure via ptPtr
*/
int execute_aging_algo(Page_Table* ptPtr, int tableSize, int nextPage){
	// 1. Copy input
	Page_Table pageTable = *ptPtr;
	int pageNumber, rCounter;
	
	// 2: check whether next_page is inside
	int i = 0, page_is_missed = 1;
	for(i = 0; i < tableSize; i++){
		pageNumber = pageTable.pageNumbers[i];
		if(pageNumber == nextPage){
			page_is_missed = 0;
			break;
		}
	}
	if(page_is_missed){
		// check whether free page frame exists => page_number == -1
		int no_free_space = 1;
		for(i = 0; i < tableSize; i++){
			pageNumber = pageTable.pageNumbers[i];
			if(pageNumber == -1){
				pageTable.pageNumbers[i] = nextPage;
				no_free_space = 0;
				break;
			}
		}
		
		if(no_free_space){
			// get min value of counters and its index
			int min_val = pageTable.rCounters[0], index_min = 0;
			for(i = 1; i < tableSize; i++){
				rCounter = pageTable.rCounters[i];
				if(rCounter < min_val){
					min_val = rCounter;
					index_min = i;
				}
			}
			// and new_buddy stands on the position of index_min
			pageTable.pageNumbers[index_min] = nextPage;
		}
	}
	
	// now - update R-counters.
	int max_value = pageTable.rCounters[0];
	for(i=1; i < tableSize; i++){
		rCounter = pageTable.rCounters[i];
		if(rCounter > max_value){
			max_value = rCounter;
		}
	}
	// then all counters should be updated like this: 
	// new_buddy.last_bit = 1, any_other.last_bit = 0
	int swapper, shifted_r_counter, add_val;
	for(i=0; i < tableSize; i++){
		rCounter = pageTable.rCounters[i];
		shifted_r_counter = rCounter >> 1;
		add_val = (pageTable.rCounters[i] == nextPage) ? 1 : 0;
		swapper = update_r_counter(shifted_r_counter, add_val, max_value);
		pageTable.rCounters[i] = swapper;
	}
	
	return page_is_missed;
}


/* 
	old_counter: old value of usage counter
	add_value: either 0 or 1
	max_value: in russian - нужен, чтобы учитывать нули в начале бинарного числа  
*/
int update_r_counter(int old_counter, int add_value, int max_value){
	// Get multiplier = power^2 such as max_value lays between some two powers.
	// Then, add it with old_counter
	int r_counter = old_counter, multiplier = 1, i = 0;
	for(; i < sizeof(int) * 8 - 1; i++){
		if((max_value > multiplier) && (max_value < multiplier*2)){
			r_counter += add_value*multiplier;
			break;
		} else {
			multiplier *= 2;
		}
	} 
	return r_counter;
}





