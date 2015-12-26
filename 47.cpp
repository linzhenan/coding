//Permutations II

//timeout
/*
class Solution {
public:
	void dfs(vector<vector<int>>& result, vector<int>& nums, bool *use, vector<int>& per, int n) {
		if (nums.size() == n) {
			if (find(result.begin(), result.end(), per) == result.end())
				result.push_back(per);
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (use[i])
					continue;
				use[i] = 1;
				per.push_back(nums[i]);
				dfs(result, nums, use, per, n + 1);
				per.pop_back();
				use[i] = 0;
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		bool use[nums.size()] = { 0 };
		vector<int> per;

		dfs(result, nums, use, per, 0);

		return result;
	}
};
*/