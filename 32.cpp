class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;//track pos of non-matching '('
        int last = -1;//pos of last non-matching ')'
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                if (stk.empty()) {
                    last = i;
                }
                else {
                    stk.pop();
                    if (stk.empty())
                        longest = max(longest, i - last);
                    else
                        longest = max(longest, i - stk.top());
                }
            }
        }
        return longest;
    }
};