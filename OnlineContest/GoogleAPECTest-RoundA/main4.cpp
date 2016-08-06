#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 12
#define MAXK 10
int max(int a, int b) {
	return a > b ? a : b;
}
int smalldata() {
	int L[MAXN];
	int K[MAXN];
	int A[MAXN][MAXK];
	int C[MAXN][MAXK - 1];
	int T, M, N;

	scanf("%d", &T);
	int f[1001];
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &M, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &K[i], &L[i]);
			for (int l = 0; l < K[i]; l++)
				scanf("%d", &A[i][l]);
			for (int l = 0; l < K[i] - 1; l++)
				scanf("%d", &C[i][l]);
		}

		memset(f, 0, sizeof(int) * 1001);
		/*
		for (int c = 0; c <= M; c++) {
			int ac_cost = 0;
			int max_atk = A[0][L[0] - 1];
			for (int lv = L[0]; lv <= K[0] - 1; lv++) {
				ac_cost += C[0][lv - 1];
				if (c - ac_cost >= 0)
					max_atk = max(max_atk, A[0][lv]);
				else
					break;
			}
			f[c] = max_atk;
		}
		*/
		for (int i = 0; i < N; i++) {
			for (int c = M; c >= 0; c--) {
				int ac_cost = 0;
				int max_atk = f[c] + A[i][L[i] - 1];
				for (int lv = L[i]; lv <= K[i] - 1; lv++) {
					ac_cost += C[i][lv - 1];
					if (c - ac_cost >= 0)
						max_atk = max(max_atk, f[c - ac_cost] + A[i][lv]);
					else
						break;
				}
				f[c] = max_atk;
			}
		}

		int max_atk = f[0];
		for (int c = 1; c <= M; c++)
			max_atk = max(max_atk, f[c]);
		printf("Case #%d: %d\n", t, max_atk);
	}
	return 0;
}

typedef long long ll;
int L[MAXN];
int K[MAXN];
ll A[MAXN][MAXK + 1];
ll C[MAXN][MAXK + 1];
ll bestans;
ll M;
int T, N;
int list[8];
struct Item {
	ll cost, atk;
	Item() {};
	Item(ll c, ll a) : cost(c), atk(a) {}
	bool operator< (const Item &b) const {
		if (cost != b.cost)
			return cost < b.cost;
		else
			return atk > b.atk;
	}
};
void check() {
	vector <Item> tmp, ntmp;
	for (int i = L[list[0]]; i <= K[list[0]]; i++)
		for (int j = L[list[1]]; j <= K[list[1]]; j++)
			for (int k = L[list[2]]; k <= K[list[2]]; k++)
				for (int l = L[list[3]]; l <= K[list[3]]; l++) {
					Item item(C[list[0]][i] + C[list[1]][j] + C[list[2]][k] + C[list[3]][l],
						A[list[0]][i] + A[list[1]][j] + A[list[2]][k] + A[list[3]][l]);
					if (item.cost <= M) {
						tmp.push_back(item);
					}
				}

	sort(tmp.begin(), tmp.end());
	ll maxatk = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].atk <= maxatk)
			continue;
		maxatk = tmp[i].atk;
		ntmp.push_back(tmp[i]);
	}

	for (int i = L[list[4]]; i <= K[list[4]]; i++)
		for (int j = L[list[5]]; j <= K[list[5]]; j++)
			for (int k = L[list[6]]; k <= K[list[6]]; k++)
				for (int l = L[list[7]]; l <= K[list[7]]; l++) {
					Item item1(C[list[4]][i] + C[list[5]][j] + C[list[6]][k] + C[list[7]][l],
						A[list[4]][i] + A[list[5]][j] + A[list[6]][k] + A[list[7]][l]);
					if (item1.cost <= M) {
						Item item2(M - item1.cost, 0);
						auto it = upper_bound(ntmp.begin(), ntmp.end(), item2);
						while (it == ntmp.end() || it->cost + item1.cost > M)
							it--;
						bestans = max(bestans, it->atk + item1.atk);
					}
				}
}
void dfs(int depth, int last) {
	if (depth == 8) {
		check();
		return;
	}
	if (8 - depth > N - last)
		return;
	for (int i = last + 1; i < N; i++) {
		list[depth] = i;
		dfs(depth + 1, i);
	}
}
void largedata() {
	scanf("%d", &T);
	int f[1001];
	for (int t = 1; t <= T; t++) {
		bestans = 0;
		scanf("%I64d%I64d", &M, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &K[i], &L[i]);
			for (int l = 1; l <= K[i]; l++)
				scanf("%I64d", &A[i][l]);
			for (int l = 2; l <= K[i]; l++)
				scanf("%I64d", &C[i][l]);

			C[i][L[i]] = 0;
			for (int j = L[i] + 1; j <= K[i]; j++)
				C[i][j] += C[i][j - 1];
		}
		dfs(0, -1);
		printf("Case #%d: %I64d\n", t, bestans);
	}
}
int main() {

	//smalldata();
	largedata();
	return 0;
}