//Best Time to Buy and Sell Stock IV

http://www.cnblogs.com/maples7/p/4350047.html


class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		if (k * 2 > prices.size())
			return noKLimit(prices);
		int f[1 + 2 * k];
		f[0] = 0;
		for (int i = 1; i <= 2 * k; i++)
			f[i] = INT_MIN;

		for (int i = 0; i < prices.size(); i++)
			for (int j = 1; j <= min(2 * k, i + 1); j++)
				f[j] = max(f[j], f[j - 1] + prices[i] * (j % 2 ? -1 : 1));
		return f[2 * k];
	}
	int noKLimit(vector<int>& prices) {
		int profit = 0;
		for (int i = 0; i < prices.size() - 1; i++)
			if (prices[i + 1] > prices[i])
				profit += prices[i + 1] - prices[i];
		return profit;
	}
};