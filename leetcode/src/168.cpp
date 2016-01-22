//Excel Sheet Column Title

class Solution {
public:
	string convertToTitle(int n) {
		string str;
		while (n) {
			int r = (n - 1) % 26;//n - 1 rather than n
			n = (n - 1) / 26;//n - 1 rather than n
			str = char('A' + r) + str;
		}
		return str;
	}
};