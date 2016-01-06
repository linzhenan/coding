class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& cand, vector<int>& comb, int target, int start) {
		if (target == 0) {
			res.push_back(comb);
		}
		else if (target > 0) {
			for (int i = start; i < cand.size() && cand[i] <= target; i++) {
				if (i > start && cand[i] == cand[i - 1])
					continue;
				comb.push_back(cand[i]);
				dfs(res, cand, comb, target - cand[i], i + 1);
				comb.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		if (candidates.size() == 0)
			res;
		sort(candidates.begin(), candidates.end());
		vector<int> comb;
		dfs(res, candidates, comb, target, 0);
		return res;
	}
};