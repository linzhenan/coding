class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> stack;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]);
            /*
            if (s[i] == '(')
                if (!stack.empty() && stack.top() == '(')
                    return false;
                else
                    stack.push(s[i]);
            else if (s[i] == '{')
                if (!stack.empty())
                    return false;
                else
                    stack.push(s[i]);
            else if (s[i] == '[')
                if (!stack.empty() && (stack.top() == '[' || stack.top() == '('))
                    return false;
                else
                    stack.push(s[i]);
            */
            else if (s[i] == ')')
                if (stack.empty() || stack.top() != '(')
                    return false;
                else
                    stack.pop();
            else if (s[i] == '}')
                if (stack.empty() || stack.top() != '{')
                    return false;
                else
                    stack.pop();
            else if (s[i] == ']')
                if (stack.empty() || stack.top() != '[')
                    return false;
                else
                    stack.pop();
            else
                return false;
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};