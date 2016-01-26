
//O(n2) space solution: http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html
//O(n) space solution: https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
class Solution {
public:
	int minCutOld(string s) {
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

	int minCut(string s) {
		int n = s.size();
		if (n <= 1)
			return 0;

		int cut[n + 1];
		for (int i = 0; i <= n; i++)
			cut[i] = i;
		int *f = cut + 1;

		vector<vector<bool>> isp = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			isp[i][i] = true;

		for (int r = 1; r < n; r++)
			for (int l = r; l >= 0; l--)
				if (s[l] == s[r] && (r - l < 2 || isp[l + 1][r - 1])) {
					isp[l][r] = true;
					f[r] = min(f[r], f[l - 1] + 1);
				}
		return f[n - 1] - 1;
	}
};