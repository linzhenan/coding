class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        res.push_back({1});
        if (numRows == 1)
            return res;
        res.push_back({1, 1});
        if (numRows == 2)
            return res;
        vector<int> lastRowNum = {1, 1};
        for (int row = 3; row <= numRows; row++) {
            vector<int> rowNum = {1};
            for (int col = 2; col <= row - 1; col++) {
                rowNum.push_back(lastRowNum[col - 2] + lastRowNum[col - 1]);
            }
            rowNum.push_back(1);
            res.push_back(rowNum);
            lastRowNum = rowNum;
        }
        return res;
    }
};