class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int num;
                if (tokens[i] == "+")
                    num = num2 + num1;
                else if (tokens[i] == "-")
                    num = num2 - num1;
                else if (tokens[i] == "*")
                    num = num2 * num1;
                else if (tokens[i] == "/")
                    num = num2 / num1;
                s.push(num);
            }
            else {
                int num = atoi(tokens[i].c_str());
                s.push(num);
            }
        }
        return s.top();
    }
};