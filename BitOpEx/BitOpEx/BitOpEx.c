#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef unsigned int U32;
typedef unsigned char U08;

//static U08 bit_count_map_32[0x100000000];
static U08 bit_count_map_16[0x10000];
static U08 bit_count_map_8[0x100];
static U08 bit_count_map_4[0x10];

U08 get_bit_count_func1(U32 u32Input) {
    U32 i;
    U08 count = 0;

    for (i = 0; i < 32; i++) {  // 각 자리수가 1이면 count
        if (((u32Input >> i) & 0x1) == 0x01) {
            count++;
        }
    }

    return count;
}

void init_bit_count_map() {
    U32 i;
    U08 count;

    for (i = 0; i < 0x10000; i++) {
        count = get_bit_count_func1(i);
        //bit_count_map_32[i] = count;
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

#if 0
U08 get_bit_count_func2(U32 u32Input) {
    return bit_count_map_32[u32Input];
}
#endif // 0

U08 get_bit_count_func3(U32 u32Input) {
    U08 count = 0;
#if 1
    U32 i;

    for (i = 0; i < 2; i++) {
        count = count + bit_count_map_16[(u32Input >> (16 * i)) & 0xFFFF];
    }
#else
    count = bit_count_map_16[u32Input & 0xFFFF] + bit_count_map_16[(u32Input >> 16) & 0xFFFF];
#endif // 1
    return count;
}

U08 get_bit_count_func4(U32 u32Input) {
    U08 count = 0;
#if 1
    U32 i;

    for (i = 0; i < 4; i++) {
        count = count + bit_count_map_8[(u32Input >> (8 * i)) & 0xFF];
    }
#else
    count = bit_count_map_8[u32Input & 0xFF] + bit_count_map_8[(u32Input >> 8) & 0xFF] + bit_count_map_8[(u32Input >> 16) & 0xFF] + bit_count_map_8[(u32Input >> 24) & 0xFF];
#endif // 1
    return count;
}

U08 get_bit_count_func5(U32 u32Input) {
    U08 count = 0;
#if 1
    U32 i;

    for (i = 0; i < 8; i++) {
        count = count + bit_count_map_4[(u32Input >> (4 * i)) & 0xF];
    }
#else
    count = bit_count_map_4[u32Input & 0xF] + bit_count_map_4[(u32Input >> 4) & 0xF] + bit_count_map_4[(u32Input >> 8) & 0xF] + bit_count_map_4[(u32Input >> 12) & 0xF] + bit_count_map_4[(u32Input >> 16) & 0xF] + bit_count_map_8[(u32Input >> 20) & 0xF] + bit_count_map_8[(u32Input >> 24) & 0xF] + bit_count_map_8[(u32Input >> 28) & 0xF];
#endif // 1
    return count;
}


int main()
{
    U32 func_type = 2;
    U32 start_time, take_time;
    U32 Input_Data;

    start_time = (U32)GetTickCount();
    printf("Initial bit_count_map\n");
    init_bit_count_map();
    take_time = (U32)GetTickCount() - start_time;
    printf("Initial Take time : %dms\n", take_time);

    for (func_type = 0; func_type < 4; func_type++) {

        start_time = (U32)GetTickCount();
        printf("Start function type : %d\n", func_type);
        for (Input_Data = 0; Input_Data < 0x1000000; Input_Data++) {
            switch (func_type) {
            case 0:
                get_bit_count_func1(Input_Data);
                break;
            case 1:
                get_bit_count_func3(Input_Data);
                break;
            case 2:
                get_bit_count_func4(Input_Data);
                break;
#if 1
            case 3:
                get_bit_count_func5(Input_Data);
                break;
#endif
            default:
                break;
            }
        }
        take_time = (U32)GetTickCount() - start_time;
        printf("Take time : %dms\n", take_time);
    }
    printf("End Test\n");
    return 0;
}
