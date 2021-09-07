#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "method.h"

int main() {
	unsigned short int input;
	unsigned __int64 start;
	unsigned __int64 end;
	int i;

	int choice;
	int count = 0;
	srand(time(NULL));

	start = GetTickCount64();
	init_bitmap();
	end = GetTickCount64();
	printf("비트맵 초기화 경과시간 : %d\n", end - start);

	while (1) {
		//printf("1 ~ 4,294,967,295 범위의 수를 입력하세요(0 입력시 종료 ) : ");
		//scanf("%d", &input);
		//}else if (input < 0 || input>4294967295) {
		//	printf("범위 안의 수를 입력하세요.\n");
		//	continue;
		//}

		//printf("입력하신 수는 %d입니다.\n", input);

		printf("비트 연산을 실행할 알고리즘을 선택하세요.\n");
		printf("1. Divide By 2 알고리즘    2. Shift 알고리즘    3. Optimized 알고리즘    0. 종료\n");

		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("프로그램을 종료합니다.\n");
			break;
		case 1:
			start = GetTickCount64();
			for (i = 0; i < 1000000; i++) {
				input = rand() + 1;
				divide_method(input, count);
			}
			end = GetTickCount64();
			printf("알고리즘 1 경과시간 : %d\n", end - start);
			break;
		case 2:
			start = GetTickCount64(); 
			for (i = 0; i < 1000000; i++) {
				input = rand() + 1;
				shift_method(input, count);
			}
			end = GetTickCount64();
			printf("알고리즘 2 경과시간 : %d\n", end - start);
			break;
		case 3:
			start = GetTickCount64();
			optimized_method1(input,count);
			end = GetTickCount64();
			printf("알고리즘 3-1 경과시간 : %d\n", end - start);

			start = GetTickCount64();
			optimized_method2(input, count);
			end = GetTickCount64();
			printf("알고리즘 3-2 경과시간 : %d\n", end - start);

			start = GetTickCount64();
			optimized_method3(input, count);
			end = GetTickCount64();
			printf("알고리즘 3-3 경과시간 : %d\n", end - start);
			break;
		}
		if (choice == 0)
			break;
	}
	return 0;
}