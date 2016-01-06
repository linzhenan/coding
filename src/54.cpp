//Spiral Matrix

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty())
			return result;
		int x_begin = 0, x_end = matrix[0].size() - 1;
		int y_begin = 0, y_end = matrix.size() - 1;
		while (true) {
			for (int j = x_begin; j <= x_end; j++)
				result.push_back(matrix[y_begin][j]);
			if (++y_begin > y_end)
				break;
			for (int i = y_begin; i <= y_end; i++)
				result.push_back(matrix[i][x_end]);
			if (x_begin > --x_end)
				break;
			for (int j = x_end; j >= x_begin; j--)
				result.push_back(matrix[y_end][j]);
			if (y_begin > --y_end)
				break;
			for (int i = y_end; i >= y_begin; i--)
				result.push_back(matrix[i][x_begin]);
			if (++x_begin > x_end)
				break;
		}
		return result;
	}
};