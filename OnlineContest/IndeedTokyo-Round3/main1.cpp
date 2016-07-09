#include <cstdio>
#include <cstring>

int main() {
	char s[11], t[11];
	char s2[11], t2[11];
	int slen, tlen;

	int ans = 0;

	scanf("%s%s", s, t);
	slen = strlen(s);
	tlen = strlen(t);
	s[slen] = '\0';
	t[tlen] = '\0';
	s2[slen] = '\0';
	t2[tlen] = '\0';

	if (slen != tlen)
		ans = -1;
	else if (strcmp(s, t) == 0)
		ans = 1;
	else {
		for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
			for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
				for (int i = 0; i < slen; i++) {
					s2[i] = s[i] == ch1 ? ch2 : s[i];
					t2[i] = t[i] == ch1 ? ch2 : t[i];
				}
				if (strcmp(s2, t2) == 0) {
					ans = 1;
					break;
				}
			}
			if (ans == 1)
				break;
		}
	}

	if (ans == 1)
		printf("Possible\n");
	else
		printf("Impossible\n");

	return 0;
}