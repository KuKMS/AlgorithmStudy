#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001
typedef struct Node {
	Node* next;
	Node* prev;
	int data;
}Node;

typedef struct Deque {
	Node* front;
	Node* rear;
	int size;
}Deque;

void init_dq(Deque* dq){
	dq->front = NULL;
	dq->rear = NULL;
	dq->size = 0;
	return;
}

int isempty_dq(Deque* dq) {
	if (dq->size == 0) return 1;
	else return 0;
}

void pushf_dq(Deque* dq, int data) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	if (isempty_dq(dq)) {
		dq->front = newnode;
		dq->rear = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else {
		dq->front->prev = newnode;
		newnode->next = dq->front;
		newnode->prev = NULL;
		dq->front = newnode;
	}
	dq->size++;
}

void pushr_dq(Deque* dq, int data) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	if (isempty_dq(dq)) {
		dq->front = newnode;
		dq->rear = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else {
		dq->rear->next = newnode;
		newnode->prev = dq->rear;
		newnode->next = NULL;
		dq->rear = newnode;
	}
	dq->size++;
}

int popf_dq(Deque* dq) {
	Node *target = dq->front;
	int n;
	if (isempty_dq(dq)) return -1;
	else {
		n = target->data;
		if (dq->front->next == NULL) {
			dq->front = NULL;
			dq->rear = NULL;
		}
		else {
			dq->front = dq->front->next;
			dq->front->prev = NULL;
		}
		free(target);
		dq->size--;
		return n;
	}
}

int popr_dq(Deque* dq) {
	Node *target = dq->rear;
	int n;
	if (isempty_dq(dq)) return -1;
	else {
		n = target->data;
		if (dq->rear->prev == NULL) {
			dq->front = NULL;
			dq->rear = NULL;
		}
		else {
			dq->rear = dq->rear->prev;
			dq->rear->next = NULL;
		}
		free(target);
		dq->size--;
		return n;
	}
}
void clr_dq(Deque* dq) {
	while (dq->size > 0) {
		popf_dq(dq);
	}
}

void traversef_dq(Deque* dq) {
	Node* n = dq->front;
	printf("[");
	while (n != NULL) {
		printf("%d", n->data);
		n = n->next;
		if (n != NULL) printf(",");
	}
	printf("]\n");
}

void traverser_dq(Deque* dq) {
	Node* n = dq->rear;
	printf("[");
	while (n != NULL) {
		printf("%d", n->data);
		n = n->prev;
		if (n != NULL) printf(",");
	}
	printf("]\n");
}