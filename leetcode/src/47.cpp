class Solution {
public:
	void dfs(vector<vector<int>>& res, vector<int>& nums, vector<pair<int, int>>& pairs, vector<int>& comb) {
		if (comb.size() == nums.size()) {
			res.push_back(comb);
		}
		else {
			for (auto it = pairs.begin(); it != pairs.end(); it++) {
				if (it->second) {
					comb.push_back(it->first);
					it->second--;
					dfs(res, nums, pairs, comb);
					it->second++;
					comb.pop_back();
				}
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;

		sort(nums.begin(), nums.end());

		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(nums[i]) != map.end())
				map[nums[i]]++;
			else
				map[nums[i]] = 1;
		}

		vector<pair<int, int>> pairs;
		pairs.push_back({ nums[0], map[nums[0]] });
		for (int i = 1; i < nums.size(); i++)
			if (nums[i] == nums[i - 1])
				continue;
			else
				pairs.push_back({ nums[i], map[nums[i]] });

		vector<int> comb;
		dfs(res, nums, pairs, comb);
		return res;
	}
};