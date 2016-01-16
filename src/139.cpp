class Solution {
public:
    bool dfs(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
            return false;
        if (wordDict.find(s) != wordDict.end())
            return true;
        for (int len = 1; len <= s.size(); len++) {
            string left = s.substr(0, len);
            string right = s.substr(len);
            if (wordDict.find(left) != wordDict.end() && wordBreak(right, wordDict))
                return true;
        }
        return false;
    }
    bool dp(string s, unordered_set<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
            return false;
        int n = s.size();
        bool f[n];
        for (int i = 0; i < n; i++)
            f[i] = false;
        f[0] = wordDict.find(s.substr(0, 1)) != wordDict.end();
        for (int i = 1; i < n; i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                f[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (f[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n - 1];
    }
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return dp(s, wordDict);
    }
};