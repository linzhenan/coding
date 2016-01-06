//Jump Game
bool canJump(int* nums, int numsSize) {
	if (!numsSize)
		return false;

	int left = 0;
	int right = 0;
	while (left <= right) {
		const int old_right = right;
		for (int i = left; i <= old_right; i++) {
			int new_right = i + nums[i];
			if (new_right >= right) {
				right = new_right;
				if (right >= numsSize - 1)
					return true;
			}
		}
		left = old_right + 1;
	}
	return false;
}