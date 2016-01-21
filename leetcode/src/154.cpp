//Find Minimum in Rotated Sorted Array II

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		mid = (left + right) / 2;
		while (left < right) {
			if (nums[mid] > nums[right]) {
				left = mid + 1;
				mid = (left + right) / 2;
			}
			else if (nums[mid] == nums[right]) {
				int nleft = mid;
				int nright = mid;
				while (left < nleft && nums[nleft - 1] == nums[nleft])
					nleft--;
				while (nright < right && nums[nright] == nums[nright + 1])
					nright++;
				if (left == nleft && nright == right)
					return nums[left];
				else if (left == nleft)
					mid = nright + 1;
				else
					mid = nleft - 1;
			}
			else {
				right = mid;
				mid = (left + right) / 2;
			}
		}
		mid = (left + right) / 2;
		return nums[mid];
	}
};