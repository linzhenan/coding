int removeDuplicates(int* nums, int numsSize) {
    int newSize = 0, i = 0;
    while (i < numsSize) {
        while (i + 1 < numsSize && nums[i] == nums[i + 1])
            i++;
        nums[newSize++] = nums[i++];
    }
    return newSize;
}