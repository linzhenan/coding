class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size() || gas.size() == 0 || cost.size() == 0)
            return -1;
        int n = gas.size();
        int start = 0;
        int total = 0;
        int sum = -1;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            if (sum < 0) {
                sum = diff;
                start = i;
            }
            else {
                sum += diff;
            }
        }
        return total < 0 ? -1 : start;
    }
};