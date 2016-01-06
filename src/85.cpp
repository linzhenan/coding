//Maximal Rectangle

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (!matrix.size() || !matrix[0].size())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int height[n + 1] = { 0 };
		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1')
					height[j]++;
				else
					height[j] = 0;
			}
			stack<int> stk;
			for (int j = 0; j < n + 1;) {
				if (stk.empty() || height[stk.top()] < height[j]) {
					stk.push(j++);
				}
				else {
					int tmp = stk.top();
					stk.pop();
					int area = height[tmp] * (stk.empty() ? j : j - stk.top() - 1);
					result = max(result, area);
				}
			}
		}
		return result;
	}
};