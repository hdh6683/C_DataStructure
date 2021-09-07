#include "method.h"

void init_bitmap() {
	unsigned int i;
	unsigned char count;

	count = 0;

	for (i = 0; i < 0x10000; i++) {
		count = shift_method(i, count);
		if (i < 0x10000) {
			bit_count_map_16[i] = count;
		}
		if (i < 0x100) {
			bit_count_map_8[i] = count;
		}
		if (i < 0x10) {
			bit_count_map_4[i] = count;
		}
	}	
}
