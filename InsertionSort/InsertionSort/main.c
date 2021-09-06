#include <stdio.h>
#include "element.h"

int main() {
	element list[] = { 26,5,37,1,61,11,59,15,48,19 };
	quicksort(list, 0, 9);
	for (int show = 0; show < sizeof(list) / sizeof(element); show++) {
		printf("%d ", list[show].key);
	}

	list[] = { 26,5,37,1,61,11,59,15,48,19 };

	return 0;
}