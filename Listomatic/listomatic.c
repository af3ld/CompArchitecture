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

int main() {
	Node node;
	int i, counter = 0;
	while (scanf("%d", &i) == 1) {
		insertFront(i);
		counter++;
	}
	intCounter(counter);
	sort(counter);
	// printList(FORWARD);
}