#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
	int numSquares_n2(int n) {
		vector<int> dp(n + 1, 0);
		for (int i = 0; i * i <= n; i++)
			dp[i * i] = 1;
		for (int i = 2; i <= n; i++) {
			if (dp[i] == 1)
				continue;
			dp[i] = dp[1] + dp[i - 1];
			for (int j = 2; j <= i / 2; j++)
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
		return dp[n];
	}
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		int i = 1;
		dp[0] = 0;
		while (i * i <= n) {
			for (int j = i * i; j <= n; j++)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
			i++;
		}
		return dp[n];
	}
};