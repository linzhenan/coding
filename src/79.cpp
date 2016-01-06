//Word Search

class Solution {
public:
	bool dfs(vector<vector<char>>& board, vector<vector<char>>& used, int i, int j, int m, int n, string word, int pos) {
		if (pos == word.size())
			return true;
		if (i < 0 || i >= m || j < 0 || j >= n)
			return false;
		if (used[i][j])
			return false;
		if (board[i][j] != word[pos])
			return false;

		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		used[i][j] = 1;
		bool ret = dfs(board, used, i - 1, j, m, n, word, pos + 1) ||
			dfs(board, used, i + 1, j, m, n, word, pos + 1) ||
			dfs(board, used, i, j - 1, m, n, word, pos + 1) ||
			dfs(board, used, i, j + 1, m, n, word, pos + 1);
		used[i][j] = 0;
		return ret;
	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<char>> used = board;
		int m = used.size();
		int n = used[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				used[i][j] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (dfs(board, used, i, j, m, n, word, 0))
					return true;
		return false;
	}
};