#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow_nlogn(vector<int>& nums, int k) {
		set<int> wnd;
		vector<int> res;
		int n = nums.size();
		if (n == 0)
			return res;
		for (int i = 0; i < n && i < k; i++)
			wnd.insert(nums[i]);
		res.push_back(*wnd.rbegin());
		for (int i = k; i < n; i++) {
			wnd.erase(nums[i - k]);
			wnd.insert(nums[i]);
			res.push_back(*wnd.rbegin());
		}

		return res;
	}
	vector<int> maxSlidingWindow_n2(vector<int>& nums, int k) {
		vector<int> res;
		int n = nums.size();
		if (n == 0)
			return res;
		int i = 0;
		int j = min(n - 1, k - 1);
		for (int j = min(n - 1, k - 1); j < n; j++) {
			int maxnum = nums[j];
			for (int i = j - 1; i > max(j - k, -1); i--) {
				if (nums[i] > maxnum)
					maxnum = nums[i];
			}
			res.push_back(maxnum);
		}
		return res;
	}
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> res;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (!dq.empty() && dq.front() == i - k)
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] <= nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1 || i == n - 1)
				res.push_back(nums[dq.front()]);
		}
		return res;
	}
};
int main() {
	//vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> nums = { 1, 3};
	Solution slu;
	slu.maxSlidingWindow_nlogn(nums, 3);
	slu.maxSlidingWindow_n2(nums, 3);
	slu.maxSlidingWindow(nums, 3);
	return 0;
}