//Shortest Palindrome

class Solution {
public:
	string shortestPalindrome(string s) {
		int n = s.size();
		if (n < 2)
			return s;
		vector<vector<bool>> isp = vector<vector<bool>>(n, vector<bool>(n + 1, false));
		for (int pos = 0; pos < n; pos++) {
			isp[pos][0] = true;
			isp[pos][1] = true;
		}
		for (int len = 2; len <= n; len++)
			for (int pos = 0; pos <= n - len; pos++)
				isp[pos][len] = isp[pos + 1][len - 2] && s[pos] == s[pos + len - 1];
		int len = n;
		for (; len >= 1; len--)
			if (isp[0][len])
				break;
		if (len == n)
			return s;
		string mid = s.substr(0, len);
		string right = s.substr(len);
		string left = right;
		reverse(left.begin(), left.end());
		return left + mid + right;
	}
};