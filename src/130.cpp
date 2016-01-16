class Solution {
public:
    void flip(vector<vector<char>>& board, int w, int h, int x, int y) {
        if (board[y][x] == 'X')
            return;
        board[y][x] = 'X';
        if (x > 0)
            flip(board, w, h, x - 1, y);
        if (x < w - 1)
            flip(board, w, h, x + 1, y);
        if (y > 0)
            flip(board, w, h, x, y - 1);
        if (y < h - 1)
            flip(board, w, h, x, y + 1);
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& v, int w, int h, int x, int y) {
        //should be 'O'
        v[x][y] = true;
        if (board[y][x] == 'X')
            return true;
        if (x == 0 || x == w - 1 || y == 0 || y == h - 1)
            return false;
        if (!v[x][y - 1] && !dfs(board, v, w, h, x, y - 1))
            return false;
        if (!v[x][y + 1] && !dfs(board, v, w, h, x, y + 1))
            return false;
        if (!v[x - 1][y] && !dfs(board, v, w, h, x - 1, y))
            return false;
        if (!v[x + 1][y] && !dfs(board, v, w, h, x + 1, y))
            return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        if (h == 0)
            return;
        int w = board[0].size();
        if (w == 0)
            return;
        vector<vector<bool>> v = vector<vector<bool>>(h, vector<bool>(w, false));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (dfs(board, v, w, h, x, y))
                    flip(board, w, h, x, y);
    }
};