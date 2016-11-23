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
	while (x>=0)
	{
		y = i;
		while (y>=0)
		{
			sum += Grid[x][y];
			y -= Lowbit(y);
		}
		x -= Lowbit(x);
	}
	return sum;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &R, &C, &K);
		memset(Grid, 0, sizeof(int) * MAXR * MAXC);
		for (int k = 0; k < K; k++) {
			int r, c;
			scanf("%d%d", &r, &c);
			add(c, r);
		}
		//printf("%d\n", Sum(C - 1, R - 1));
		long long cnt = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				int cur = 0;
				int S = min(R - r, C - c);
				for (int s = 0; s < S; s++) {
					int s0123 = Sum(c + s, r + s);
					int s01 = Sum(c + s, r - 1);
					int s02 = Sum(c - 1, r + s);
					int s0 = Sum(c - 1, r - 1);
					int monster = s0123 - s01 - s02 + s0;
					if (!monster) {
						cnt++;
						cur++;
					}
					else
						break;
				}
				//printf("%d, %d: %d\n", r, c, cur);
			}
		}
		printf("Case #%d: %lld\n", t, cnt);
	}
	return 0;
}