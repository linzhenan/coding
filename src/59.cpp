//Spiral Matrix II

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));
		int x_start = 0, x_end = n - 1;
		int y_start = 0, y_end = n - 1;
		int num = 0;
		while (true) {
			for (int j = x_start; j <= x_end; j++)
				result[y_start][j] = ++num;
			if (++y_start > y_end)
				break;
			for (int i = y_start; i <= y_end; i++)
				result[i][x_end] = ++num;
			if (--x_end < x_start)
				break;
			for (int j = x_end; j >= x_start; j--)
				result[y_end][j] = ++num;
			if (--y_end < y_start)
				break;
			for (int i = y_end; i >= y_start; i--)
				result[i][x_start] = ++num;
			if (++x_start > x_end)
				break;
		}
		return result;
	}
};