#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int L, R;
		scanf("%d%d", &L, &R);
		long long K = min(L, R);
		long long res = (K + 1) * K / 2;
		printf("Case #%d: %lld\n", t, res);
	}
	return 0;
}