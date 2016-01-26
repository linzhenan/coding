int singleNumber(int* nums, int numsSize) {
    int i;
    int num = nums[0];
    for (i = 1; i < numsSize; i++)
        num ^= nums[i];
    return num;
}