
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
#include <cmath>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

void mult(double m1[4], double m2[4])
{
	double ans[4];
	ans[0] = m1[0] * m2[0] + m1[1] * m2[2];
	ans[1] = m1[0] * m2[1] + m1[1] * m2[3];
	ans[2] = m1[2] * m2[0] + m1[3] * m2[2];
	ans[3] = m1[2] * m2[1] + m1[3] * m2[3];
	for (int i = 0; i < 4; i++)
		m1[i] = ans[i];
}

int main()
{
	int T, A, B, C, N, X, K;
	double a, b, c;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d%d%d%d%d", &N, &X, &K, &A, &B, &C);
		a = A / 100.0;
		b = B / 100.0;
		c = C / 100.0;
		double ans0[] = { 1, 0, 0, 1 }, ans1[] = { 1, 0, 0, 1 };
		double cur0[] = { 1, a, 0, b + c }, cur1[] = { a, c, b + c, a + b };
		while (N)
		{
			if (N & 1)
			{
				mult(ans0, cur0), mult(ans1, cur1);
				//mult(cur0, ans0), mult(cur1, ans1);//error
			}
			mult(cur0, cur0), mult(cur1, cur1);
			N >>= 1;
		}
		int base = 1;
		double res = 0;
		while (X || K)
		{
			double p1 = X & 1, p0 = 1 - p1;
			double c0, c1;
			if (K & 1)
				c0 = ans1[2], c1 = ans1[3];
			else
				c0 = ans0[2], c1 = ans0[3];
			res += (c0 * p0 + c1 * p1) * base;
			X >>= 1;
			K >>= 1;
			base <<= 1;
		}
		printf("Case #%d: %.10lf\n", t, res);
	}
	return 0;
}
