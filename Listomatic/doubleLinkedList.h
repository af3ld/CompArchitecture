#include <stdio.h>
#include <stdlib.h>
#define REVERSE 0
#define FORWARD 1

typedef struct {
	int value;
	struct Node *prev;
	struct Node *next;
} Node;


Node* firstNode;

// creates new node
Node* newNode(int x);

// inserts node into front of list
void insertFront(int x);

// inserts node into rear of list
void insertRear(int x);

// Prints list in forward or reverse order
// depending on toggle
void printListInRegOrder(int toggle) ;