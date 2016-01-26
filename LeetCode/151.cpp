class Solution {
public:
	void reverseWords(string &s) {
		stack<string> stk;
		string sub;
		for (int pos = 0; pos < s.size(); pos++) {
			if (s[pos] == ' ') {
				if (sub.size()) {
					stk.push(sub);
					sub.clear();
				}
			}
			else {
				sub += s[pos];
			}
		}
		if (sub.size())
			stk.push(sub);

		s.clear();
		if (!stk.empty()) {
			s += stk.top();
			stk.pop();
		}
		while (!stk.empty()) {
			s += " " + stk.top();
			stk.pop();
		}
	}
};