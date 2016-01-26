#include "leetcode.h"

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
void dfs(char ****result, int *returnSize, int *flag[FLAG_NUM], int row, int n) {
    if (row == n) {
        *returnSize += 1;
        (*result) = realloc(*result, sizeof(char**) * (*returnSize));
        (*result)[*returnSize - 1] = malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++) {
            (*result)[*returnSize - 1][i] = malloc(sizeof(char) * (n + 1));
            memset((*result)[*returnSize - 1][i], '.', sizeof(char) * n);
            (*result)[*returnSize - 1][i][n] = '\0';
        }
        for (int i = 0; i < n; i++)
            (*result)[*returnSize - 1][i][flag[ROW][i]] = 'Q';
    }
    for (int j = 0; j < n; j++) {
        if (flag[COL][j] || flag[MAIN_DIAG][(n - 1 - j) + row] || flag[ANTI_DIAG][row + j])
            continue;
        flag[COL][j] = flag[MAIN_DIAG][(n - 1 - j) + row] = flag[ANTI_DIAG][row + j] = 1;
        flag[ROW][row] = j;
        dfs(result, returnSize, flag, row + 1, n);
        flag[ROW][row] = 0;
        flag[COL][j] = flag[MAIN_DIAG][(n - 1 - j) + row] = flag[ANTI_DIAG][row + j] = 0;
    }
}
char*** solveNQueens(int n, int* returnSize) {
    int *flag[FLAG_NUM];
    char ***result = NULL;
    for (int i = 0; i < FLAG_NUM; i++) {
        int size;
        switch (i)
        {
        case ROW:
        case COL: size = n; break;
        case MAIN_DIAG:
        case ANTI_DIAG: size = n * 2 - 1; break;
        }
        flag[i] = malloc(sizeof(int) * size);
        memset(flag[i], 0, sizeof(int) * size);
    }
    *returnSize = 0;
    dfs(&result, returnSize, flag, 0, n);
    for (int i = 0; i < FLAG_NUM; i++)
        free(flag[i]);
    return result;
}

void main()
{
    int n = 6;
    int returnSize;
    char ***result = solveNQueens(n, &returnSize);
    for (int k = 0; k < returnSize; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c", *(*(*(result + k) + i) + j));
            printf("\n");
        }
        printf("\n");
    }
}