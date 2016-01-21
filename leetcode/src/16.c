int cmp(const void *a, const void *b)//ascending order
{
    return (*(int*)a) - (*(int*)b);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k;
    int diff;
    int diff_min = 1 << 30;
    
    qsort(nums, numsSize, sizeof(int), cmp);
                    
    for (i = 0; i < numsSize; i++)
    {
        j = i + 1;
        k = numsSize - 1;
        
        while (j < k)
        {
            diff = nums[i] + nums[j] + nums[k] - target;
            
            if (diff == 0)
                return target;
            if (abs(diff) < abs(diff_min))
                diff_min = diff;
            if (diff < 0)
                j++;
            else
                k--;
        }
    }
    return target + diff_min;
}