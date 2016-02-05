//计算整数二进制表示里'1'的个数
//判断整数二进制表示里'1'的个数是偶数/奇数
//http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html

#include <stdio.h>
#include <stdint.h>
#include <nmmintrin.h>

typedef struct B4 {
	uint8_t b0:1;
	uint8_t b1:1;
	uint8_t b2:1;
	uint8_t b3:1;
	uint8_t b4:1;
	uint8_t b5:1;
	uint8_t b6:1;
	uint8_t b7:1;

	uint8_t b8:1;
	uint8_t b9:1;
	uint8_t b10:1;
	uint8_t b11:1;
	uint8_t b12:1;
	uint8_t b13:1;
	uint8_t b14:1;
	uint8_t b15:1;

	uint8_t b16 : 1;
	uint8_t b17 : 1;
	uint8_t b18 : 1;
	uint8_t b19 : 1;
	uint8_t b20 : 1;
	uint8_t b21 : 1;
	uint8_t b22 : 1;
	uint8_t b23 : 1;

	uint8_t b24 : 1;
	uint8_t b25 : 1;
	uint8_t b26 : 1;
	uint8_t b27 : 1;
	uint8_t b28 : 1;
	uint8_t b29 : 1;
	uint8_t b30 : 1;
	uint8_t b31 : 1;
}
B4;
int oneBitCntBM(uint32_t num) {
	B4 *p = (B4 *)&num;
	return p->b0 + p->b1 + p->b2 + p->b3 + p->b4 + p->b5 + p->b6 + p->b7 + 
			p->b8 + p->b9 + p->b10 + p->b11 + p->b12 + p->b13 + p->b14 + p->b15 + 
			p->b16 + p->b17 + p->b18 + p->b19 + p->b20 + p->b21 + p->b22 + p->b23 + 
			p->b24 + p->b25 + p->b26 + p->b27 + p->b28 + p->b29 + p->b30 + p->b31;
}

int oneBitCntIntrinsic(uint32_t num) {
	return _mm_popcnt_u32(num);
}

int oneBitCntLoop(uint32_t num) {
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (num & 0x01)
			count++;
		num = num >> 1;
	}
	return count;
}

int leadingZeroBitCnt(uint32_t num) {
	return _lzcnt_u32(num);
}

int trailingZeroBitCnt(uint32_t num) {
	return _tzcnt_u32(num);
}

void main() {
	uint32_t num = 31;
	printf("%d\n", oneBitCntIntrinsic(num));
	printf("%d\n", oneBitCntBM(num));
	printf("%d\n", oneBitCntLoop(num));
	printf("%d\n", leadingZeroBitCnt(num));
	printf("%d\n", trailingZeroBitCnt(num));
}