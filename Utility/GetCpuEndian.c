#include "stdio.h"
#include "stdlib.h"

int checkCPUendian()
// return 1 : little-endian
// return 0 : big-endian
{
	//联合体中的所有数据成员具有同样的起始地址
	union {
	unsigned int a;
	unsigned char b;
	}c;

	c.a = 1;
	return (c.b == 1);

}   

void CUPendian()
{
	printf("CPU Endian:\n");

	if(checkCPUendian())
		printf("This CPU is Little-Endian.\n");
	else
		printf("This CPU is Big-Endian.\n");
	printf("\n");
	printf("Little-Endian (Host Order):\n");
	printf("unsigned shrot 0x1234\n");
	printf("Addr      Value\n");
	printf("0x4001    0x12\n");
	printf("0x4000    0x34\n");
	printf("bit  0  1  2  3  4  5  6  7 |  8  9 10 11 12 13 14 15\n");
	printf("val  0  0  1  1  0  1  0  0 |  0  0  0  1  0  0  1  0 \n");
	printf("Intel X86\n");
	printf("\n");
	printf("Big-Endian (Net Order):\n");
	printf("unsigned shrot 0x1234\n");
	printf("Addr      Value\n");
	printf("0x4001    0x34\n");
	printf("0x4000    0x12\n");
	printf("bit  0  1  2  3  4  5  6  7 |  8  9 10 11 12 13 14 15\n");
	printf("val  0  0  0  1  0  0  1  0 |  0  0  1  1  0  1  0  0\n");
	printf("IBM3700 Series, PDP-10, Mortolora, Sun SPARC and Most RISC Processers\n");
	printf("\n");
}

void main(int argc,char *argv[])
{
	CUPendian();
}