class Solution {
public:
	string decodeString(string s) {
		stack<int> mul;
		stack<string> str;
		int n = s.size();
		int num = 0;
		string cur;
		for (int i = 0; i < n; i++) {
			char ch = s[i];
			if ('0' <= ch && ch <= '9') {
				num = num * 10 + ch - '0';
			}
			else if (ch == '[') {
				mul.push(num);
				str.push(cur);
				num = 0;
				cur = "";
			}
			else if (ch == ']') {
				int rep = mul.top();
				mul.pop();
				string pre = str.top();
				str.pop();
				for (int i = 0; i < rep; i++)
					pre += cur;
				cur = pre;
			}
			else {
				cur += ch;
			}
		}
		return cur;
	}
};