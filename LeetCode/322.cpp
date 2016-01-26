//Coin Change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0 || amount == 0)
            return 0;
        unordered_map <int, bool> map;
        for (auto val : coins)
            map[val] = true;
        int f[amount + 1];
        for (int i = 0; i <= amount; i++)
            f[i] = INT_MAX;
        for (int i = 1; i <= amount; i++) {
            //if (find(coins.begin(), coins.end(), i) != coins.end()) {
            if (map.find(i) != map.end()) {
                f[i] = 1;
            }
            else {
                /*
                for (int j = 1; j <= i / 2; j++) {
                    if (f[j] != INT_MAX && f[i - j] != INT_MAX)
                        f[i] = min(f[i], f[j] + f[i -j]);
                }
                */
                for (int j = 0; j < coins.size(); j++) {
                    if (i - coins[j] > 0) {
                        if (f[coins[j]] != INT_MAX && f[i - coins[j]] != INT_MAX)
                            f[i] = min(f[i], f[coins[j]] + f[i - coins[j]]);
                    }
                }
            }
        }
        if (f[amount] == INT_MAX)
            return -1;
        else
            return f[amount];
    }
};