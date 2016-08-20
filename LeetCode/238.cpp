#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> output(n, 1);
		int front = 1;
		int end = 1;
		for (int i = 0; i < n - 1; i++) {
			front *= nums[i];
			end *= nums[n - 1 - i];
			output[i + 1] *= front;
			output[n - 1 - i - 1] *= end;
		}
		return output;
	}
};