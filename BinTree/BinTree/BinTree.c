#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node* tree_pointer;
struct node {
	int data;
	tree_pointer left_child, right_child;
};