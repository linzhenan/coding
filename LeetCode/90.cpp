//Subsets II

class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> comb, int start) {
		res.push_back(comb);
		for (int i = start; i < nums.size(); i++) {
			if (i != start && nums[i] == nums[i - 1])
				continue;
			comb.push_back(nums[i]);
			dfs(res, nums, comb, i + 1);
			comb.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> comb;
		dfs(res, nums, comb, 0);
		return res;
	}
};