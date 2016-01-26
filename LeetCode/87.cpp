//Scramble String

//What about DP?

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int l1 = s1.size();
		int l2 = s2.size();
		if (l1 != l2)
			return false;
		string st1 = s1, st2 = s2;
		sort(st1.begin(), st1.end());
		sort(st2.begin(), st2.end());
		if (st1 != st2)
			return false;
		string s11, s12, s21, s22;
		bool res = false;
		for (int i = 1; i < l1 && !res; i++) {
			s11 = s1.substr(0, i);
			s12 = s1.substr(i, l1 - i);
			s21 = s2.substr(0, i);
			s22 = s2.substr(i, l2 - i);
			res = isScramble(s11, s21) && isScramble(s12, s22);
			if (!res) {
				s21 = s2.substr(0, l1 - i);
				s22 = s2.substr(l1 - i, i);
				res = isScramble(s11, s22) && isScramble(s12, s21);
			}
		}
		return res;
	}
};