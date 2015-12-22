int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    int newSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val)
            newSize--;
        else
            nums[index++] = nums[i];
    }
    return newSize;
}