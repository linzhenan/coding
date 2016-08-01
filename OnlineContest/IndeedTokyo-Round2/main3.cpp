#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#ifdef WIN32
#pragma warning(disable:4996)
#endif
int valid(int map[7][7]) {
	int i, j;
	for (i = 1; i <= 6; i++)
		if (map[i][0] > 3)
			return 0;
	for (j = 1; j <= 6; j++)
		if (map[0][j] > 3)
			return 0;
	return 1;
}
int satisfy(int map[7][7]) {
	int i, j;
	for (i = 1; i <= 6; i++)
		if (map[i][0] != 3)
			return 0;
	for (j = 1; j <= 6; j++)
		if (map[0][j] != 3)
			return 0;
	return 1;
}
int dfs(int map[7][7], int visit[7][7], int i, int j) {
	int cnt = 0;
	if (i < 1 || j < 1 || i > 6 || j > 6 || visit[i][j])
		return 0;
	if (satisfy(map))
		return 1;
	visit[i][j] = 1;
	if (!map[i][j]) {
		map[i][j] = 1;
		map[0][j]++;
		map[i][0]++;
		if (satisfy(map))
			cnt = 1;
		else if (valid(map)) {
			cnt += dfs(map, visit, i + 1, j);
			cnt += dfs(map, visit, i - 1, j);
			cnt += dfs(map, visit, i, j + 1);
			cnt += dfs(map, visit, i, j - 1);
		}
		map[i][j] = 0;
		map[0][j]--;
		map[i][0]--;
	}
	cnt += dfs(map, visit, i + 1, j);
	cnt += dfs(map, visit, i - 1, j);
	cnt += dfs(map, visit, i, j + 1);
	cnt += dfs(map, visit, i, j - 1);

	return cnt;
}

int main() {
	int i, j;
	char table[7][8];
	int map[7][7] = { 0 };
	int visit[7][7] = { 0 };
	int cnt = 0;

	for (i = 1; i <= 6; i++)
		scanf("%s", &table[i][1]);
	for (i = 1; i <= 6; i++)
		for (j = 1; j <= 6; j++) {
			if (table[i][j] == 'o') {
				map[i][j] = 1;
				map[0][j]++;
				map[i][0]++;
			}
		}
	cnt = dfs(map, visit, 1, 1);
	printf("%d\n", cnt);
	return 0;
}