#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;