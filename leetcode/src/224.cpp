class Solution {
public:
    bool isDigital(char ch) {
        if ('0' <= ch && ch <= '9')
            return true;
        else
            return false;
    }
    int calculate(string s) {
        int res = 0;
        int sign = 0;
        stack<int> stk;
        stack<int> stksign;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case ' ': break;
                case '(': stk.push(res); res = 0;
                        stksign.push(sign); sign = 0;
                        break;
                case ')':
                        if (stksign.top())
                            res = stk.top() - res;
                        else
                            res = stk.top() + res;
                        stk.pop();
                        stksign.pop();
                        break;
                case '+': sign = 0; break;
                case '-': sign = 1; break;
                default:
                    int digital = s[i] - '0';
                    int num = digital;
                    while (i + 1 < s.size() && isDigital(s[i + 1])) {
                        i++;
                        digital = s[i] - '0';
                        num = num * 10 + digital;
                    }
                    if (sign)
                        res -= num;
                    else
                        res += num;
                    break;
            }
        }
        return res;
    }
};