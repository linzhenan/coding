//Word Pattern

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> str2ch;
		unordered_map<char, string> ch2str;
		int pos = 0;
		int i = 0;
		while (pos < str.size() && i < pattern.size()) {
			string substr = "";
			while (pos < str.size() && str[pos] != ' ') {
				substr += str[pos];
				pos++;
			}
			if (pos < str.size())
				pos++;
			if (substr != "") {
				bool c1 = str2ch.find(substr) == str2ch.end();
				bool c2 = ch2str.find(pattern[i]) == ch2str.end();
				if (c1 && c2) {
					ch2str[pattern[i]] = substr;
					str2ch[substr] = pattern[i];
					i++;
				}
				else if (!c1 && !c2) {
					if (ch2str[pattern[i]] != substr || str2ch[substr] != pattern[i])
						return false;
					i++;
				}
				else {
					return false;
				}
			}
		}
		if (i == pattern.size() && pos == str.size())
			return true;
		else
			return false;
	}
};