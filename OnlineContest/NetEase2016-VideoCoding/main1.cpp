#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int main() {
	string s, t;
	while (cin >> s >> t) {
		int sn = s.length();
		int tn = t.length();
		if (tn == 0) {
			printf("Yes\n");
			continue;
		}
		if (sn == 0) {
			printf("No\n");
			continue;
		}
		int j = 0;
		for (int i = 0; i < sn; i++) {
			if (s[i] == t[j])
				j++;
			if (j == tn)
				break;
		}
		if (j == tn)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}