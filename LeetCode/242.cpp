class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> map;
        unordered_map<char, int> map2;
        for (int i = 0; i < s.size(); i++)
            map[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            if (map.find(t[i]) != map.end()) {
                map2[t[i]]++;
                if (map2[t[i]] > map[t[i]])
                    return false;
            }
            else {
                return false;
            }
        for (auto e : map) {
            if (e.second != map2[e.first])
                return false;
        }
        return true;
    }   
};