#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#ifdef WIN32
#pragma warning(disable:4996)
#endif

int main() {
	char ch;

	while (scanf("%c", &ch) != EOF) {
		if (ch == ',')
			printf("\n");
		else if (ch == '\n')
			break;
		else
			printf("%c", ch);
	}
	printf("\n");
	return 0;
}