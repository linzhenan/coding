//Permutations

#include "leetcode.h"

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int ***result, int *nums, int numsSize, int *returnSize, int *use, int *per, int n) {
    if (n == numsSize) {
        *returnSize += 1;
        *result = realloc(*result, sizeof(int *) * (*returnSize));
        (*result)[*returnSize - 1] = malloc(sizeof(int) * numsSize);
        memcpy((*result)[*returnSize - 1], per, sizeof(int) * numsSize);
    }
    else {
        for (int i = 0; i < numsSize; i++) {
            if (use[i])
                continue;
            use[i] = 1;
            per[n] = nums[i];
            dfs(result, nums, numsSize, returnSize, use, per, n + 1);
            use[i] = 0;
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if (!numsSize)
        return NULL;
        
    int *use = malloc(sizeof(int) * numsSize);
    memset(use, 0, sizeof(int) * numsSize);
    int *per = malloc(sizeof(int) * numsSize);
    
    int **result = NULL;
    dfs(&result, nums, numsSize, returnSize, use, per, 0);
    
    free(use);
    free(per);
    
    return result;
}
void main() {
#define numsSize 1
	int nums[numsSize] = { 1 };
	int returnSize;
	int **result;

	result = permute(nums, numsSize, &returnSize);

	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < numsSize; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}