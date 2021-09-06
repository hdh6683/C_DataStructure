#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node* tree_pointer;
struct node {
	int	data;
	tree_pointer	left_child, right_child;
};

// Recursive Search
tree_pointer search(tree_pointer root, int key) {
	if (!root)return NULL;
	if (key == root->data)return root;
	if (key < root->data)
		return search(root->left_child, key);
	return search(root->right_child, key);
}

// Iterative Search

tree_pointer search2(tree_pointer tree, int key) {
	while(tree)	{
		if (key == tree->data)return tree;
		if (key < tree->data)
			tree = tree->left_child;
		else
			tree = tree->right_child;
	}
	return NULL;
}

void insert_node(tree_pointer* root, int num) {
	tree_pointer ptr, temp = modified_search(*root, num);

	if (temp || !(*root)) {
		ptr = (tree_pointer)malloc(sizeof(struct node));
		if (IS_FULL(ptr)) {
			fprintf(stderr, "The memory is full\n"); exit(1);
		}
		ptr->data = num;
		ptr->left_child = ptr->right_child = NULL;

		if (*root)
			if (num < temp->data)temp->left_child = ptr;
			else temp->right_child = ptr;
		else *root = ptr;
	}
}