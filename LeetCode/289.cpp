//Game of Life

class Solution {
public:
	int livenum(vector<vector<int>>& board, int x, int y, int width, int height) {
		int num = 0;
		if (y > 0) {
			if (x > 0)
				if (board[y - 1][x - 1])
					num++;
			if (board[y - 1][x])
				num++;
			if (x < width - 1)
				if (board[y - 1][x + 1])
					num++;
		}
		if (x > 0)
			if (board[y][x - 1])
				num++;
		if (x < width - 1)
			if (board[y][x + 1])
				num++;
		if (y < height - 1) {
			if (x > 0)
				if (board[y + 1][x - 1])
					num++;
			if (board[y + 1][x])
				num++;
			if (x < width - 1)
				if (board[y + 1][x + 1])
					num++;
		}
		return num;
	}
	void gameOfLife(vector<vector<int>>& board) {
		int height = board.size();
		if (height == 0)
			return;
		int width = board[0].size();
		if (width == 0)
			return;
		vector<vector<int>> boardcopy = vector<vector<int>>(board);

		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++) {
				int num = livenum(boardcopy, x, y, width, height);
				if (boardcopy[y][x]) {
					if (num < 2)
						board[y][x] = 0;
					else if (num > 3)
						board[y][x] = 0;
				}
				else {
					if (num == 3)
						board[y][x] = 1;
				}
			}
	}
};