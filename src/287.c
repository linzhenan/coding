int findDuplicate(int* nums, int numsSize) {
    int i, j;
    int num_left, num_right;
    if (numsSize == 2) {
        if (nums[0] == nums[1])
            return nums[0];
        else
            return 0;
    }
    else if (numsSize == 3) {
        if (nums[0] == nums[1])
            return nums[0];
        else if (nums[1] == nums[2])
            return nums[1];
        else if (nums[2] == nums[0])
            return nums[2];
        else
            return 0;
    }
    else if (numsSize > 3) {
        num_left = findDuplicate(nums, numsSize / 2);
        if (num_left != 0)
            return num_left;
        num_right = findDuplicate(nums + numsSize / 2, numsSize - numsSize / 2);
        if (num_right != 0)
            return num_right;
        for (i = 0; i < numsSize / 2; i++)
            for (j = numsSize / 2; j < numsSize; j++)
                if (nums[i] == nums[j])
                    return nums[i];
        return 0;
    }
    return 0;
}