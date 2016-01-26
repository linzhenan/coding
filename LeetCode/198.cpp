class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int n = nums.size();
        vector<int> f = vector<int>(n, 0);
        vector<int> g = vector<int>(n, 0);
        f[0] = nums[0];
        g[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            f[i + 1] = g[i] + nums[i + 1];
            g[i + 1] = max(f[i], g[i]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};