#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h"



Node* creatNewNode(int x) {
	Node* newNode = (Node*) malloc( sizeof(Node));
	newNode->value = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertFront(int x) {
	Node *newNode = creatNewNode(x);
	if (firstNode == NULL) {
		firstNode = newNode;
		return;
	}
	firstNode->prev = newNode;
	newNode->next = firstNode;
	firstNode = newNode;
}


void printList(int toggle) {
	struct Node *tempNode = firstNode;
	if (tempNode == NULL) {
		printf("The list is empty\n");
		return;
	} else {
		switch (toggle) {
		case REVERSE:
			while (tempNode != NULL) {
				printf("%d\n", tempNode->value);
				tempNode = tempNode->next;
			}
		case FORWARD:
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			while (tempNode != NULL) {
				printf("%d\n", tempNode->value);
				tempNode = tempNode->prev;
			}
		}
	}
}

void sort(int length) {
	int temp, i, j;
	struct Node *currentNode, *tempNode;
	if (currentNode == NULL) {
		printf("The list is empty\n");
		return;
	}
	for (j = 0 ; j < length; j++) {
		currentNode = firstNode;
		for (i = 0; i < length - 1 - j; i++) {
			if (currentNode->value > currentNode->next->value) {
				temp = currentNode->value;
				currentNode->value = currentNode->next->value;
				currentNode->next->value = temp;
			}
		tempNode = currentNode;
        currentNode = currentNode->next;
		}
	}
}


