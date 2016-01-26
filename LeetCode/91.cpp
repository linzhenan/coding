//Decode Ways

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0)
			return 0;

		int f[s.size()] = { 0 };

		if (s[0] == '0')
			f[0] = 0;
		else
			f[0] = 1;
		if (s.size() == 1)
			return f[0];

		if (s[0] == '0' || s[1] == '0' && !(s[0] == '1' || s[0] == '2'))
			f[1] = 0;
		else if (s[0] == '1' && s[1] != '0' || s[0] == '2' && '1' <= s[1] && s[1] <= '6')
			f[1] = 2;
		else
			f[1] = 1;
		if (s.size() == 2)
			return f[1];

		for (int i = 2; i < s.size(); i++) {
			if (s[i] == '0' && !(s[i - 1] == '1' || s[i - 1] == '2'))
				return 0;
			if (s[i] == '0')
				f[i] = f[i - 2];
			else if (s[i - 1] == '1' && s[i] != '0' || s[i - 1] == '2' && '1' <= s[i] && s[i] <= '6')
				f[i] = f[i - 2] + f[i - 1];
			else
				f[i] = f[i - 1];
		}
		return f[s.size() - 1];
	}
};