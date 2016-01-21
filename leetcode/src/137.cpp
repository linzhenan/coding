class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        for (auto e : map)
            if (e.second == 1)
                return e.first;
    }
};