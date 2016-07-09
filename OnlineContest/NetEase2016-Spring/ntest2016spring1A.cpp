#include <vector>
#include <iostream>
#include <string>

using namespace std;

void main(void) {
	vector<int> led[5];

	int S, K, N;
	string str;

	uint8_t bitset[8];
	uint8_t numbit[10] = { 0 };
	for (int i = 0; i < 8; i++)
		bitset[i] = 1 << i;
	numbit[0] = bitset[1] | bitset[2] | bitset[3] | bitset[5] | bitset[6] | bitset[7];
	numbit[1] = bitset[3] | bitset[6];
	numbit[2] = bitset[1] | bitset[3] | bitset[4] | bitset[5] | bitset[7];
	numbit[3] = bitset[1] | bitset[3] | bitset[4] | bitset[6] | bitset[7];
	numbit[4] = bitset[2] | bitset[3] | bitset[4] | bitset[6];
	numbit[5] = bitset[1] | bitset[2] | bitset[4] | bitset[6] | bitset[7];
	numbit[6] = bitset[1] | bitset[2] | bitset[4] | bitset[5] | bitset[6] | bitset[7];
	numbit[7] = bitset[1] | bitset[3] | bitset[6];
	numbit[8] = bitset[1] | bitset[2] | bitset[3] | bitset[4] | bitset[5] | bitset[6] | bitset[7];
	numbit[9] = bitset[1] | bitset[2] | bitset[3] | bitset[4] | bitset[6] | bitset[7];

	cin >> S; getline(cin, str);
	for (int i = 0; i < S; i++) {
		cin >> K >> N; getline(cin, str);
		for (int j = 0; j < 5; j++)
			led[j].clear();
		for (int j = 0; j < 5 - K; j++)
			led[j].push_back(0);
		for (int j = 5 - K; j < 5; j++) {
			getline(cin, str);
			uint8_t cand = 0;
			for (int k = 0; k < str.size(); k++) {
				if (str[k] == ' ')
					continue;
				cand |= bitset[str[k] - '0'];
			}
			for (int k = 0; k < 10; k++) {
				if ((cand & numbit[k]) == cand)
					led[j].push_back(k);
			}
		}
		int cnt = 0;
		for (int i0 = 0; i0 < led[0].size(); i0++)
			for (int i1 = 0; i1 < led[1].size(); i1++)
				for (int i2 = 0; i2 < led[2].size(); i2++)
					for (int i3 = 0; i3 < led[3].size(); i3++)
						for (int i4 = 0; i4 < led[4].size(); i4++)
							if (led[0][i0] * 10000 +
								led[1][i1] * 1000 +
								led[2][i2] * 100 +
								led[3][i3] * 10 +
								led[4][i4] < N)
								cnt++;
							else
								goto done;
	done:
		cout << cnt << endl;
	}
}