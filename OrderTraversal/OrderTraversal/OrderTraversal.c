#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node* tree_pointer;

struct node {
	int data;
	tree_pointer left_child, right_child;
};

void inorder(tree_pointer ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		print("%d", ptr->data);
		inorder(ptr->right_child);
	}
}

void preorder(tree_pointer ptr) {
	if (ptr) {
		printf("%d", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

void postorder(tree_pointer ptr) {
	if (ptr) {
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d", ptr->data);
	}
}

tree_pointer copy(tree_pointer original) {
	tree_pointer temp;
	if (original) {
		temp = (tree_pointer)malloc(sizeof(node));
		if (IS_NULL(temp)) {
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}
		temp->left_child = copy(original->left_child);
		temp->right_child = copy(original->right_child);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}

int equal(tree_pointer first, tree_pointer second) {
	return((!first && !second) || (first && second && (first->data == second->data)
		&& equal(first->left_child, second->left_child)
		&& equal(first->right_child, second->right_child)));
}