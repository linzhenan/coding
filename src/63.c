//Unique Paths II
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	if (!obstacleGridRowSize || !obstacleGridColSize)
		return 0;
	int *f = malloc(sizeof(int) * obstacleGridColSize);
	memset(f, 0, sizeof(int) * obstacleGridColSize);
	for (int j = 0; j < obstacleGridColSize; j++)
		if (obstacleGrid[0][j])
			break;
		else
			f[j] = 1;
	for (int i = 1; i < obstacleGridRowSize; i++) {
		if (obstacleGrid[i][0])
			f[0] = 0;
		for (int j = 1; j < obstacleGridColSize; j++)
			if (obstacleGrid[i][j])
				f[j] = 0;
			else
				f[j] = f[j] + f[j - 1];
	}
	return f[obstacleGridColSize - 1];
}