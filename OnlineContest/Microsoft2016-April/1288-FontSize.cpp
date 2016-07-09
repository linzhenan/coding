#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

#pragma warning(disable:4996)

using namespace std;

#define MAXN 1000000
int a[MAXN];

int calcline(int num, int W, int H, int S) {
	int num_per_line = W / S;
	int line = (num + (num_per_line - 1)) / num_per_line;
	return line;
}
int calcpage(int a[MAXN], int N, int W, int H, int S) {
	int line = 0;
	for (int i = 0; i < N; i++)
		line += calcline(a[i], W, H, S);
	int line_per_page = H / S;
	int page = (line + (line_per_page - 1)) / line_per_page;
	return page;
}
int main() {
	int T;
	int N, P, W, H;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> P >> W >> H;
		for (int j = 0; j < N; j++)
			cin >> a[j];
		int minS = 1;
		int maxS = min(W, H);
		for (int currS = maxS; currS >= minS; currS--) {
			int currP = calcpage(a, N, W, H, currS);
			if (currP <= P) {
				cout << currS << endl;
				break;
			}
		}
	}
	return 0;
}