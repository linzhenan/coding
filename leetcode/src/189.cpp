//Rotate Array

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;//consider k > n
		nums.insert(nums.end(), nums.begin(), nums.begin() + n - k);
		nums.erase(nums.begin(), nums.begin() + n - k);
	}
};