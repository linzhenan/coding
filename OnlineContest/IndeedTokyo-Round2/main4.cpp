#include <vector>
#include <cstdio>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int k;
	int s = 0;
	cin >> k;
	int* count = (int*)malloc(sizeof(int) * k);
	double* p = (double*)malloc(sizeof(double) * k);
	double* dp = (double*)malloc(sizeof(double) * 2048);
	int i;
	for (int i = 0; i < k; i++) {
		count[i] = 0;
		p[i] = 0.0;
	}
	for (int i = 0; i < 2048; i++) {
		dp[i] = 0.0;
	}
	/*memset(count, 0, sizeof(int) * k);
	memset(p, 0, sizeof(double) * k);
	memset(dp, 0, sizeof(double) * 2048);*/

	for (int i = 0; i < k; i++) {
		scanf("%d", &count[i]);
		s += count[i];
	}
	for (int i = 0; i < k; i++)
		p[i] = 1.0 * count[i] / s;

	for (int i = 0; i < k; i++)
		dp[1 << i] = 1.0 / p[i];

	int total = (1 << k) - 1;
	for (int i = 0; i <= total; i++) {
		if (dp[i] > 0.0)
			continue;
		double b = 0;
		double sum = 0;

		for (int j = 0; j < k; j++) {
			if ((i & (1 << j)) > 0) {
				sum += p[j];
				int idx = i & (~(1 << j));
				b += p[j] * (1 + dp[idx]);
			}
		}

		dp[i] = (b + (1.0 - sum)) / sum;
	}

	printf("%lf", dp[total]);

}