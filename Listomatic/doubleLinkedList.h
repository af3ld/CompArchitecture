#include <stdio.h>
#include <stdlib.h>
#define REVERSE 0
#define FORWARD 1

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

// Prints list in forward or reverse order
// depending on toggle
void printList(int toggle, char input);

// sorts the linked list
void sort(int length);


