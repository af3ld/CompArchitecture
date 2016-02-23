#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int value;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct {
    int count;
    node *first;
    node *last;
} List;

Node* newNode(int x);

void insertFront(int x);

void insertRear(int x);