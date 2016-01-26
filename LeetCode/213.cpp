//House Robber II

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];
		vector<int> f = vector<int>(n, 0);
		vector<int> g = vector<int>(n, 0);

		f[0] = 0;
		g[0] = 0;
		for (int i = 0; i < n - 1; i++) {
			f[i + 1] = g[i] + nums[i + 1];
			g[i + 1] = max(f[i], g[i]);
		}
		int max1 = f[n - 1];

		f[0] = nums[0];
		g[0] = 0;
		for (int i = 0; i < n - 1; i++) {
			f[i + 1] = g[i] + nums[i + 1];
			g[i + 1] = max(f[i], g[i]);
		}
		int max2 = g[n - 1];

		return max(max1, max2);
	}
};