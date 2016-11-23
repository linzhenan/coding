class Solution {
public:
	void dfs(vector<vector<string>>& res, vector<string>& slu, string& s, int pos, unordered_set<string>& wordDict) {
		if (pos == s.size()) {
			res.push_back(slu);
			return;
		}
		for (int len = 1; len <= s.size() - pos; len++) {
			string sub = s.substr(pos, len);
			if (wordDict.find(sub) != wordDict.end()) {
				slu.push_back(sub);
				dfs(res, slu, s, pos + len, wordDict);
				slu.pop_back();
			}
		}
	}
	vector<string> wordBreak_dfs(string s, unordered_set<string>& wordDict) {
		vector<vector<string>> res;
		vector<string> slu;
		dfs(res, slu, s, 0, wordDict);
		for (int i = 0; i < res.size(); i++) {
			string str;
			for (string sub : res[i])
				str += sub + " ";
			str = str.substr(0, str.size() - 1);
			slu.push_back(str);
		}
		return slu;
	}
	void traceback(vector<vector<string>>&res, vector<string>& slu, vector<vector<int>>& trace, string& s, int pos) {
		if (pos == -1) {
			res.push_back(slu);
			return;
		}
		for (int i = 0; i < trace[pos].size(); i++) {
			slu.push_back(s.substr(trace[pos][i], pos - trace[pos][i] + 1));
			traceback(res, slu, trace, s, trace[pos][i] - 1);
			slu.pop_back();
		}
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.size();
		vector<vector<int>> trace(n);
		vector<int> dp(n);
		vector<vector<string>> res;
		vector<string> slu;
		for (int i = 0; i < n; i++) {
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
				dp[i] = true;
				trace[i].push_back(0);
			}
			for (int j = 0; j < i; j++) {
				if (dp[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
					dp[i] = true;
					trace[i].push_back(j + 1);
				}
			}
		}
		traceback(res, slu, trace, s, n - 1);
		for (int i = 0; i < res.size(); i++) {
			string str;
			for (int j = res[i].size() - 1; j >= 0; j--)
				str += res[i][j] + " ";
			str = str.substr(0, str.size() - 1);
			slu.push_back(str);
		}
		return slu;
	}
};