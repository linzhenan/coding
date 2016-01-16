class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.size(); i++)
            if ('a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
                str += s[i];
            else if ('A' <= s[i] && s[i] <= 'Z')
                str += (char)(s[i] - 'A' + 'a');
        for (int i = 0; i < (str.size() + 1) / 2; i++)
            if (str[i] != str[str.size() - 1 - i])
                return false;
        return true;
    }
};