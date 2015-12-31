//Unique Paths

int uniquePaths(int m, int n) {
	if (!m || !n)
		return 0;
	int *f = malloc(sizeof(int) * n);
	memset(f, 0, sizeof(int) * n);
	for (int j = 0; j < n; j++)
		f[j] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++)
			f[j] = f[j] + f[j - 1];
	}
	return f[n - 1];
}