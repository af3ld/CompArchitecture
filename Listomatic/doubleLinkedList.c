#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"



Node* newNode(int x) {
	Node* newNode = (struct Node*)
	                malloc(sizeof(struct Node));
	newNode->value = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertFront(int x) {
	Node* newNode = GetNewNode(x);
	if (firstNode == NULL) {
		firstNode = newNode;
		return;
	}
	firstNode->prev = newNode;
	newNode->next = firstNode;
	firstNode = newNode;
}

void insertRear(int x) {
	Node* temp = firstNode;
	Node* newNode = GetNewNode(x);
	if (firstNode == NULL) {
		firstNode = newNode;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}


void printList(int toggle) {
	struct Node* temp = firstNode;
	if (temp == NULL) {
		printf("The list is empty\n");
		return;
	} else {
		switch (toggle) {
		default:
			printf("Printing in regular order: ")
			while (temp != NULL) {
				printf("%d ", temp->data);
				temp = temp->next;
			}
		case REVERSE:
			while (temp->next != NULL) {
				temp = temp->next;
			}
			printf("Printing in reverse order: ")
			while (temp != NULL) {
				printf("%d ", temp->data);
				temp = temp->prev;
			}
		}
		printf("\n");
	}
}


