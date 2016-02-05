#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node * next;
}
Node;

typedef struct Queue {
	Node *front;
	Node *rear;
	int size;
}
Queue;

void init(Queue *q) {
	q->front = malloc(sizeof(Node));
	q->rear = q->front;
	q->rear->next = NULL;
	q->size = 0;
}

void destroy(Queue *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	q->size = 0;
}

void push(Queue *q, int val) {
	q->rear->next = malloc(sizeof(Node));
	q->rear = q->rear->next;

	q->rear->val = val;
	q->rear->next = NULL;
	q->size++;
}

void pop(Queue *q) {
	if (q->front->next == q->rear) {
		free(q->rear);
		q->rear = q->front;
		q->rear->next = NULL;
	}
	else {
		Node *tmp = q->front->next;
		q->front->next = tmp->next;
		free(tmp);
	}
	q->size--;
}

int front(Queue *q) {
	return q->front->next->val;
}

int size(Queue *q) {
	return q->size;
}

void main() {
	Queue q;
	init(&q);
	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	for (int i = 0; i < 4; i++) {
		printf("%d %d\n", front(&q), size(&q));
		pop(&q);
	}
	destroy(&q);
}