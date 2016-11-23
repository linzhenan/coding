#include <stdio.h>
#include <memory>
#include <algorithm>
#include <cmath>
using namespace std;

char grid[3010][3010];
int ans;

int dfs(int rs, int cs, int size)
{
	int nextr = rs + size - 1;
	int nextc = cs + size - 1;
	for (int i = rs; i <= nextr; i++)
		if (grid[i][nextc] == 50)
			return 0;
	for (int j = cs; j <= nextc; j++)
		if (grid[nextr][j] == 50)
			return 0;
	return 1;
}
int main()
{
	int T, R, C, K;
	scanf("%d", &T);
	for (int k = 1; k <= T; k++)
	{
		scanf("%d%d%d", &R, &C, &K);
		memset(grid, 1, sizeof(grid));
		ans = R * C - K;
		for (int i = 0; i < K; i++)
		{
			int r, c;
			scanf("%d%d", &r, &c);
			grid[r][c] = 50;
		}
		for (int size = 2; size <= min(R, C); size++)
			for (int i = 0; i <= R - size; i++)
				for (int j = 0; j <= C - size; j++)
				{
					if (grid[i][j] == 1)
					{
						int ret = dfs(i, j, size);
						ans += ret;
						grid[i][j] = ret;
					}
				}

		printf("Case #%d: %d\n", k, ans);
	}
}