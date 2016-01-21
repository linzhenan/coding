class Solution {
public:
	int minCut(string s) {
		if (s.size() <= 1)
			return 0;
		int n = s.size();
		vector<vector<bool>> isp = vector<vector<bool>>(n, vector<bool>(n + 1, false));
		for (int pos = 0; pos < n; pos++) {
			isp[pos][0] = true;
			isp[pos][1] = true;
		}
		for (int len = 2; len <= n; len++)
			for (int pos = 0; pos <= n - len; pos++)
				isp[pos][len] = isp[pos + 1][len - 2] && s[pos] == s[pos + len - 1];
		vector<vector<int>> mincut = vector<vector<int>>(n, vector<int>(n + 1, 0));
		for (int len = 2; len <= n; len++) {
			for (int pos = 0; pos <= n - len; pos++) {
				if (!isp[pos][len]) {
					int minval = INT_MAX;
					for (int leftlen = 1; leftlen < len; leftlen++)
						minval = min(minval, mincut[pos][leftlen] + mincut[pos + leftlen][len - leftlen]);
					mincut[pos][len] = minval + 1;
				}
			}
		}
		return mincut[0][n];
	}
};