//Implement strStr()

//What about KMP?

int strStr(char* haystack, char* needle) {
	char *s = haystack;
	char *p = needle;
	int slen = strlen(s);
	int plen = strlen(p);
	if (plen == 0)
		return 0;
	if (plen > slen)
		return -1;
	for (int i = 0; i < slen; i++) {
		if (slen - i < plen)
			return -1;
		int j;
		for (j = 0; j < plen; j++)
			if (s[i + j] != p[j])
				break;
		if (j == plen)
			return i;
	}
	return -1;
}