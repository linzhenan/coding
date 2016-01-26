/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
void combinationSearch(int *candidates, int candidatesSize, int target, int combBuffer[], int combSize,
                        int ***combs, int **columnSizes, int *returnSize) {
    for (int i = 0; i < candidatesSize; i++) {
        if (candidates[i] < target) {
            combinationSearch(candidates + 1, candidatesSize - 1, target, combBuffer, combSize,
                                combs, columnSizes, returnSize);
            combBuffer[combSize] = candidates[i];
            combinationSearch(candidates + 1, candidatesSize - 1, target - candidates[0], combBuffer, combSize + 1,
                                combs, columnSizes, returnSize);
        }
        else if (candidates[i] == target) {
            *returnSize = *returnSize + 1;
            *combs = realloc(*combs, sizeof(int*) * (*returnSize));
            *columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize));
			combBuffer[combSize] = candidates[i];
            combSize++;
            (*combs)[*returnSize - 1] = malloc(sizeof(int) * combSize);
            memcpy((*combs)[*returnSize - 1], combBuffer, sizeof(int) * combSize);
            (*columnSizes)[*returnSize - 1] = combSize;
            return;
        }
        else {
            return;
        }
    }
    return;
}
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int *combBuffer = malloc(sizeof(int) * candidatesSize);
    int **combs = (int **)0;
    *returnSize = 0;
	*columnSizes = (int*)0;
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    combinationSearch(candidates, candidatesSize, target, combBuffer, 0,
                        &combs, columnSizes, returnSize);
    return combs;
}