#include <cstdio>
#include <cstring>
#include <cinttypes>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

int main() {
	int t;
	int n, k;
	int num[4][1000];
	int ans;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < n; l++) {
				scanf("%d", &num[j][l]);
			}
		}
		for (int l0 = 0; l0 < n; l0++)
			for (int l1 = 0; l1 < n; l1++)
				for (int l2 = 0; l2 < n; l2++)
					for (int l3 = 0; l3 < n; l3++) {
						if ((num[0][l0] ^ num[1][l1] ^ num[2][l2] ^ num[3][l3]) == k) {
							//printf("%d %d %d %d\n", num[0][l0], num[1][l1], num[2][l2], num[3][l3]);
							ans++;
						}
					}
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}