class Solution {
public:
    vector<string> generate(vector<string> p, stack<char> s, string str, int left, int n) {
        if (left == n) {
            while (!s.empty()) {
                str += ')';
                s.pop();
            }
            p.push_back(str);
            return p;
        }
        if (s.empty()) {
            s.push('(');
            p = generate(p, s, str + '(', left + 1, n);
            s.pop();
        }
        else {
            s.push('(');
            p = generate(p, s, str + '(', left + 1, n);
            s.pop();
            s.pop();
            p = generate(p, s, str + ')', left, n);
            s.push('(');
        }
        return p;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> p;
        stack<char> s;
        string str;
        p = generate(p, s, str, 0, n);
        return p;
    }
};