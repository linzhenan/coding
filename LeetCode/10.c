bool isMatch(char* s, char* p) {
	int slen = strlen(s);
	int plen = strlen(p);
	int sidx = 0, pidx;
	int i;

	for (pidx = 0; pidx < plen && sidx < slen; pidx++) {
		if (pidx + 1 < plen && p[pidx + 1] == '*') {
			if (p[pidx] == '.') {
				if (isMatch(s + sidx, p + pidx + 2))
					return true;
				for (i = sidx; i < slen; i++)
					if (isMatch(s + i + 1, p + pidx + 2))
						return true;
				return false;
			}
			else {
				if (isMatch(s + sidx, p + pidx + 2))
					return true;
				for (i = sidx; s[i] == p[pidx] && i < slen; i++)
					if (isMatch(s + i + 1, p + pidx + 2))
						return true;
				return false;
			}
		}
		else {
			if (p[pidx] == '.') {
				sidx++;
				continue;
			}
			else {
				if (s[sidx] == p[pidx]) {
					sidx++;
					continue;
				}
				else {
					return false;
				}
			}
		}
	}

	if (sidx == slen && pidx == plen) {
		return true;
	}
	else if (sidx == slen) {
		for (; pidx + 1 < plen && p[pidx + 1] == '*'; pidx += 2)
			if (isMatch(s + sidx, p + pidx + 2))
				return true;
		return false;
	}
	else {
		return false;
	}
}