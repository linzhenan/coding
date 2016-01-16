class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0)
            return 0;
        int candies[n];
        for (int i = 0; i < n; i++)
            candies[i] = 1;
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += candies[i];
        return sum;
    }
};