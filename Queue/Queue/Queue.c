#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_Q_SIZE 100

typedef struct {
	int key;
	// 다른 field값들
}element;
element queue[MAX_Q_SIZE];
int rear = -1, front = -1;

int isEmpty() {
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull() {
	if (rear == MAX_Q_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void add(element item) {
	if (isFull()) {
		printf("Queue Full.\n");
		return;
	}
	else {
		queue[++rear] = item;
	}
}

element delete() {
	if (isEmpty()) {
		printf("Queue Empty.\n");
		return;
	}
	else {
		return queue[++front];
	}
}