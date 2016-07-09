#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
	int a, b, c;
	char s[101];
	scanf("%d%d%d%s", &a, &b, &c, s);
	printf("%d %s\n", a + b + c, s);
	return 0;
}