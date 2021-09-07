#ifndef METHOD_H
#define METHOD_H

void optimized_method1(unsigned int input,int count);
void optimized_method2(unsigned int input,int count);
void optimized_method3(unsigned int input,int count);
int shift_method(unsigned int input,int count);
void divide_method(unsigned int input,int count);
void init_bitmap();

static unsigned char bit_count_map_16[0x10000];
static unsigned char bit_count_map_8[0x100];
static unsigned char bit_count_map_4[0x10];

#endif