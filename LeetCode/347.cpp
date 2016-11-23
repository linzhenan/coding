class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		int n = nums.size();
		map<int, int> hash;
		for (int i = 0; i < nums.size(); i++)
			hash[nums[i]]++;
		vector<vector<int>> freq(n + 1);
		for (auto e : hash)
			freq[e.second].push_back(e.first);
		for (int i = n; i >= 0 && k > 0; i--) {
			k -= freq[i].size();
			for (auto num : freq[i])
				res.push_back(num);
		}
		return res;
	}
};