#include "element.h"

void selection_sort(element list[], int n) {
	int i, j, least;
	element temp;
	for (i = 0; i < LIST_SIZE - 1; i++) {
		least = i;
		for (j = i + 1; j < LIST_SIZE; j++) {
			if (list[least].key > list[j].key) {
				least = j;
			}
		}
		SWAP(list[i], list[least], temp);
	}
}