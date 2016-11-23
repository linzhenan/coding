class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> map;
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++)
			map[nums1[i]] = false;
		for (int i = 0; i < nums2.size(); i++) {
			if (map.find(nums2[i]) != map.end() && !map[nums2[i]]) {
				res.push_back(nums2[i]);
				map[nums2[i]] = true;
			}
		}
		return res;
	}
};