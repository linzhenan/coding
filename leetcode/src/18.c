/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int quadrupletsNum = 0;
    int **quadruplets = NULL;
    
    for (int i = 0; i < numsSize - 3; i++) {
        for (int j = i + 1; j < numsSize - 2; j++) {
            int m = j + 1;
            int n = numsSize - 1;
            int subTarget = target - nums[i] - nums[j];
            while (m < n) {
                if (nums[m] + nums[n] < subTarget) {
                    while (m + 1 < n && nums[m + 1] == nums[m])
                        m++;
                    m++;
                }
                else if (nums[m] + nums[n] > subTarget) {
                    while (n - 1 > m && nums[n - 1] == nums[n])   
                        n--;
                    n--;
                }
                else {
                    quadrupletsNum++;
                    quadruplets = realloc(quadruplets, sizeof(int *) * quadrupletsNum);
                    quadruplets[quadrupletsNum - 1] = malloc(sizeof(int) * 4);
                    quadruplets[quadrupletsNum - 1][0] = nums[i];
                    quadruplets[quadrupletsNum - 1][1] = nums[j];
                    quadruplets[quadrupletsNum - 1][2] = nums[m];
                    quadruplets[quadrupletsNum - 1][3] = nums[n];
                    while (m + 1 < n && nums[m + 1] == nums[m])
                        m++;
                    m++;
                }
            }
            while (j < numsSize - 1 && nums[j + 1] == nums[j])
                j++;
        }
        while (i < numsSize - 1 && nums[i + 1] == nums[i])
            i++;
    }
    *returnSize = quadrupletsNum;
    return quadruplets;
}