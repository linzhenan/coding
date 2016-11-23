#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
#include <stack>
using namespace std;

class Solution {
private:
	stack<int> num;
	stack<char> op;
public:
	int calcVal(string expr) {
		int lastDigitalPos = 0;
		int d0 = 0, d1 = 0;
		for (int i = 0; i < expr.size(); i++) {
			char ch = expr[i];
			if (ch == '+' || ch == '-' || ch == '*') {
				d0 = atoi(expr.substr(lastDigitalPos, i - lastDigitalPos).c_str());
				if (!op.empty() && op.top() == '*') {
					d1 = num.top();
					num.pop();
					op.pop();
					d0 = d1 * d0;
				}
				if (ch != '*' && !op.empty()) {
					char ch1 = op.top();
					d1 = num.top();
					num.pop();
					op.pop();
					switch (ch1) {
					case '*': d0 = d1 * d0; break;
					case '-': d0 = d1 - d0; break;
					case '+': d0 = d1 + d0; break;
					}
				}
				num.push(d0);
				op.push(ch);
				lastDigitalPos = i + 1;
			}
		}
		d0 = atoi(expr.substr(lastDigitalPos).c_str());
		while (!op.empty()) {
			char ch = op.top();
			op.pop();
			d1 = num.top();
			num.pop();
			switch (ch) {
			case '*': d0 = d1 * d0; break;
			case '-': d0 = d1 - d0; break;
			case '+': d0 = d1 + d0; break;
			}
		}
		return d0;
	}
	void dfs(vector<string>& res, string &num, int idx, string expr, int target) {
		if (idx == num.size()) {
			if (calcVal(expr) == target)
				res.push_back(expr);
		}
		else {
			for (int len = 1; len < num.size() - idx; len++) {
				string number = num.substr(idx, len);
				if (number[0] == '0' && len > 1)
					continue;
				dfs(res, num, idx + len, expr + number + "*", target);
				dfs(res, num, idx + len, expr + number + "+", target);
				dfs(res, num, idx + len, expr + number + "-", target);
			}
			string number = num.substr(idx);
			if (number[0] != '0' || num.size() - idx == 1)
				dfs(res, num, num.size(), expr + num.substr(idx), target);
		}
	}
	vector<string> addOperators_timeout(string num, int target) {
		vector<string> res;
		dfs(res, num, 0, "", target);
		return res;
	}
private:
	long long t;
	int slen;
	const char * s;
public:
	void processTail(long long presum, long long last, int pos, char* buf, int bufpos, vector<string>& res) {
		if (pos == slen) {
			if (presum + last == t) {
				buf[bufpos] = 0;
				res.push_back(buf);
			}
			return;
		}
		int lmax = (s[pos] == '0' ? 1 : slen - pos);
		long long v = 0;
		for (int l = 1; l <= lmax; l++) {
			char c = s[pos + l - 1];
			v = v * 10 + (c - '0');
			buf[bufpos + l] = c;

			buf[bufpos] = '+';
			processTail(presum + last, v, pos + l, buf, bufpos + l + 1, res);

			buf[bufpos] = '-';
			processTail(presum + last, -v, pos + l, buf, bufpos + l + 1, res);

			buf[bufpos] = '*';
			processTail(presum, last * v, pos + l, buf, bufpos + l + 1, res);
		}
	}
	vector<string> addOperators(string num, int target) {
		slen = num.size();
		t = target;
		s = num.c_str();

		vector<string> res;
		char *buf = new char[slen * 2 + 1];
		int lmax = (s[0] == '0' ? 1 : slen);
		long long v = 0;
		for (int l = 1; l <= lmax; l++) {
			char c = s[l - 1];
			v = v * 10 + (c - '0');
			buf[l - 1] = c;
			processTail(0, v, l, buf, l, res);
		}
		delete buf;
		return res;
	}
};
int main() {
	int ret;
	Solution slu;
	cout << slu.calcVal("1*2*3*4*5-6+78-9") << endl;
	cout << slu.calcVal("1+2+3") << endl;
	cout << slu.calcVal("1*2*3") << endl;
	cout << slu.calcVal("2+3*2") << endl;
	cout << slu.calcVal("2*3+2") << endl;
	cout << slu.calcVal("1*0+5") << endl;
	cout << slu.calcVal("10-5") << endl;
	vector<string> res = slu.addOperators("999999999", 81);
	return 0;
}