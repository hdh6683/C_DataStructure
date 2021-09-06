#include "element.h"

void adjust(element list[], int root, int n) {
	int rootkey = list[root].key, child = 2 * root;
	element temp = list[root];

	while (child <= n) {
		if ((child < n) && (list[child].key < list[child + 1].key))
			child++;
		if (rootkey > list[child].key)
			break;
		else {
			list[child / 2] = list[child];
			child *= 2;
		}
	}
	list[child / 2] = temp;
}

void heapsort(element list[], int n) {
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(list, i, n);
	for (i = n; i > 0; i--) {
		SWAP(list[1], list[i], temp);
		adjust(list, 1, i - 1);
	}
}