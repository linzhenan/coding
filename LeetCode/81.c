bool search(int* nums, int numsSize, int target) {
    int first = 0;
    int end = numsSize;
    while (first != end) {
        int mid = (first + end) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[first] < nums[mid]) {
            if (nums[first] <= target && target < nums[mid])
                end = mid;
            else
                first = mid + 1;
        }
        else if (nums[first] > nums[mid]) {
            if (nums[mid] < target && target <= nums[end - 1])
                first = mid + 1;
            else
                end = mid;
        }
        else {
            first++;
        }
    }
    return false;
}