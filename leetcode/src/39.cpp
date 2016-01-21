//Combination Sum

class Solution {
private:
	void dfs(vector<vector<int>>& res, vector<int>& cand, vector<int>& comb, int target, int start) {
		if (target == 0) {
			res.push_back(comb);
		}
		else if (target > 0) {
			for (int i = start; i < cand.size() && cand[i] <= target; i++) {
				comb.push_back(cand[i]);
				dfs(res, cand, comb, target - cand[i], i);
				comb.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		if (candidates.size() == 0)
			res;
		sort(candidates.begin(), candidates.end());
		vector<int> comb;
		dfs(res, candidates, comb, target, 0);
		return res;
	}
};