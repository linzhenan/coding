//N-Queens

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef enum {
    ROW = 0,
    COL,
    MAIN_DIAG,
    ANTI_DIAG,
    FLAG_NUM,
}
FlagEnum;

void dfs(char ***result, int *returnSize, int *flag[FLAG_NUM], int row, int n) {
    if (row == n) {
        *returnSize += 1;
        result = realloc(result, sizeof(char**) * (*returnSize));
        result[*returnSize - 1] = malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++) {
            result[*returnSize - 1][i] = malloc(sizeof(char) * n);
            memset(result[*returnSize - 1][i], '.', sizeof(char) * n);
        }
        for (int i = 0; i < n; i++)
            result[*returnSize - 1][i][flag[ROW][i]] = 'Q';
    }
    for (int j = 0; j < n; j++) {
        if (flag[COL][j] || flag[MAIN_DIAG][j])
    }
}

char*** solveNQueens(int n, int* returnSize) {
    int *flag[FLAG_NUM];
    char ***result = NULL;
    for (int i = 0; i < FLAG_NUM; i++) {
        flag[i] = malloc(sizeof(int) * n);
        memset(flag[i], 0, sizeof(int) * n);
    }
    dfs(result, returnSize, flag, 0, n);
    for (int i = 0; i < FLAG_NUM; i++)
        free(flag[i]);
    return result;
}