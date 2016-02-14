class Solution {
public:
    int getCommonLen(string &p) {
        int n = p.size();
        int len[n];
        len[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = len[i - 1];
            while (j > 0 && p[j] != p[i])
                j = len[j - 1];
            if (j == 0) {
                if (p[j] == p[i])
                    len[i] = 1;
                else
                    len[i] = 0;
            }
            else {
                len[i] = j + 1;
            }
        }
        return len[n - 1];
    }
    string shortestPalindrome(string s) {
        string res;
        int n = s.size();
        if (!n)
            return res;
        string r = s;
        reverse(r.begin(), r.end());
        string p = s + "#" + r;
        int comlen = getCommonLen(p);
        res = s.substr(comlen);
        reverse(res.begin(), res.end());
        res = res + s;
        return res;
    }
};