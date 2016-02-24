#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"

void intCounter(int counter) {
	if (counter == 0)
		printf("Zero ints were entered\n");
	else if  (counter == 0)
		printf("1 int was entered\n");
	else
		printf("There were %d ints entered\n", counter);
}

void printArray(int size, int *arr) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}



int main() {
	Node *copyNode;
	int counter = 0;
	int i, *arr;
	while (scanf("%d", &i) == 1) {
		insertFront(i);
		counter++;
	}
	intCounter(counter);
	sort(counter);
	printList(REVERSE, 'o');
	printList(FORWARD, 'o'); //calls sorted orignal
	printList(FORWARD, 'c'); //calls copy
	
	// printArray(counter, arr);
}