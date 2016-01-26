//Minimum Size Subarray Sum

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int minWidth = INT_MAX;
		int i = 0;
		int j = 0;
		int sum = 0;
		int n = nums.size();
		for (j = 0; j < n; j++) {
			sum += nums[j];
			while (sum >= s && i <= j) {
				minWidth = min(minWidth, j - i + 1);
				if (minWidth == 1)
					return 1;
				sum -= nums[i++];
			}
		}
		if (minWidth == INT_MAX)
			return 0;
		else
			return minWidth;
	}
};