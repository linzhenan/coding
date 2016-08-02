#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int A[100];
int n, k;
int res;
int count() {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (A[i] < A[j])
				cnt++;

	return cnt;
}
void dfs(vector<int> &pos, vector<int> &num, vector<int> &use, int idx) {
	if (idx == num.size()) {
		if (count() == k)
			res++;
	}
	else {
		for (int i = 0; i < pos.size(); i++) {
			if (use[i])
				continue;
			use[i] = 1;
			A[pos[i]] = num[idx];
			dfs(pos, num, use, idx + 1);
			A[pos[i]] = 0;
			use[i] = 0;
		}
	}
}
int main() {
	while (cin >> n >> k) {
		vector<int> pos;
		vector<int> num;
		vector<int> use;
		res = 0;
		int hash[101] = { 0 };
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			if (!A[i]) {
				pos.push_back(i);
				use.push_back(0);
			}
			else
				hash[A[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!hash[i])
				num.push_back(i);
		}
		dfs(pos, num, use, 0);
		printf("%d\n", res);
	}

	return 0;
}