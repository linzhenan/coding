//Combinations

class Solution {
public:
	void dfs(vector<vector<int>> &result, vector<int> &comb, int n, int k, int start, int count) {
		if (count == k) {
			result.push_back(comb);
		}
		else {
			for (int i = start; i <= n; i++) {
				comb.push_back(i);
				dfs(result, comb, n, k, i + 1, count + 1);
				comb.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> comb;
		dfs(result, comb, n, k, 1, 0);
		return result;
	}
};