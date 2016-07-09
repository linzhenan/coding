#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
#include <cmath>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

double dfs(int level, int n, int a, int b, int c, int input, int k) {
	if (level == n)
		return input;
	return  1.0 * a / 100 * dfs(level + 1, n, a, b, c, input & k, k) +
			1.0 * b / 100 * dfs(level + 1, n, a, b, c, input | k, k) +
			1.0 * c / 100 * dfs(level + 1, n, a, b, c, input ^ k, k);
}
int main() {

	/*
	int x = 1;
	int k = 1;

	printf("%d\n", x ^ k & k | k ^ k ^ k ^ k);
	printf("%d\n", x & k | k ^ k & k | k | k);
	printf("%d\n", x | k & k ^ k | k | k & k);
	*/

	int t;
	int n, x, k, a, b, c;
	double ans;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d%d%d%d%d%d", &n, &x, &k, &a, &b, &c);
		ans = dfs(0, n, a, b, c, x, k);
		printf("Case #%d: %.10lf\n", i, ans);
	}
	//< D:\C-small-attempt0.in > D:\output.txt

	int na, nb, nc;// & | ^
	for (int na = 0; na <= n; na++)
		for (int nb = 0; nb <= n - na; nb++) {
			int nc = n - na - nb;
			double prop = pow(1.0 * a / 100, na) *
				pow(1.0 * b / 100, nb) *
				pow(1.0 * c / 100, nc);
			for (int shift = 0; shift <= 13; shift++) {
				int mask = 1 << shift;
				int kbit = k & mask;
				int xbit = x & mask;
				int rbit;
				if (!xbit && !kbit)
					rbit = 0;
				else if (xbit && !kbit) {
					if (na)
						rbit = 0;
					else
						rbit = 1 << shift;
				}
				else if (!xbit && kbit) {

				}

			}
		}
	return 0;
}