#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long mypow(int a, int n) {
	long long res = 1;
	for (int i = 1; i <= n; i++)
		res *= a;
	return res;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int A, B, N, K;
		long long cnt = 0;
		scanf("%d%d%d%d", &A, &B, &N, &K);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;
				if ((mypow(i, A) + mypow(j, B)) % K == 0) {
					cnt++;
					cnt %= 1000000007;
				}
			}
		}
		printf("Case #%d: %lld\n", t, cnt);
	}
	return 0;
}