//Contains Duplicate II

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		k = min(k, n - 1);
		unordered_map<int, int> map;
		int i;
		for (i = 0; i <= k; i++) {
			map[nums[i]]++;
			if (map[nums[i]] > 1)
				return true;
		}
		int j = 0;
		while (i < n) {
			map[nums[j]]--;
			map[nums[i]]++;
			if (map[nums[i]] > 1)
				return true;
			j++;
			i++;
		}
		return false;
	}
};