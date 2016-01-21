/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void search(int *nums, int startPos, int numsSize, int target, int range[2]) {
    if (numsSize < 1) {
        range[0] = -1;
        range[1] = -1;
    }
    else if (numsSize == 1) {
        if (nums[startPos] == target) {
            range[0] = startPos;
            range[1] = startPos;
        }
        else {
            range[0] = -1;
            range[1] = -1;
        }
    }
    else {
        int leftRange[2];
        int rightRange[2];
        search(nums, startPos, numsSize / 2, target, leftRange);
        search(nums, startPos + numsSize / 2, numsSize - numsSize / 2, target, rightRange);
        if (leftRange[1] != -1 && rightRange[0] != -1) {
            range[0] = leftRange[0];
            range[1] = rightRange[1];
        }
        else if (leftRange[1] != -1) {
            range[0] = leftRange[0];
            range[1] = leftRange[1];
        }
        else if (rightRange[0] != -1) {
            range[0] = rightRange[0];
            range[1] = rightRange[1];
        }
        else {
            range[0] = -1;
            range[1] = -1;
        }
    }
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *range = malloc(sizeof(int) * 2);
    *returnSize = 2;
    search(nums, 0, numsSize, target, range);
    return range;
}