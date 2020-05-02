
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct Node2 {
	int data;
	int order;
	struct Node2 *next;
}Node2;

typedef struct Queue {
	Node *front;
	Node *rear;
	int size;
}Queue;

typedef struct Queue2 {
	Node2 *front;
	Node2 *rear;
	int size;
}Queue2;



void init(Queue *q);
int isempty(Queue *q);
void push(int data, Queue *q);
int pop(Queue *q);		//empty = -1 return
int ndata(Node *n);

void ppush(int data, Queue *q);

void init2(Queue2 *q);
int isempty2(Queue2 *q);
void push2(int data,int order, Queue2 *q);
int pop2(Queue2 *q);		//empty = -1 return
int order(Node2 *n);
int ndata2(Node2 *n);


Queue2 q;
Queue pq;

int main(void) {
	int t, n, m, h, i,tmp,x,y;
	int a[101] = { 0, };
	int o[101] = { 0, };
	scanf("%d", &t);
	for (h = 0; h < t; h++) {
		init2(&q);
		init(&pq);
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			push2(a[i],i, &q);
			ppush(a[i], &pq);
			o[i] = 0;
		}
		i = 0;
		while (isempty(&pq) == 0) {
			tmp = order(q.front);
			x = pop2(&q);
			y = pop(&pq);
			if (x==y) {
				o[i++] = tmp;
			}
			else {
				push2(x, tmp, &q);
				ppush(y, &pq);
			}

		}


		for (i = 0; i < n; i++) {
			if (o[i] == m) printf("%d\n",i+1);
		}
	}

}

void init(Queue *q) {
	q->front = q->rear = NULL;
	q->size = 0;
}
int isempty(Queue *q) {
	if (q->size == 0) return 1;
	else return 0;
}

void push(int data, Queue *q) {
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if (isempty(q) == 1) {
		q->front = n;
	}
	else {
		q->rear->next = n;
	}
	q->rear = n;
	q->size++;
	return;
}

int pop(Queue *q) {
	int a = 0;
	Node *n;
	if (isempty(q) == 1) { return -1; }
	n = q->front;
	a = n->data;
	q->front = n->next;
	free(n);
	q->size--;
	return a;
}
int ndata(Node *n) { return n->data;}


void ppush(int data, Queue *q) {
	Node *n = (Node *)malloc(sizeof(Node));
	Node *m, *o;
	n->data = data;
	n->next = NULL;
	if (isempty(q) == 1) {
		q->front = n;
	}
	else {
		m = q->front;
		o = NULL;
		while (m != NULL) {
			if (data >= ndata(m)) {
				if (q->front == m) {
					n->next = m;
					q->front = n;
				}
				else {
					o->next = n;
					n->next = m;
				}
				break;
			}
			else {
				o = m;
				m = m->next;
			}
		}
		if (m == NULL) {
			o->next = n;
			q->rear = n;
		}
	}
	q->size++;
	return;
}


void init2(Queue2 *q) {
	q->front = q->rear = NULL;
	q->size = 0;
}
int isempty2(Queue2 *q) {
	if (q->size == 0) return 1;
	else return 0;
}

void push2(int data,int order, Queue2 *q) {
	Node2 *n = (Node2 *)malloc(sizeof(Node2));
	n->data = data;
	n->order = order;
	n->next = NULL;
	if (isempty2(q) == 1) {
		q->front = n;
	}
	else {
		q->rear->next = n;
	}
	q->rear = n;
	q->size++;
	return;
}

int pop2(Queue2 *q) {
	int a = 0;
	Node2 *n;
	if (isempty2(q) == 1) { return -1; }
	n = q->front;
	a = n->data;
	q->front = n->next;
	free(n);
	q->size--;
	return a;
}

int order(Node2 *n) { return n->order; }
int ndata2(Node2 *n) { return n->data; }