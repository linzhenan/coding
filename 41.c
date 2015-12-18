void swap(int *a, int *b) {
	if (a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
void bucketSort(int *nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		while (nums[i] != i + 1) {
			if (nums[i] <= 0 || nums[i] > numsSize || nums[i] == i + 1)
				break;
			if (nums[i] != nums[nums[i] - 1])
				swap(&nums[i], &nums[nums[i] - 1]);
			else
				nums[i] = -1;
		}
	}
}
int firstMissingPositive(int* nums, int numsSize) {
	bucketSort(nums, numsSize);
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != i + 1)
			return i + 1;
	}
	return numsSize + 1;
}