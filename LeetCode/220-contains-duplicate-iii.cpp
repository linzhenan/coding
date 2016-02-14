class Solution {
private:
    static bool cmp(pair<long, int> a, pair<long, int> b) {
        return a.first < b.first;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2)
            return false;
        vector<pair<long, int>> p;
        for (int i = 0; i < n; i++)
            p.push_back({(long)nums[i], i});
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while (j < n) {
                if (p[j].first - p[i].first > t)
                    break;
                if (p[j].second - p[i].second <= k && p[j].second - p[i].second >= -1 * (long)k)
                    return true;
                j++;
            }
        }
        return false;
    }
};