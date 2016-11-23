#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<int> num(nums.size() + 2);
		int n = 1;
		for (int x : nums) {
			if (x > 0)
				num[n++] = x;
		}
		num[0] = num[n++] = 1;
		vector<vector<int>> dp(n, vector<int>(n));
		for (int k = 2; k < n; k++) {
			for (int left = 0; left < n - k; left++) {
				int right = left + k;
				for (int i = left + 1; i < right; i++) {
					dp[left][right] = max(dp[left][right], num[left] * num[i] * num[right] + dp[left][i] + dp[i][right]);
				}
			}
		}
		return dp[0][n - 1];
	}
};
int main() {
	vector<int> nums = { 3, 1, 5, 8 };
	Solution slu;
	cout << slu.maxCoins(nums) << endl;
	return 0;
}