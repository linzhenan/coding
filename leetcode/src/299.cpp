class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> map;
        int n = secret.size();
        for (int i = 0; i < n; i++)
            map[secret[i]]++;
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < n; i++) {
            char ch = guess[i];
            if (secret[i] == ch) {
                bulls++;
                map[ch]--;
            }
        }
        for (int i = 0; i < n; i++) {
            char ch = guess[i];
            if (secret[i] != ch) {
                if (map[ch]) {
                    map[ch]--;
                    cows++;
                }
            }
        }
        
        stringstream ss;
        ss << bulls;
        ss << 'A';
        ss << cows;
        ss << 'B';
        return ss.str();
    }
};