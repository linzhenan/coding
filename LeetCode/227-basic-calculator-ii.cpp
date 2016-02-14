class Solution {
public:
    int calculate(string s) {
        stack<int> stknum;
        stack<char> stkop;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;
            if ('0' <= s[i] && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            else {
                if (s[i] == '+' || s[i] == '-') {
                    while (!stkop.empty()) {
                        if (stkop.top() == '+')//loop once only
                            num = stknum.top() + num;
                        else if (stkop.top() == '-')//loop once only
                            num = stknum.top() - num;
                        else if (stkop.top() == '*')//loop twice at most
                            num = stknum.top() * num;
                        else if (stkop.top() == '/')//loop twice at most
                            num = stknum.top() / num;
                        stknum.pop();
                        stkop.pop();
                    }
                    stknum.push(num);
                    stkop.push(s[i]);
                }
                else {
                    if (!stkop.empty() && (stkop.top() == '*' || stkop.top() == '/')) {
                        if (stkop.top() == '*')
                            num = stknum.top() * num;
                        else if (stkop.top() == '/')
                            num = stknum.top() / num;
                        stknum.pop();
                        stkop.pop();
                    }
                    stknum.push(num);
                    stkop.push(s[i]);
                }
                num = 0;
            }
        }
        //last num
        while (!stkop.empty()) {
            if (stkop.top() == '+')//loop once only
                num = stknum.top() + num;
            else if (stkop.top() == '-')//loop once only
                num = stknum.top() - num;
            else if (stkop.top() == '*')//loop twice at most
                num = stknum.top() * num;
            else if (stkop.top() == '/')//loop twice at most
                num = stknum.top() / num;
            stknum.pop();
            stkop.pop();
        }
        return num;
    }
};