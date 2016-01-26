int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0)
        return 0;
    else if (numsSize == 1) {
        if (target <= nums[0])
            return 0;
        else
            return 1;
    }
    else {
        if (target <= nums[0])
            return 0;
        if (target > nums[numsSize - 1])
            return numsSize;
        int i;
        for (i = 1; i <= numsSize - 1; i++) {
            if (target <= nums[i])
                break;
        }
        return i;
    }
}