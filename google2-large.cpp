#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

#define MAXR 3000
#define MAXC 3000

int Grid[MAXC][MAXR];
int R, C, K;
int Mark[MAXC][MAXR];

int Lowbit(int t)
{
	t++;
	return t&(-t);
}
void add(int x, int y)
{
	int i = y;
	while (x < C)
	{
		y = i;
		while (y < R)
		{
			Grid[x][y]++;
			y += Lowbit(y);
		}
		x += Lowbit(x);
	}
}
int Sum(int x, int y)
{
	int i = y, sum = 0;
	while (x >= 0)
	{
		y = i;
		while (y >= 0)
		{
			sum += Grid[x][y];
			y -= Lowbit(y);
		}
		x -= Lowbit(x);
	}
	return sum;
}

long long sumsquare(int s) {
	long long sum = 0;
	sum = s * (s + 1) * (2 * s + 1);
	return sum;
	for (int i = 1; i <= s; i++)
		sum += i * i;
	return sum;
}
int hasMonster(int r, int c, int s) {
	s--;
	int s0123 = Sum(c + s, r + s);
	int s01 = Sum(c + s, r - 1);
	int s02 = Sum(c - 1, r + s);
	int s0 = Sum(c - 1, r - 1);
	return s0123 - s01 - s02 + s0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &R, &C, &K);
		memset(Grid, 0, sizeof(int) * MAXR * MAXC);
		memset(Mark, 0, sizeof(int) * MAXR * MAXC);
		for (int k = 0; k < K; k++) {
			int r, c;
			scanf("%d%d", &r, &c);
			add(c, r);
			Mark[r][c] = 1;
		}
		//printf("%d\n", Sum(C - 1, R - 1));
		long long cnt = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				int maxS = min(R - r, C - c);
				int minS = 1;
				int midS = minS + (maxS - minS) / 2;
				int midS_last = midS;
				while (minS <= maxS) {
					if (hasMonster(r, c, midS))
						maxS = midS - 1;
					else {
						minS = midS + 1;
						midS_last = midS;
					}
					midS = minS + (maxS - minS) / 2;
				}
				//printf("%d, %d: %d", r, c, midS_last);
				if (!hasMonster(r, c, midS_last)) {
					//cnt += sumsquare(midS_last);
					cnt += midS_last;
					//printf("cnt : 0 (%d)\n", sumsquare(midS_last));
				}
				else
				{
					//printf("cnt : %d\n", hasMonster(r, c, midS_last));
				}
				//for (int i = r; i <= r + s; i++) {
				//	for (int j = c; j <= c + s; j++) {
				//		Mark[i][j] = 1;
				//	}
				//}
				//printf("%d, %d: %d\n", r, c, cur);
			}
		}
		printf("Case #%d: %lld\n", t, cnt);
	}
	return 0;
}