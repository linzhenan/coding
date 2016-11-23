#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char str[101];
char mod[101];
int main() {
	int S;
	scanf("%d", &S);
	char ch;
	for (int s = 0; s < S; s++) {
		int k;
		scanf("%d %s", &k, str);
		int len = strlen(str);
		int maxcnt = INT_MIN;
		for (int i = 0; i <= len - k; i++)
		{
			memcpy(mod, str, sizeof(char) * 101);
			int cnt = 0;
			for (int j = i; j < i + k; j++) {
				if (mod[j] == '1')
					mod[j] = '0';
				else
					mod[j] = '1';
			}
			for (int m = 0; m < len; m++) {
				if (mod[m] == '0') {
					cnt = 1;
					for (int l = m + 1; l < len && mod[l] == '0'; l++)
						cnt++;
					maxcnt = max(maxcnt, cnt);
				}
			}
			//printf("%s %d\n", mod, cnt);
			maxcnt = max(maxcnt, cnt);
		}
		printf("%d\n", maxcnt);
	}
	return 0;
}