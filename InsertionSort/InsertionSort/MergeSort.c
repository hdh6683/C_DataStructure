#include "element.h"

element extra[MAX_SIZE];

void merge(element list[], element sorted[], int i, int m, int n) {
	int j = m + 1, k = i, t;

	while (i <= m && j <= n) {
		if (list[i].key <= list[j].key)
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > m) {
		for (t = j; t <= n; t++)
			sorted[k++] = list[t];
	}
	else {
		for (t = i; t <= m; t++)sorted[k++] = list[t];
	}
}

void merge_pass(element list[], element sorted[], int n, int length) {
	int i, j;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i + 2 * length - 1);

	if (i + length < n)	// 길이가 2*length보다 적게 남아있는 리스트들 병합
		merge(list, sorted, i, i + length - 1, n - 1);
	else{				// 하나의 리스트만 남아있는 경우
		for (j = i; j < n; j++)
			sorted[j] = list[j];
	}

}

void merge_sort(element list[], int n) {
	int length = 1;
	// extra는 크기가 커서 전역변수로 선언

	while (length < n) {
		merge_pass(list, extra, n, length);
		length *= 2;
		merge_pass(extra, list, n, length);
		length *= 2;
	}
}

int rmergeSort(element a[], int link[], int left, int right) {
	int mid;
	if (left >= right)
		return left;
	else {
		mid = (left + right) / 2;
		return listMerge(a, link, rmergeSort(a, link, left, mid), rmergeSort(a, link, mid + 1, right));
	}
}

int listMerge(element a[], int link[], int start1, int start2) {
	int last1, last2, lastResult = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (a[last1].key <= a[last2].key) {
			if (a[last1].key <= a[last2].key) {
				link[lastResult] = last1;
				lastResult = last1; last1 = link[last1];
			}
			else {
				link[lastResult] = last2;
				lastResult = last2; last2 = link[last2];
			}
		}
	}
	if (last1 == 0)
		link[lastResult] = last2;
	else
		link[lastResult] = last1;
	return link[0];
}