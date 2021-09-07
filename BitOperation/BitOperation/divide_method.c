#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void divide_method(unsigned int input,int count) {
	int remainder;
	count = 0;

	while (input>=1) {
		remainder = input & 0x1;
		if (remainder == 1) {
			(count)++;
		}
		input = input / 2;
	}
	/*printf("%d\n", count);*/
}

