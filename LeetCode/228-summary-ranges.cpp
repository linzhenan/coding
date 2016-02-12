class Solution {
public:
    void push_res(vector<string> &res, int lastbegin, int lastend) {
        if (lastbegin == lastend) {
            stringstream ss;
            ss << lastbegin;
            res.push_back(ss.str());
        }
        else {
            stringstream ss;
            ss << lastbegin;
            ss << "->";
            ss << lastend;
            res.push_back(ss.str());
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (!n)
            return res;
        int lastbegin = nums[0];
        int lastend = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == lastend + 1) {
                lastend = nums[i];
                continue;
            }
            else {
                push_res(res, lastbegin, lastend);
                lastbegin = lastend = nums[i];
            }
        }
        push_res(res, lastbegin, lastend);
    }
};