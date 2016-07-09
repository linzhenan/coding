#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define N 50
#define TBD 10

int r, c;

int dfs(char map[N][N], int i0[TBD], int j0[TBD], int level) {
	if (level == 0) {
		int cnt = 0;
		int down = 0;
		char op[N][N];
		memcpy(op, map, sizeof(char) * N * N);
		while (down < r * c) {
			cnt++;
			int i, j;
			for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					if (op[i][j] != '.')
						break;
				}
				if (j < c && op[i][j] != '.')
					break;
			}
			while (i < r && j < c) {
				if (op[i][j] == 'R') {
					op[i][j++] = '.';
					down++;
				}
				else if (op[i][j] == 'C') {
					op[i++][j] = '.';
					down++;
				}
				else
					break;
			}
		}
		return cnt;
	}

	map[i0[0]][j0[0]] = 'R';
	int cnt1 = dfs(map, i0 + 1, j0 + 1, level - 1);
	map[i0[0]][j0[0]] = 'C';
	int cnt2 = dfs(map, i0 + 1, j0 + 1, level - 1);
	return cnt1 + cnt2;
}

int main() {

	int i0[TBD], j0[TBD], n = 0;
	char map[N][N];
	
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", map[i]);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '?') {
				i0[n] = i;
				j0[n] = j;
				n++;
			}
		}

	int cnt = dfs(map, i0, j0, n);

	double res = cnt / pow(2, n);
	printf("%.15lf\n", res);

	return 0;
}