#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define compare(x,y)(((x)<(y))?-1:((x)==(y))?0:1)
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int binsearch(int list[], int searchnum, int left, int right) {
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum)) {
		case -1:
			return binsearch(list, searchnum, middle + 1, right);
		case 0:
			return middle;
		case 1:
			return binsearch(list, searchnum, left, middle - 1);
		}
		return -1;
	}
}

int main() {
	int i, j, list[100], min, temp;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		list[i] = rand() % 1000;
	}

	for (i = 0; i < 99; i++) {
		min = i;
		for (j = 1; j < 100; j++) {
			if (list[j] < list[min])
				min = j;
		}
		SWAP(list[i], list[min], temp);
	}

	printf("%d\n",binsearch(list, 69, 0, 99));
}