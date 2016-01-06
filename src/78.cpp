//Subsets

class Solution {
public:
	void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& subset, int end) {
		if (end == -1) {
			vector<int> tmp = subset;
			sort(tmp.begin(), tmp.end());
			result.push_back(tmp);
		}
		else {
			dfs(result, nums, subset, end - 1);
			subset.push_back(nums[end]);
			dfs(result, nums, subset, end - 1);
			subset.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> subset;
		dfs(result, nums, subset, nums.size() - 1);
		return result;
	}
};