class Solution {
public:
	int max3(int a, int b, int c) {
		int tmp = max(a, b);
		return max(tmp, c);
	}
	int min3(int a, int b, int c) {
		int tmp = min(a, b);
		return min(tmp, c);
	}
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int minp[n];
		int maxp[n];
		minp[0] = nums[0];
		maxp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			maxp[i] = max3(maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i]);
			minp[i] = min3(maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i]);
			res = max(res, maxp[i]);
		}
		return res;
	}
};