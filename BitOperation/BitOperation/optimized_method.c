#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "method.h"

void optimized_method1(unsigned int input,int count) {
	count = bit_count_map_16[input & 0xFFFF] + bit_count_map_16[(input >> 16) & 0xFFFF];
}

void optimized_method2(unsigned int input, int count) {
	count = bit_count_map_8[input & 0xFF] + bit_count_map_8[(input >> 8) & 0xFF]
		+ bit_count_map_8[(input >> 16) & 0xFF] + bit_count_map_8[(input >> 24) & 0xFF];
}

void optimized_method3(unsigned int input, int count) {
	count = bit_count_map_4[input & 0xF] + bit_count_map_4[(input >> 4) & 0xF]
		+ bit_count_map_4[(input >> 8) & 0xF] + bit_count_map_4[(input >> 12) & 0xF]
		+ bit_count_map_4[(input >> 16) & 0xF] + bit_count_map_4[(input >> 20) & 0xF]
		+ bit_count_map_4[(input >> 24) & 0xF] + bit_count_map_4[(input >> 28) & 0xF];
}