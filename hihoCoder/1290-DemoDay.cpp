#include <stdio.h>
#include <string.h>
#define MAXLEN 110

#define MIN(x, y) ((x)<(y)?(x):(y))
int map[MAXLEN][MAXLEN];
int n, m;

int dp[MAXLEN][MAXLEN][2];

int main() {
	int i, j;

	scanf("%d%d", &n, &m);

	memset(map, 0, sizeof(map));
	for (i = 0; i < n; i++) {
		char line[MAXLEN];
		scanf("%s", line);
		for (j = 0; j < m; j++) {
			if (line[j] == '.')
				map[i][j] = 1;
		}
	}

	dp[0][0][0] = 0;
	dp[0][0][1] = map[0][1];
	for (j = 1; j < m; j++) {
		dp[0][j][0] = dp[0][j - 1][0] + !map[0][j];
		dp[0][j][1] = dp[0][j - 1][0] + !map[0][j] + map[0][j + 1];
	}
	for (i = 1; i < n; i++) {
		dp[i][0][0] = dp[i - 1][0][1] + !map[i][0] + map[i + 1][0];
		dp[i][0][1] = dp[i - 1][0][1] + !map[i][0];
	}
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			dp[i][j][0] = MIN(dp[i - 1][j][1] + !map[i][j] + map[i + 1][j],
				dp[i][j - 1][0] + !map[i][j]);
			dp[i][j][1] = MIN(dp[i - 1][j][1] + !map[i][j],
				dp[i][j - 1][0] + !map[i][j] + map[i][j + 1]);
		}
	}

	printf("%d\n", MIN(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]));

	return 0;
}