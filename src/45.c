//Jump Game II
int jump(int* nums, int numsSize) {
	if (numsSize == 1)
		return 0;
	int left = 0;
	int right = 0;
	int step = 0;
	while (left <= right) {
		step++;
		const int old_right = right;
		for (int i = left; i <= old_right; i++) {
			int new_right = i + nums[i];
			if (new_right >= numsSize - 1)
				return step;
			if (new_right > right)
				right = new_right;
		}
		left = old_right + 1;
	}
	return -1;
}