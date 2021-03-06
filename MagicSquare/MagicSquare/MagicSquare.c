#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 15

void main(void) {
	static int square[MAX_SIZE][MAX_SIZE];
	int i, j, row, column;
	int size;
	int count;

	printf("Enter the size of the square : ");
	scanf("%d", &size);
	if (size<1 || size>MAX_SIZE + 1) {
		fprintf(stderr, "Error! Size is out of range\n");
		exit(1);
	}
	if (!(size % 2)) {
		fprintf(stderr, "Error! Size is even\n");
		exit(1);
	}
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			square[i][j] = 0;
	square[0][(size - 1) / 2] = 1;
	i = 0;
	j = (size - 1) / 2;
	for (count = 2; count <= size * size; count++) {
		row = (i - 1 < 0) ? (size - 1) : (i - 1);
		column = (j - 1 < 0) ? (size - 1) : (j - 1);
		if (!square[row][column]) {
			i = (++i) % size;
		}
		else {		// 갈 수 있을 경우,  i와 j를 대각선 위로.
			i = row;
			j = column;
		}
		square[i][j] = count; // 변경된 위치에 다음 수 추가
	}
	// 생성된 magic square를 출력
	printf("Magic Square of size %d : \n \n", size);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%5d", square[i][j]);
			printf("\n");		// 한 줄에 한 행씩 출력
		}
		printf("\n\n");
	}

	}