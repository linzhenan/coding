//Palindrome Partitioning

class Solution {
public:
	void dfs(vector<vector<string>>& res, vector<string>& path, vector<vector<bool>>& isp, string& s, int pos, int n) {
		if (pos == n) {
			res.push_back(path);
		}
		else {//pos < n
			for (int len = 1; len <= n - pos; len++) {
				if (isp[pos][len]) {
					path.push_back(s.substr(pos, len));
					dfs(res, path, isp, s, pos + len, n);
					path.pop_back();
				}
			}
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s.size() == 0)
			return res;
		int n = s.size();
		vector<vector<bool>> isp = vector<vector<bool>>(n, vector<bool>(n + 1, false));
		for (int pos = 0; pos < n; pos++) {
			isp[pos][0] = true;
			isp[pos][1] = true;
		}
		for (int len = 2; len <= n; len++)
			for (int pos = 0; pos <= n - len; pos++)
				isp[pos][len] = isp[pos + 1][len - 2] && s[pos] == s[pos + len - 1];
		vector<string> path;
		dfs(res, path, isp, s, 0, n);
		return res;
	}
};