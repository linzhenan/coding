#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int n = nums.size();
		unsigned int flag = 0;
		vector<int> res;
		vector<int> grp1, grp2;
		int num1 = 0;
		int num2 = 0;
		int offset = 0;
		for (int i = 0; i < n; i++) {
			flag ^= nums[i];
		}
		while (flag > 1) {
			flag >>= 1;
			offset++;
		}
		flag <<= offset;
		for (int i = 0; i < n; i++) {
			if (nums[i] & flag) {
				num1 ^= nums[i];
				grp1.push_back(nums[i]);
			}
			else {
				num2 ^= nums[i];
				grp2.push_back(nums[i]);
			}
		}
		res.push_back(num1);
		res.push_back(num2);
		return res;
	}
};
int main() {
	vector<int> nums = { 1, 2, 1, 3, 2, 5 };
	Solution slu;
	vector<int> res = slu.singleNumber(nums);
	return 0;
}