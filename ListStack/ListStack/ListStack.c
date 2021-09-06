#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK 10
typedef struct {
	int key;
	int value;
}element;

typedef struct stack* stack_pointer;

struct stack {
	element  item;
	stack_pointer link;
};

stack_pointer top[MAX_STACK];

void add(stack_pointer* top, element item) {
	stack_pointer temp = (stack_pointer)malloc(sizeof(struct stack));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->item = item;
	temp->link = *top;
	*top = temp;
}

element delete(stack_pointer* top) {
	stack_pointer temp = *top;
	element item;
	if (IS_EMPTY(temp)) {
		fprintf(stderr, "The stack is empty\n");
		exit(1);
	}
	item = (*top)->item;
	*top = (*top)->link;
	free(temp);
	return item;
}