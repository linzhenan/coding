//Combination Sum III

class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& path, int i, int j, int k, int n) {
		if (n == 0 && k == 0) {
			res.push_back(path);
		}
		else if (i <= j && i <= n && k > 0) {
			for (int num = i; num <= j; num++) {
				path.push_back(num);
				dfs(res, path, num + 1, j, k - 1, n - num);
				path.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> path;
		int sum = 0;
		for (int i = 1; i <= k; i++)
			sum += i;
		if (n < sum)
			return res;
		sum = 0;
		for (int i = 9; i >= 9 - (k - 1); i--)
			sum += i;
		if (sum < n)
			return res;
		dfs(res, path, 1, 9, k, n);
		return res;
	}
};