class Solution {
private:
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (!h) return 0;
        int w = matrix[0].size();
        if (!w) return 0;
        
        int maxVal = 0;
        
        vector<vector<int>> side = vector<vector<int>>(h, vector<int>(w, 0));
        for (int x = 0; x < w; x++)
            if (matrix[0][x] == '1') {
                side[0][x] = 1;
                maxVal = 1;
            }
        for (int y = 0; y < h; y++)
            if (matrix[y][0] == '1') {
                side[y][0] = 1;
                maxVal = 1;
            }
        for (int y = 1; y < h; y++)
            for (int x = 1; x < w; x++) {
                if (matrix[y][x] == '1') {
                    side[y][x] = min3(side[y - 1][x - 1], side[y - 1][x], side[y][x - 1]) +1;
                    maxVal = max(maxVal, side[y][x] * side[y][x]);
                }
            }
            
        return maxVal;
    }
};