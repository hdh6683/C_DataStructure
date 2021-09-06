#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUES 10

typedef struct {
	int key;
	int value;
}element;

typedef struct queue* Qpointer;
struct queue {
	element item;
	Qpointer link;
};

Qpointer front[MAX_QUEUES], rear[MAX_QUEUES];

void addq(Qpointer* front, Qpointer* rear, element item) {
	Qpointer temp = (Qpointer)malloc(sizeof(struct queue));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->item = item;
	temp->link = NULL;
	if (*front) {
		(*rear)->link = temp;
	}
	else {
		*front = temp;
	}
	*rear = temp;
}

element deleteq(Qpointer* front) {
	Qpointer temp = *front;
	element item;
	if (IS_EMPTY(temp)) {
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}
	item = (*front)->item;
	*front = (*front)->link;
	free(temp);
	return item;
}