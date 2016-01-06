//Gray Code

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);
		stack<int> stk;
		stk.push(0);
		for (int i = 0; i < n; i++) {
			while (!stk.empty()) {
				res.push_back(stk.top() + (1 << i));
				stk.pop();
			}
			for (int j = 0; j < res.size(); j++)
				stk.push(res[j]);
		}
		return res;
	}
};