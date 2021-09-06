#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

typedef struct poly_node* poly_pointer;
struct poly_node {
	int coef;
	int expon;
	poly_pointer link;
};

poly_pointer a, b, d;

poly_pointer padd(poly_pointer a, poly_pointer b)
{
	poly_pointer front, rear, temp;
	int sum;

	rear = (poly_pointer)malloc(sizeof(struct poly_node));
	if (IS_FULL(rear))
	{
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	front = rear;
	while(a&&b)
		switch (COMPARE(a->expon, b->expon)) {
		case -1://a 지수 < b 지수
			attach(b->coef, b->expon, &rear);
			b = b->link; break;
		case 0: //a 지수 == b 지수
			sum = a->coef + b->coef;
			if (sum)attach(sum, a->expon, &rear);
			a = a->link; b = b->link; break;
		case 1: // a 지수 > b 지수
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	for (; a; a = a->link)attach(a->coef, a->expon, &rear);
	for (; b; b = b->link)attach(b->coef, b->expon, &rear);
	rear->link = NULL;

	temp = front; front = front->link; free(temp);
	return front;
}

void attach(float coefficient, int exponent, poly_pointer* rear)
{
	poly_pointer temp;
	temp = (poly_pointer)malloc(sizeof(struct poly_node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->coef = coefficient;
	temp->expon = exponent;
	(*rear)->link = temp;
	*rear = temp;
}

//void erase(poly_pointer* ptr) {
//	poly_pointer temp;
//	while (*ptr) {
//		temp = *ptr;
//		*ptr = (*ptr)->link; free(temp);
//	}
//}
//
//poly_pointer get_node(void) {
//	poly_pointer node;
//	if (avail) {
//		node = avail;
//		avail = avail->link;
//	}
//	else {
//		node = (poly_pointer)malloc(sizeof(struct poly_node));
//		if (IS_FULL(node)) {
//			fprintf(stderr, "The memory is full\n");
//			exit(1);
//		}
//	}
//	return node;
//}
//
//void ret_node(poly_pointer ptr) {
//	ptr->link = avail;
//	avail = ptr;
//}