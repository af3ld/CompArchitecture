#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"



Node* newNode(int x) {
	struct Node* newNode = (struct Node*)
	                       malloc(sizeof(struct Node));
	newNode->value = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertFront(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}


void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}



void pop(List *list)
{

	Node *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}


