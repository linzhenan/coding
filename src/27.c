int removeElement(int* nums, int numsSize, int val) {
    int i;
    for (i = 0; i < numsSize; )
    {
        if (nums[i] == val)
        {
            nums[i] = nums[numsSize - 1];
            numsSize--;
        }
        else
        {
            i++;
        }
    }
}