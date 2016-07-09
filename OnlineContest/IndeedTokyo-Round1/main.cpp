#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define P1 0
#define P2 0
#define P3 1

int main() {
#if P1
	string s;
	cin >> s;

	set<string> strs;
	vector<string> res;

	for (int i = 0; i < s.size(); i++) {
		for (char ch = 'a'; ch <= 'd'; ch++) {
			string str = s;
			str[i] = ch;

			sort(str.begin(), str.end());
			if (strs.count(str) > 0)
				continue;

			strs.insert(str);
			res.push_back(str);
			while (next_permutation(str.begin(), str.end())) {
				strs.insert(str);
				res.push_back(str);
			}
		}
	}
	sort(res.begin(), res.end());

	for (auto it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
#endif 

#if P2
	string s;
	long long m;
	cin >> s >> m;

	unordered_map<string, long long> map;

	long long i;
	for (i = 0; i < m; i++) {
		if (map.find(s) != map.end())
			break;
		map[s] = i;
		s.insert(s.begin() + (s[0] - '0'), s[0]);
		s = s.substr(1);
	}

	if (i == m) {
		cout << s;
	}
	else {
		long long cycle = i - map[s];
		m = (m - i) % cycle;
		for (i = 0; i < m; i++) {
			s.insert(s.begin() + (s[0] - '0'), s[0]);
			s = s.substr(1);
		}
		cout << s << endl;;
	}
#endif

#if P3
	int map[100][100] = { 0 };
	int v, q, a, b;
	//for (int i = 0; i < 100; i++)
	//	for (int j = 0; j < 100; j++)
	//		map[i][j] = INT_MAX;
	//memset(map, 0xFF, sizeof(int) * 100 * 100);
	cin >> v >> q;
	for (int i = 0; i < v - 1; i++)
		for (int j = i + 1; j < v; j++)
			map[i][j] = j - i;
	for (int m = 0; m < q; m++) {
		cin >> a >> b;
		a--;
		b--;
		if (!map[a][b])
			cout << -1 << endl;
		else
			cout << map[a][b] << endl;
		if (map[a][b] == 1)
			continue;
		map[a][b] = 1;
		/*
		for (int j = 0; j < v; j++) {
			if (j == a || j == b)
				continue;
			//start from a
			if (map[a][j] > 1 + map[b][j] && map[b][j])
				map[a][j] = 1 + map[b][j];
			//arrive at b
			if (map[j][b] > map[j][a] + 1 && map[j][a])
				map[j][b] = map[j][a] + 1;
		}
		*/
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				for (int k = 0; k < v; k++)
					if (map[i][k] && map[k][j] && (map[i][j] > map[i][k] + map[k][j] || !map[i][j]))
						map[i][j] = map[i][k] + map[k][j];
	}
#endif
	return 0;
}