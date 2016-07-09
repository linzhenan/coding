#include <stdint.h>
#include <iostream>
#include <unordered_map>
#include <math.h>
using namespace std;

#undef _DEBUG

int main1() {
	int64_t n;
	int maxcnt;
	int maxnum;
	unordered_map<int64_t, int> map;

	cin >> n;

	if (n == 0) {
		maxcnt = 0;
		maxnum = 0;
	}
	else {
		maxcnt = 1;
		maxnum = 1;
	}
	for (int64_t num = 2; num <= n; num++) {
		int64_t max = num;
		int64_t adivisor = 2;
		map.clear();
#ifdef _DEBUG
		cout << num << ": ";
#endif
		while (max != 1) {
			if (max % adivisor == 0) {
				max = max / adivisor;
#ifdef _DEBUG
				cout << adivisor << " ";
#endif
				map[adivisor]++;
				adivisor = 2;
			}
			else {
				adivisor++;
			}
		}
		int64_t currcnt = 1;
		for (auto e : map)
			currcnt = currcnt * (e.second + 1);
		if (maxcnt < currcnt) {
			maxcnt = currcnt;
			maxnum = num;
		}
#ifdef _DEBUG
		cout << "(" << currcnt << ")" << endl;
#endif
	}
	cout << maxnum << endl;

	return 0;
}

int main2() {
	unordered_map<int64_t, unordered_map<int64_t, int>> map;
	int64_t n;
	int64_t maxcnt;
	int64_t maxnum;
	cin >> n;
	if (n == 0) {
		maxcnt = 0;
		maxnum = 0;
	}
	else {
		maxcnt = 1;
		maxnum = 1;
	}
	for (int64_t num = 2; num <= n; num++) {
		int64_t max = num;
		int64_t adivisor = 2;
		if (num & 0x01)
			continue;
#ifdef _DEBUG
		cout << num << ": ";
#endif
		while (max != 1) {
			if (max % adivisor == 0) {
#ifdef _DEBUG
				cout << adivisor << " ";
#endif
				max = max / adivisor;
				map[num][adivisor]++;
				if (map.find(max) != map.end()) {
#ifdef _DEBUG
					cout << "(" << max << ":";
#endif
					for (auto e : map[max]) {
#ifdef _DEBUG
						cout << e.first << " " << e.second << ",";
#endif
						map[num][e.first] += map[max][e.first];
					}
#ifdef _DEBUG
					cout << ")";
#endif
					break;
				}
				else {
					adivisor = 2;
				}
			}
			else {
				adivisor++;
				if (max < adivisor * adivisor) {
					map[num][max] = 1;
#ifdef _DEBUG
					cout << "[ " << max << "] ";
#endif
					break;
				}
			}
		}
		int64_t cnt = 1;
		for (auto e : map[num])
			cnt = cnt * (e.second + 1);
		if (cnt > maxcnt) {
			maxcnt = cnt;
			maxnum = num;
		}
#ifdef _DEBUG
		cout << "(" << cnt << ")" << endl;
#endif
	}
	cout << maxnum << endl;

	return 0;
}

#define  PRIME_CNT 13
const int prime[PRIME_CNT] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, };
int64_t N;
int max_cnt = 0;
int64_t min_res = 0;
void dfs(int64_t n, int cnt, int pi, int ni) {

	if (n > N || pi == PRIME_CNT)
		return;
	if (cnt > max_cnt || cnt == max_cnt && n < min_res) {
		max_cnt = cnt;
		min_res = n;
	}
	for (int i = 1; i <= ni; i++) {
		n *= prime[pi];
		if (n > N)
			break;
		dfs(n, cnt * (i + 1), pi + 1, i);
	}
}
int main() {
	while (cin >> N) {
		if (N == 0) {
			cout << 0 << endl;
			continue;
		}
		if (N < 0)
			N = -N;
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		min_res = 1;
		max_cnt = 1;
		dfs(1, 1, 0, log2(N));
		cout << min_res << endl;
	}

	return 0;
}