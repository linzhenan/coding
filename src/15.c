/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}
 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i, j, k;
    int sum;
    
    int tripletsNum = 0;
    int** triplets = NULL;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    for (i = 0; i < numsSize - 2; i++) {
        if (i && nums[i] == nums[i - 1])
            continue;
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                tripletsNum++;
                triplets = realloc(triplets, sizeof(int*) * tripletsNum);
                triplets[tripletsNum - 1] = malloc(sizeof(int) * 3);
                triplets[tripletsNum - 1][0] = nums[i];
                triplets[tripletsNum - 1][1] = nums[j];
                triplets[tripletsNum - 1][2] = nums[k];
                while (j < k) {
                    j++;
                    if (nums[j] == nums[j - 1])
                        continue;
                    else
                        break;
                }
            }
            else if (sum < 0) {
                while (j < k) {
                    j++;
                    if (nums[j] == nums[j - 1])
                        continue;
                    else
                        break;
                }
            }
            else { //sum > 0
                while (j < k) {
                    k--;
                    if (nums[k] == nums[k + 1])
                        continue;
                    else
                        break;
                }
            }
        }
    }
    *returnSize = tripletsNum;
    return triplets;
    
}