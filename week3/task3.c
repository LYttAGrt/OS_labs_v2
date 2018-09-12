#include <stdio.h>
#include <stdlib.h>
#include "task3.h"

typedef struct Node{
	struct Node *next;
	int data;
} Node;

typedef struct LinkedList {
	Node head;
	int size;
} SLL;

int main(void){
	// 1. Create the head of list
	Node* mHead = (Node*) malloc(sizeof(Node));
	(*mHead).next = NULL;
	(*mHead).data = 0;
	// 2. Create a list: add a head
	SLL* myList = (SLL*) malloc(sizeof(SLL));
	myList->head = *mHead;
	myList->size = 0;
	printf("%s\n", "List created");
	// 3. Have fun
	insert_node(myList, 5);
	insert_node(myList, 4);
	print_list(myList);
	return 0;
}

void insert_node(SLL *thisList, int new_guy){
	Node position = (*thisList).head; 
	int i = 0;
	// move to the end
	while(position.next != NULL){
		position = *(position.next);
		i += 1;
	}
	printf("%s%d%s", "Moved ", i, " times\n");
	// add new Node
	Node* new_buddy = (Node*) malloc(sizeof(Node));
	(*new_buddy).next = NULL;
	(*new_buddy).data = new_guy;
	position.next = new_buddy;
	thisList->size += 1;
	printf("%d%s%d%s", position.next, " ", new_buddy, " new address\n");
	printf("%s%d%s%d%s", "Added ", (*new_buddy).data, ", current size: ", thisList->size, "\n");
}

void print_list(SLL *thisList){
	Node pos = (*thisList).head;
	Node* ptr = pos.next;
	printf("%d", ptr);
  while(ptr != NULL){
		pos = *ptr;
		printf("%d%c", pos.data, ' ');
		ptr = pos.next;
		printf("%d", ptr);
	}
}

