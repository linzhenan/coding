class Solution {
public:
	//Each recursive call takes O(n), but at most 26 recursive calls will be triggered.
	//This is a O(26n) ~ O(n) solution.
	string removeDuplicateLetters(string s) {
		int cnt[26] = { 0 };
		int n = s.size();
		for (int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] < s[pos]) pos = i;
			if (--cnt[s[i] - 'a'] == 0) break;
		}
		string sub;
		for (int i = pos + 1; i < s.size(); i++)
			if (s[i] != s[pos]) sub += s[i];
		return s.size() ? s[pos] + removeDuplicateLetters(sub) : "";
	}
};