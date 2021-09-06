#include "element.h"


void quicksort(element list[], int left, int right) {
	int pivot, i, j;
	int show;
	element temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = list[left].key;

		do {
			do {		// 왼쪽부터 pivot보다 크거나 같은 키를 검색
				i++;
			} while (list[i].key < pivot);
			do {		// 오른쪽부터 pivot보다 작거나 같은 키를 검색
				j--;
			} while (list[j].key > pivot);
			if (i < j)
				SWAP(list[i], list[j], temp);
		} while (i < j);
		SWAP(list[left], list[j], temp);
		quicksort(list, left, j - 1);	// 왼쪽 리스트를 다시 정렬
		quicksort(list, j + 1, right);	// 오른쪽 리스트를 다시 정렬
	}
}