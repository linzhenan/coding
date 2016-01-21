//Count and Say

class Solution {
public:
	string next(string s) {
		stringstream ss;
		for (int i = 0; i < s.size();) {
			int count = 1;
			char ch = s[i];
			while (ch == s[++i])
				count++;
			ss << count << ch;
		}
		return ss.str();
	}
	string countAndSay(int n) {
		string s("1");
		for (int i = 1; i < n; i++)
			s = next(s);
		return s;
	}
};