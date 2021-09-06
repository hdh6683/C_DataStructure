#ifndef ELEMENT_H
#define ELEMNET_H

#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x,y,t){t=x;x=y;y=t;}
#define MAX_SIZE 1000

typedef struct element {
	int key;
}element;

void merge(element list[], element sorted[], int i, int m, int n);
void quicksort(element list[], int left, int right);
void insertion_sort(element list[], int n);
int rmergeSort(element a[], int link[], int left, int right);

#endif ELEMENT_H