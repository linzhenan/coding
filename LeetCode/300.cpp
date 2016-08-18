#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int lengthOfLIS_n2(vector<int>& nums) {
		int n = nums.size();
		vector<int> DP(n, 1);
		vector<int> Parent(n, -1);
		int maxlen = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i] && DP[j] + 1 > DP[i]) {
					DP[i] = DP[j] + 1;
					Parent[i] = j;
				}
			}
			maxlen = max(maxlen, DP[i]);
		}
		int pos = n - 1;
		while (pos >= 0) {
			cout << nums[pos] << " ";
			pos = Parent[pos];
		}
		return maxlen;
	}
	int lengthOfLIS(vector<int>& nums) {
		vector<int> s;
		vector<int> sidx;
		vector<int> parent;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (s.size() == 0) {
				s.push_back(nums[i]);
				sidx.push_back(i);
				parent.push_back(-1);
			}
			else {
				if (nums[i] > s[s.size() - 1]) {
					parent.push_back(s.size() - 1);
					s.push_back(nums[i]);
					sidx.push_back(i);
				}
				else {
					auto it = lower_bound(s.begin(), s.end(), nums[i]);
					int idx = it - s.begin();
					s[idx] = nums[i];
					sidx[idx] = i;
					parent[idx] = idx - 1;
				}
			}
		}
		int pos = s.size() - 1;
		while (pos >= 0) {
			cout << nums[sidx[pos]];
			pos = parent[sidx[pos]];
		}
		return s.size();
	}
};

int main() {
	Solution slu;
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	slu.lengthOfLIS(nums);
	return 0;
}