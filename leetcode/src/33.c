int searchMethod1(int *nums, int numsSize, int target) {
    int i, j, pos = -1;
    for (i = 0; i < numsSize - 1; i++)
        if (nums[i] > nums[i + 1])//rotating point is between nums[i] and nums[i + 1]
            break;
    if (nums[0] <= target && target <= nums[i])
        for (j = 0; j <= i; j++)
            if (target == nums[j]) {
                pos = j;
                break;
            }
    if (i + 1 <= numsSize - 1 && nums[i + 1] <= target && target <= nums[numsSize - 1])
        for (j = i + 1; j <= numsSize - 1; j++)
            if (target == nums[j]) {
                pos = j;
                break;
            }
    return pos;
}

int searchMethod2(int *nums, int numsSize, int target) {
    int begin = 0;
    int end = numsSize;
    while (begin != end) {
        int mid = (begin + end) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[begin] <= nums[mid]) {
            if (nums[begin] <= target && target < nums[mid])
                end = mid;
            else
                begin = mid + 1;
        }
        else {
            if (nums[mid] < target && target <= nums[end - 1])
                begin = mid + 1;
            else
                end = mid;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    return searchMethod2(nums, numsSize, target);
}