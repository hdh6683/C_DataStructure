#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int key;
	// 다른 field값들
}element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty(void) {
	if (top < 0)
		return 1;
	else
		return 0;
}

int isFull(void) {
	if (top >= MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void add(element item) {
	if (isFull()) {
		printf("Stack Full.\n");
		return;
	}
	stack[++top] = item;
}

element delete() {
	if (isEmpty()) {
		printf("Stack Empty.\n");
		return;
	}
	return stack[top--];
}