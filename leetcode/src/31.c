int cmp(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}
void nextPermutation(int* nums, int numsSize) {
    //find the first inversion pair
    int find = 0;
    int i, j;
    for (i = numsSize - 1; find == 0 && i >= 1; i--) {
        if (nums[i - 1] < nums[i])
            find = 1;
    }
    if (find) {
        //...nums[i] nums[i + 1] ... nums[numsSize - 1]
        //select the smallest nums[j] from nums[i + 1]...nums[numsSize - 1]
        for (j = numsSize - 1; j >= i + 1; j--)
            if (nums[j] > nums[i]) {
                int tmp;
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                break;
            }
        //...nums[i] nums[i + 1]...
        qsort(nums + i + 1, numsSize - (i + 1), sizeof(int), cmp);
    }
    else {
        qsort(nums, numsSize, sizeof(int), cmp);
    }
}