#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> twoSum_nlogn(vector<int>& numbers, int target) {
		vector<int> res;
		int n = numbers.size();
		for (int i = 0; i < n - 1; i++) {
			auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
			if (it == numbers.end())
				continue;
			if (numbers[i] + *it == target) {
				res.push_back(i + 1);
				res.push_back(it - numbers.begin() + 1);
				break;
			}
		}
		return res;
	}
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res;
		int i = 0, j = numbers.size() - 1;
		while (i < j) {
			if (numbers[i] + numbers[j] > target)
				j--;
			else if (numbers[i] + numbers[j] < target)
				i++;
			else {
				res.push_back(i + 1);
				res.push_back(j + 1);
				break;
			}
		}
		return res;
	}
};