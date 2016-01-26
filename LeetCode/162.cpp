//Find Peak Element

class Solution {
public:
	int dfs(vector<int>& nums, int start, int end) {
		if (end < start)
			return -1;
		int mid = (start + end) / 2;
		if (mid == 0) {
			if (nums[0] > nums[1])
				return 0;
			else
				return -1;
		}
		else if (mid == nums.size() - 1) {
			if (nums[mid] > nums[mid - 1])
				return mid;
			else
				return -1;
		}
		else {
			if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
				return mid;
			if (nums[mid - 1] > nums[mid])
				return dfs(nums, start, mid);
			if (nums[mid] < nums[mid + 1])
				return dfs(nums, mid + 1, end);
		}
	}
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;
		if (nums.size() == 1)
			return 0;
		if (nums.size() == 2)
			if (nums[0] > nums[1])
				return 0;
			else
				return 1;
		return dfs(nums, 0, nums.size() - 1);
	}
};