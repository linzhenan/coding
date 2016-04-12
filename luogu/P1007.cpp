#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int L, N, pos;
	int mint = 0, maxt = 0;
	scanf("%d%d", &L, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &pos);
		mint = max(min(pos, L + 1 - pos), mint);
		maxt = max(max(pos, L + 1 - pos), maxt);
	}
	printf("%d %d\n", mint, maxt);
	return 0;
}