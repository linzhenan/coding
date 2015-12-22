void moveZeroes(int* nums, int numsSize) {
    int i, j = 0;
    
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != 0)
            continue;

        //find the first non-zero num after num[i]     
        if (j <= i)
            j = i + 1;
        for (; j < numsSize; j++)
            if (nums[j] == 0)
                continue;
            else
                break;

        if (j < numsSize)//found
        {
            nums[i] = nums[j];
            nums[j] = 0;
        }
        else//no more
        {
            break;
        }
    }
}