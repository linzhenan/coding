class Solution {
public:
    void dfs(vector<string>& res, string& s, string str, vector<vector<bool>>& indict, int pos, int n) {
        if (pos == n) {
            res.push_back(str);
        }
        else {
            for (int len = n - pos; len >= 1; len--) {
                if (indict[pos][len]) {
                    if (str.size() == 0)
                        dfs(res, s, str + s.substr(pos, len), indict, pos + len, n);
                    else
                        dfs(res, s, str + " " + s.substr(pos, len), indict, pos + len, n);
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.size() == 0 || wordDict.size() == 0)
            return res;
        int n = s.size();
        vector<vector<bool>> indict = vector<vector<bool>>(n, vector<bool>(n + 1, false));
        for (int len = 1; len <= n; len++)
            for (int pos = 0; pos < n; pos++)
                if (wordDict.count(s.substr(pos, len)) > 0)
                    indict[pos][len] = true;
        vector<bool> f = vector<bool>(n, false);
        f[0] = wordDict.count(s.substr(0, 1)) > 0;
        for (int i = 1; i < n; i++) {
            if (wordDict.count(s.substr(0, i + 1)) > 0) {//no split!
                f[i] = true;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (f[j] && wordDict.count(s.substr(j + 1, i - j)) > 0) {
                    f[i] = true;
                    break;
                }
            }
        }
        if (f[n - 1])
            dfs(res, s, "", indict, 0, n);
        return res;
    }
};