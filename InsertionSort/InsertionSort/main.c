#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "element.h"

element list[LIST_SIZE];
element list1[LIST_SIZE];
element list2[LIST_SIZE];
element list3[LIST_SIZE];
element list4[LIST_SIZE];
element list5[LIST_SIZE];

void show_list(element* list_pointer) {
	int show;
	for (show = 0; show < LIST_SIZE; show++) {
		printf("%d ", list_pointer[show].key);
	}
}

int main() {
	clock_t start, end;
	int i;
	srand(time(NULL));

	for (i = 0; i < LIST_SIZE; i++) {
		list[i].key = rand() % LIST_SIZE + 1;
	}


	for (i = 0; i < LIST_SIZE; i++) {
		list1[i].key = list[i].key;
	}
	start = clock();
	quicksort(list1, 0, LIST_SIZE);
	end = clock();
	float time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Quick Sort 소요된 시간 : %.3f\n", time);


	for (i = 0; i < LIST_SIZE; i++) {
		list2[i].key = list[i].key;
	}
	start = clock();
	merge_sort(list2, LIST_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Merge Sort 소요된 시간 : %.3f\n", time);


	for (i = 0; i < LIST_SIZE; i++) {
		list3[i].key = list[i].key;
	}
	start = clock();
	insertion_sort(list3, LIST_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Insertion Sort 소요된 시간 : %.3f\n", time);


	for (i = 0; i < LIST_SIZE; i++) {
		list4[i].key = list[i].key;
	}
	start = clock();
	heapsort(list4, LIST_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Heap Sort 소요된 시간 : %.3f\n", time);


	for (i = 0; i < LIST_SIZE; i++) {
		list5[i].key = list[i].key;
	}
	start = clock();
	selection_sort(list5, LIST_SIZE);
	end = clock();
	time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Selection Sort 소요된 시간 : %.3f\n", time);

	return 0;
}