//Minimum Path Sum
int min(int a, int b) {
	return a < b ? a : b;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
	int m = gridRowSize;
	int n = gridColSize;
	if (!m || !n)
		return 0;
	int *f = malloc(sizeof(int) * n);
	f[0] = grid[0][0];
	for (int j = 1; j < n; j++)
		f[j] = f[j - 1] + grid[0][j];
	for (int i = 1; i < m; i++) {
		f[0] = f[0] + grid[i][0];
		for (int j = 1; j < n; j++)
			f[j] = min(f[j - 1], f[j]) + grid[i][j];
	}
	int sum = f[n - 1];
	free(f);
	return sum;
}