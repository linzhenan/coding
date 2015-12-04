#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int i, j;

	for (i = 0; i < 5; i++) {
		int num = 2 * i + 1;
		int num_blank = 4 - i;
		for (j = 0; j < num_blank; j++)
			printf(" ");
		for (j = 0; j < num; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}