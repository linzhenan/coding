#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <unordered_map>

using namespace std;

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

void smallcase()
{
	int t;
	int n, k;
	int num[4][1000];
	int ans;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < n; l++) {
				scanf("%d", &num[j][l]);
			}
		}
		for (int l0 = 0; l0 < n; l0++)
		{
			for (int l1 = 0; l1 < n; l1++)
			{
				for (int l2 = 0; l2 < n; l2++)
				{
					for (int l3 = 0; l3 < n; l3++)
					{
						if ((num[0][l0] ^ num[1][l1] ^ num[2][l2] ^ num[3][l3]) == k)
						{
							ans++;
						}
					}
				}
			}
		}

		printf("Case #%d: %d\n", i, ans);
	}
}

void largecase()
{
	int T, t;
	int n;
	long long k;
	long long num[4][1000];
	long long ans;
	unordered_map<long long, long long> map1, map2;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		ans = 0;
		map1.clear();
		map2.clear();

		scanf("%d%" PRIu64, &n, &k);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%" PRIu64, &num[i][j]);
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map1[num[0][i] ^ num[1][j]]++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map2[num[2][i] ^ num[3][j]]++;

		for (auto e : map1)
		{
			if (map2.find(e.first ^ k) != map2.end())
			{
				ans += e.second * map2[e.first ^ k];
			}
		}

		printf("Case #%d: %" PRIu64 "\n", t, ans);
	}
}

int main() {
	largecase();
	return 0;
}