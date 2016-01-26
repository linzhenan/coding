//Number of Islands

class Solution {
public:
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y, int w, int h) {
		if (0 <= x && x < w && 0 <= y && y < h) {
			if (grid[y][x] == '1' && !visit[y][x]) {
				visit[y][x] = true;
				dfs(grid, visit, x - 1, y, w, h);
				dfs(grid, visit, x + 1, y, w, h);
				dfs(grid, visit, x, y - 1, w, h);
				dfs(grid, visit, x, y + 1, w, h);
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int num = 0;
		int h = grid.size();
		int w = grid[0].size();
		vector<vector<bool>> visit = vector<vector<bool>>(h, vector<bool>(w, false));
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				if (!visit[y][x] && grid[y][x] == '1') {
					num++;
					dfs(grid, visit, x, y, w, h);
				}
		return num;
	}
};