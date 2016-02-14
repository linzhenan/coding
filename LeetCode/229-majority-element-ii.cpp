class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (!n)
            return res;
        int num1 = nums[0], num2, cnt1 = 1, cnt2 = 0;
        int i;
        for (i = 1; i < n; ) {
            if (nums[i] == num1) {
                cnt1++;
                i++;
            }
            else {
                num2 = nums[i];
                cnt2 = 1;
                i++;
                break;
            }
        }
        if (cnt2 == 0) {
            if (cnt1 > n / 3)
                res.push_back(num1);
            return res;
        }
        for (; i < n; i++) {
            if (nums[i] == num1) {
                cnt1++;
            }
            else if (nums[i] == num2) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                cnt1 = 1;
                num1 = nums[i];
            }
            else if (cnt2 == 0) {
                cnt2 = 1;
                num2 = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
        }
        if (cnt1 > n / 3)
            res.push_back(num1);
        if (cnt2 > n / 3)
            res.push_back(num2);
        return res;
    }
};