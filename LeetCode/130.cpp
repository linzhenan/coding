//Surrounded Regions

//DFS will meet stack overflow and get Runtime Error

class Solution {
private:
	queue<pair<int, int>> q;
public:
	void dfs(vector<vector<char>>& board, int x, int y, int w, int h) {
		if (0 <= x && x < w && 0 <= y && y < h && board[y][x] == 'O') {
			board[y][x] = '#';
			dfs(board, x - 1, y, w, h);
			dfs(board, x + 1, y, w, h);
			dfs(board, x, y - 1, w, h);
			dfs(board, x, y + 1, w, h);
		}
	}
	void pushQ(vector<vector<char>>&board, int x, int y, int w, int h) {
		if (0 <= x && x < w && 0 <= y && y < h && board[y][x] == 'O') {
			board[y][x] = '#';
			q.push(pair<int, int>(x, y));
		}
	}
	void bfs(vector<vector<char>>& board, int x, int y, int w, int h) {
		if (board[y][x] == 'O') {
			board[y][x] = '#';
			q.push(pair<int, int>(x, y));
		}
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			pushQ(board, p.first - 1, p.second, w, h);
			pushQ(board, p.first + 1, p.second, w, h);
			pushQ(board, p.first, p.second - 1, w, h);
			pushQ(board, p.first, p.second + 1, w, h);
		}
	}
	void solve(vector<vector<char>>& board) {
		int h = board.size();
		if (h == 0)
			return;
		int w = board[0].size();
		if (w == 0)
			return;

		for (int x = 0; x < w; x++) {
			//dfs(board, x, 0, w, h);
			//dfs(board, x, h - 1, w, h);
			bfs(board, x, 0, w, h);
			bfs(board, x, h - 1, w, h);
		}
		for (int y = 0; y < h; y++) {
			//dfs(board, 0, y, w, h);
			//dfs(board, w - 1, y, w, h);
			bfs(board, 0, y, w, h);
			bfs(board, w - 1, y, w, h);
		}
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				if (board[y][x] == 'O')
					board[y][x] = 'X';
				else if (board[y][x] == '#')
					board[y][x] = 'O';
			}
	}
};