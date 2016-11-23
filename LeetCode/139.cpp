class Solution {
public:
	bool wordBreak_n2(string s, unordered_set<string>& wordDict) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
		for (int i = 0; i < n; i++)
			dp[i][0] = true;
		for (int len = 1; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				string sub = s.substr(i, len);
				if (wordDict.find(sub) != wordDict.end())
					dp[i][len] = true;
				else {
					for (int l = 1; l < len && !dp[i][len]; l++)
						dp[i][len] = dp[i][l] && dp[i + l][len - l];
				}
			}
		}
		return dp[0][n];
	}
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.size();
		vector<bool> dp(n, false);
		for (int i = 0; i < n; i++) {
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
				dp[i] = true;
				continue;
			}
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n - 1];
	}
};