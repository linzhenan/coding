//Maximum Gap

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int minVal = INT_MAX;
		int maxVal = INT_MIN;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] < minVal)
				minVal = nums[i];
			if (nums[i] > maxVal)
				maxVal = nums[i];
		}
		double interval = (double)(maxVal - minVal) / (n - 1);
		int bucketNum = n - 1;
		vector<pair<int, int>> bucket = vector<pair<int, int>>(bucketNum, pair<int, int>({ INT_MIN, INT_MAX }));
		for (int i = 0; i < n; i++) {
			if (nums[i] == minVal || nums[i] == maxVal)
				continue;
			int idx = (nums[i] - minVal) / interval;//note!
			if (nums[i] > bucket[idx].first)
				bucket[idx].first = nums[i];
			if (nums[i] < bucket[idx].second)
				bucket[idx].second = nums[i];
		}
		int maxGap = 0;
		int lastMax = minVal;
		for (auto p : bucket) {
			if (p.first == INT_MIN)
				continue;
			maxGap = max(maxGap, p.second - lastMax);
			lastMax = p.first;
		}
		maxGap = max(maxGap, maxVal - lastMax);
		return maxGap;
	}
};