//Isomorphic Strings

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int n = s.size();
		unordered_map<char, char> map1, map2;
		for (int i = 0; i < n; i++) {
			bool find1 = map1.find(s[i]) != map1.end();
			bool find2 = map2.find(t[i]) != map2.end();
			if (find1 && find2) {
				if (map1[s[i]] != t[i] || map2[t[i]] != s[i])
					return false;
			}
			else if (!find1 && !find2) {
				map1[s[i]] = t[i];
				map2[t[i]] = s[i];
			}
			else {
				return false;
			}
		}
		return true;
	}
};