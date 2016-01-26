class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        if (rowIndex == 0)
            return res;
        res.push_back(1);
        if (rowIndex == 1)
            return res;
        vector<int> last = res;
        for (int row = 2; row <= rowIndex; row++) {
            res.clear();
            res.push_back(1);
            for (int col = 1; col < row; col++)
                res.push_back(last[col - 1] + last[col]);
            res.push_back(1);
            last = res;
        }
        return res;
    }
};