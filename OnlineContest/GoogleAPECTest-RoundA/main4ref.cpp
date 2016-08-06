#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int T, Case = 1;
ll m, n;
int Ki[15], Li[15];
ll A[15][15], C[15][15];

ll bestans;
bool sel[15];

int itemList[8];

struct Item {
	ll money, power;
	Item() {}
	Item(ll a, ll b) :money(a), power(b) {}
	bool operator<(const Item&b)const {
		if (money != b.money)return money < b.money;
		return power > b.power;
	}
};

vector<Item> tmp, t1;

void check() {
	tmp.clear(); t1.clear();
	for (int i = Li[itemList[0]]; i <= Ki[itemList[0]]; ++i)
		for (int j = Li[itemList[1]]; j <= Ki[itemList[1]]; ++j)
			for (int k = Li[itemList[2]]; k <= Ki[itemList[2]]; ++k)
				for (int l = Li[itemList[3]]; l <= Ki[itemList[3]]; ++l) {
					Item nnew(C[itemList[0]][i] + C[itemList[1]][j] + C[itemList[2]][k] + C[itemList[3]][l],
						A[itemList[0]][i] + A[itemList[1]][j] + A[itemList[2]][k] + A[itemList[3]][l]);
					if (nnew.money <= m)tmp.push_back(nnew);
				}
	sort(tmp.begin(), tmp.end());
	ll maxpow = 0;
	for (int i = 0; i<tmp.size(); i++) {
		if (tmp[i].power <= maxpow)continue;
		maxpow = tmp[i].power;
		t1.push_back(tmp[i]);
	}

	for (int i = Li[itemList[4]]; i <= Ki[itemList[4]]; ++i)
		for (int j = Li[itemList[5]]; j <= Ki[itemList[5]]; ++j)
			for (int k = Li[itemList[6]]; k <= Ki[itemList[6]]; ++k)
				for (int l = Li[itemList[7]]; l <= Ki[itemList[7]]; ++l) {
					Item nnew(C[itemList[4]][i] + C[itemList[5]][j] + C[itemList[6]][k] + C[itemList[7]][l],
						A[itemList[4]][i] + A[itemList[5]][j] + A[itemList[6]][k] + A[itemList[7]][l]);
					if (nnew.money <= m) {
						Item nn2(m - nnew.money, 0);
						auto it = upper_bound(t1.begin(), t1.end(), nn2);
						//while(it!=t1.end()&&it->money+nnew.money<m)++it;
						while (it == t1.end() || it->money + nnew.money>m)--it;
						auto x = *it;
						bestans = max(bestans, x.power + nnew.power);
					}
				}

}

void dfs(int depth, int last) {
	if (depth == 8) {
		check();
		return;
	}
	if (8 - depth > n - last)return;
	for (int i = last + 1; i < n; i++) {
		itemList[depth] = i;
		dfs(depth + 1, i);
	}
}

int main() {
	//freopen("D-large-practice.in", "r", stdin);
	//freopen("D-large.txt", "w", stdout);

	for (scanf("%d", &T); Case <= T; Case++) {
		bestans = 0;

		scanf("%I64d%I64d", &m, &n);

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &Ki[i], &Li[i]);
			for (int j = 1; j <= Ki[i]; j++)scanf("%I64d", &A[i][j]);
			for (int j = 2; j <= Ki[i]; j++)scanf("%I64d", &C[i][j]);
			C[i][Li[i]] = 0;
			for (int j = Li[i] + 1; j <= Ki[i]; j++)C[i][j] += C[i][j - 1];
		}
		dfs(0, -1);
		printf("Case #%d: %I64d\n", Case, bestans);
	}
	return 0;
}
