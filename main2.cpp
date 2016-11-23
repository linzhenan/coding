#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
/*
int main() {
	int n;
	scanf("%d", &n);
	int cnt = INT_MAX;
	for (int i = 0; i <= n / 6; i++) {
		int j = (n - 6 * i) / 8;
		if (i * 6 + j * 8 == n)
			cnt = min(cnt, i + j);
	}
	if (cnt == INT_MAX)
		cnt = -1;
	printf("%d\n", cnt);
}
*/

/*
int f(int n) {
	if (n <= 0) return -1;
	if (n & 1) return n;
	while (!(n & 1)) n >>= 1;
	return n;
}
int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += f(i);
	printf("%d\n", sum);
}
*/

int f(int n) {
	if (n <= 0) return -1;
	if (n & 1) return n;
	while (!(n & 1)) n >>= 1;
	return n;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n <= 0) return 0;
	long long sum = 0;
	
	//odd
	int m = n & (~1);
	sum += m * m / 4;
	if (n & 1)
		sum += n;

	//even
	int power = 2;
	for (int power = 2; power <= m; power *= 2) {
		for (int i = 1; i <= n / power; i += 2) {
			sum += i;
		}
	}

	printf("%lld\n", sum);
}
