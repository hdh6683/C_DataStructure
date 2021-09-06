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