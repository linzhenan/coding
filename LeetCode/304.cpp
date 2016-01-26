//Range Sum Query 2D - Immutable

class NumMatrix {
public:
	vector<vector<int>> m;
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.size() == 0)
			return;
		if (matrix[0].size() == 0)
			return;
		m = vector<vector<int>>(matrix);
		int h = matrix.size();
		int w = matrix[0].size();
		for (int i = 0; i < h; i++)
			for (int j = 1; j < w; j++)
				m[i][j] += m[i][j - 1];
		for (int i = 1; i < h; i++)
			for (int j = 0; j < w; j++)
				m[i][j] += m[i - 1][j];
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0)
			return m[row2][col2];
		if (row1 == 0)
			return m[row2][col2] - m[row2][col1 - 1];
		if (col1 == 0)
			return m[row2][col2] - m[row1 - 1][col2];
		return m[row2][col2] - m[row2][col1 - 1] - m[row1 - 1][col2] + m[row1 - 1][col1 - 1];
	}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);