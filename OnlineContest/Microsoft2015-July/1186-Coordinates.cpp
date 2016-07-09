#include <stdio.h>

#pragma warning(disable:4996)

int main() {
	int P, Q;

	scanf("%d%d", &P, &Q);

	for (int i = 1; i <= P; i++) {
		if (P % i != 0)
			continue;
		for (int j = 1; j <= Q; j++) {
			if (Q % j != 0)
				continue;
			printf("%d %d\n", i, j);
		}
	}

	return 0;
}