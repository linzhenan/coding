#include "leetcode.h"

bool isMatch(char* s, char* p) {
	int slen = strlen(s);
	int plen = strlen(p);

	if (slen == 0 && plen == 0)
		return true;

	for (int pidx = 0; pidx < plen && slen; pidx++) {
		if (p[pidx] == '?' || p[pidx] == s[0]) {
			return isMatch(s + 1, p + 1);
		}
		else if (p[pidx] == '*') {
			for (int sidx = 0; sidx <= slen; sidx++)
				if (isMatch(s + sidx, p + 1))
					return true;
		}
		else {
			return false;
		}
	}

	return false;
}

void isMatchTest() {
	printf("%d\n", isMatch("a", "aa"));
	printf("%d\n", isMatch("aa", "aa"));
	printf("%d\n", isMatch("aaa", "aa"));
	printf("%d\n", isMatch("aa", "*"));
	printf("%d\n", isMatch("aa", "a*"));
	printf("%d\n", isMatch("ab", "?*"));
	printf("%d\n", isMatch("aab", "c*a*b"));
	printf("%d\n", isMatch("abbbbbbbaabbabaabaa", "*****a*ab"));
}