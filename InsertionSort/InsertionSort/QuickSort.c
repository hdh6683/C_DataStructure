#include "element.h"


void quicksort(element list[], int left, int right) {
	int pivot, i, j;
	int show;
	element temp;
	if (left < right) {
		i = left; j = right + 1;
		pivot = list[left].key;

		do {
			do {		// ���ʺ��� pivot���� ũ�ų� ���� Ű�� �˻�
				i++;
			} while (list[i].key < pivot);
			do {		// �����ʺ��� pivot���� �۰ų� ���� Ű�� �˻�
				j--;
			} while (list[j].key > pivot);
			if (i < j)
				SWAP(list[i], list[j], temp);
		} while (i < j);
		SWAP(list[left], list[j], temp);
		quicksort(list, left, j - 1);	// ���� ����Ʈ�� �ٽ� ����
		quicksort(list, j + 1, right);	// ������ ����Ʈ�� �ٽ� ����
	}
}