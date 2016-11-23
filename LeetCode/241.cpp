#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> diffWaysToCompute(string str) {
		vector<int> res;
		int n = str.size();
		for (int i = 0; i < n; i++) {
			char ch = str[i];
			if (ispunct(ch)) {
				vector<int> left = diffWaysToCompute(str.substr(0, i));
				vector<int> right = diffWaysToCompute(str.substr(i + 1, n - i - 1));
				for (int var1 : left) {
					for (int var2 : right) {
						res.push_back(ch == '*' ? var1 * var2 : (ch == '+' ? var1 + var2 : var1 - var2));
					}
				}
			}
		}
		if (res.size() == 0) {
			int num = atoi(str.c_str());
			res.push_back(num);
		}
		return res;
	}
};
int main() {
	Solution slu;
	string s1 = "2-1-1";
	string s2 = "2*3-4*5";
	vector<int> res = slu.diffWaysToCompute(s1);
	res = slu.diffWaysToCompute(s2);
	return 0;
}