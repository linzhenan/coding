#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	int hash[26];
	char name[21];
	vector<string> res;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N); getchar();
		int maxlen = 0;
		res.clear();
		for (int i = 1; i <= N; i++) {
			memset(hash, 0, sizeof(int) * 26);
			gets_s(name, 21);
			int n = strlen(name);
			int len = 0;
			for (int j = 0; j < n; j++) {
				char ch = name[j];
				if ('A' <= ch && ch <= 'Z') {
					if (hash[ch - 'A'])
						;
					else {
						hash[ch - 'A'] = 1;
						len++;
					}
				}
			}
			string strname = name;
			if (len > maxlen) {
				res.clear();
				maxlen = len;
				res.push_back(strname);
			}
			else if (len == maxlen) {
				res.push_back(strname);
			}
		}
		sort(res.begin(), res.end());
		cout << "Case #" << t << ": " << res[0] << endl;
	}


	return 0;
}