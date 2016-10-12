#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const int maxn = 100005;
char str[maxn];
int dp[30];

int n, m;

int main()
{
	scanf("%d", &n);
	scanf("%s", str);

	scanf("%d", &m);
	set<int > ad[30];

	for (int i = 0; i < m; i++)
	{
		char s[3];
		scanf("%s", s);
		ad[s[0] - 'a'].insert(s[1] - 'a');
		ad[s[1] - 'a'].insert(s[0] - 'a');
	}
	memset(dp, 0, sizeof(dp));
	dp[str[0] - 'a'] = 1;
	for (int i = 1; str[i] != '\0'; i++)
	{
		int temp = 0;
		for (int j = 0; j < 26; j++)
		{
			if (ad[str[i] - 'a'].find(j) == ad[str[i] - 'a'].end())
				temp = max(temp, dp[j] + 1);
		}
		dp[str[i] - 'a'] = temp;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", n - ans);
	return 0;
}
/*
5
abcde
3
ac
ab
de
*/