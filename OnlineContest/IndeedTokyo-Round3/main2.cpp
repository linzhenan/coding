#include <cstdio>

//the last two cases fail

int main() {

	int a, b, k;
	float taka_next = 0;
	float aoki_next = 0;

	scanf("%d%d%d", &a, &b, &k);
	taka_next = a;
	aoki_next = 0.5 + b;

	while (k > 0) {
		if (aoki_next < taka_next) {
			k--;
			aoki_next += b;
			if (k == 0)
				printf("Aoki\n");
		}
		else if (aoki_next > taka_next) {
			k--;
			taka_next += a;
			if (k == 0)
				printf("Takahashi\n");
		}
		else {
			k -= 2;
		}
	}
	return 0;
}