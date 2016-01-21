//N-Queens II

typedef enum {
	COL = 0,
	MAIN_DIAG,
	ANTI_DIAG,
	FLAG_NUM,
}
FlagEnum;
void dfs(int *returnSize, int *flag[FLAG_NUM], int row, int n) {
	if (row == n) {
		*returnSize += 1;
	}
	for (int j = 0; j < n; j++) {
		if (flag[COL][j] || flag[MAIN_DIAG][(n - 1 - j) + row] || flag[ANTI_DIAG][row + j])
			continue;
		flag[COL][j] = flag[MAIN_DIAG][(n - 1 - j) + row] = flag[ANTI_DIAG][row + j] = 1;
		dfs(returnSize, flag, row + 1, n);
		flag[COL][j] = flag[MAIN_DIAG][(n - 1 - j) + row] = flag[ANTI_DIAG][row + j] = 0;
	}
}
int totalNQueens(int n) {
	int *flag[FLAG_NUM];
	for (int i = 0; i < FLAG_NUM; i++) {
		int size;
		switch (i)
		{
		case COL: size = n; break;
		case MAIN_DIAG:
		case ANTI_DIAG: size = n * 2 - 1; break;
		}
		flag[i] = malloc(sizeof(int) * size);
		memset(flag[i], 0, sizeof(int) * size);
	}
	int returnSize = 0;
	dfs(&returnSize, flag, 0, n);
	for (int i = 0; i < FLAG_NUM; i++)
		free(flag[i]);
	return returnSize;
}