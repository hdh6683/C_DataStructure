#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "method.h"

int shift_method(unsigned int input,int count) {
	count = 0;
	int i;

	for (i = 31; i >= 0; i--) {
		int result = (input >> i) & 1;
		if (result == 1) {
			(count)++;
		}
	}
	return count;
	/*printf("%d\n",count);*/
}