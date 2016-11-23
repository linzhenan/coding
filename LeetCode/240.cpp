#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool dfs(vector<vector<int>>& matrix, int target, int y0, int x0, int y1, int x1) {
		int y = (y0 + y1) / 2;
		int x = (x0 + x1) / 2;
		if (x0 > x1 || y0 > y1)
			return false;
		else if (matrix[y][x] == target)
			return true;
		else if (matrix[y][x] > target) {
			return dfs(matrix, target, y0, x0, y - 1, x - 1) ||
				dfs(matrix, target, y0, x, y - 1, x1) ||
				dfs(matrix, target, y, x0, y1, x - 1);
		}
		else {
			return dfs(matrix, target, y + 1, x + 1, y1, x1) ||
				dfs(matrix, target, y0, x + 1, y, x1) ||
				dfs(matrix, target, y + 1, x0, y1, x);
		}
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		return dfs(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
	}
};

int main() {
	vector<vector<int>> mat = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	};
	Solution slu;
	bool ret = slu.searchMatrix(mat, 5);
	ret = slu.searchMatrix(mat, 20);
	return 0;
}