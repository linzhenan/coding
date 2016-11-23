#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
private:
	unordered_set<string> res;
	void dfs(string &s, string t, int pos, int lCount, int rCount, int openCount) {
		if (s[pos] == '\0') {
			if (!openCount)
				res.insert(t);
		}
		else if (s[pos] == '(') {
			if (lCount) dfs(s, t, pos + 1, lCount - 1, rCount, openCount);
			dfs(s, t + '(', pos + 1, lCount, rCount, openCount + 1);
		}
		else if (s[pos] == ')') {
			if (rCount) dfs(s, t, pos + 1, lCount, rCount - 1, openCount);
			if (openCount) dfs(s, t + ')', pos + 1, lCount, rCount, openCount - 1);
		}
		else {
			dfs(s, t + s[pos], pos + 1, lCount, rCount, openCount);
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		int lCount = 0;
		int rCount = 0;
		res.clear();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				lCount++;
			else if (s[i] == ')')
				lCount ? lCount-- : rCount++;
		}
		dfs(s, "", 0, lCount, rCount, 0);
		return vector<string>(res.begin(), res.end());
	}
};

int main() {
	Solution slu;
	string s1 = "()())()";
	string s2 = "(a)())()";
	string s3 = ")(";
	for (auto s : slu.removeInvalidParentheses(s1))
		cout << s << endl;
	cout << endl;

	for (auto s : slu.removeInvalidParentheses(s2))
		cout << s << endl;
	cout << endl;

	for (auto s : slu.removeInvalidParentheses(s3))
		cout << s << endl;
	cout << endl;
	return 0;
}