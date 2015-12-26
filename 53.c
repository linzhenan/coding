//Maximum Subarray

int max(int a, int b) {
	return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize) {
	int largestSum = 0x80000000;
	int f = 0;
	for (int i = 0; i < numsSize; i++) {
		f = max(nums[i], f + nums[i]);
		if (f > largestSum)
			largestSum = f;
	}
	return largestSum;
}