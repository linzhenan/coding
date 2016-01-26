//Find Minimum in Rotated Sorted Array

//See also Search in Rotated Sorted Array

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left < right) {
			mid = (left + right) / 2;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;//note!
		}
		mid = (left + right) / 2;
		return nums[mid];
	}
};