#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *prev;
	struct Node *next;
} Node;


Node *firstNode;
Node *copy;

// creates new node
// TODO: remember to free the memory as currently causes a mem leak
Node newNode(int x);

// inserts node into front of list
void insertFront(int x);

// Prints list in ascending order
void printListAscending(char input);

void printListDescending(char input);

// sorts the linked list
void sort(int length);


