#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define MAXM 100

double calc(double r, int C[MAXM + 1], int M) {
	double res = 0;
	double rate = 1.0;
	for (int i = M; i >= 1; i--) {
		res += C[i] * rate;
		rate *= (1 + r);
	}
	res -= C[0] * rate;
	return res;
}
int main() {
	int C[MAXM + 1];
	int T;
	int M;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &M);
		scanf("%d", &C[0]);
		for (int i = 1; i <= M; i++)
			scanf("%d", &C[i]);
		double l = -1.0 + 1e-9;
		double r = +1.0 - 1e-9;
		double m;
		double mres;
		do {
			m = (l + r) / 2;
			mres = calc(m, C, M);
			double lres = calc(l, C, M);
			//printf("l = %.12lf  r = %.12lf  m = %.12lf  v = %.12lf\n", l, r, m, mres);
			if (lres * mres < 0)
				r = m;
			else
				l = m;
			
		} while (abs(mres) > 1e-9 && abs(r - l) > 1e-9);
		printf("Case #%d: %.12lf\n", t, m);
	}

	return 0;
}