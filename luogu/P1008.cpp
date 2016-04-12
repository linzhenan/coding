#include <stdio.h>
#include <memory.h>

int main() {
	int a, b, c;
	int hash[10];
	int num;
	for (a = 100; a <= 333; a++) {
		memset(hash, 0, sizeof(int) * 10);
		hash[0] = 1;
		num = a / 100;		hash[num] = 1;
		num = a / 10 % 10;	if (hash[num]) continue; else hash[num] = 1;
		num = a % 10;		if (hash[num]) continue; else hash[num] = 1;
		b = a * 2;
		num = b / 100;		if (hash[num]) continue; else hash[num] = 1;
		num = b / 10 % 10;	if (hash[num]) continue; else hash[num] = 1;
		num = b % 10;		if (hash[num]) continue; else hash[num] = 1;
		c = a * 3;
		num = c / 100;		if (hash[num]) continue; else hash[num] = 1;
		num = c / 10 % 10;	if (hash[num]) continue; else hash[num] = 1;
		num = c % 10;		if (hash[num]) continue; else hash[num] = 1;
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}