#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node* list_pointer;
struct node {
	char data[4];
	struct node* link;
};
struct node* ptr = NULL;
ptr = (struct node*)malloc(sizeof(struct node));

void insert(struct node** ptr, struct node* before) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n"); exit(1);
	}
	temp->data = 50;
	if (*ptr) {
		temp->link = before->link;
		before->link = temp;
	}
	else {
		temp->link = NULL; *ptr = temp;
	}
}

void delete(list_pointer* ptr, list_pointer before, list_pointer A) {
	if (before)
		before->link = A->link;
	else
		*ptr = *ptr->link;
	free(A);
}