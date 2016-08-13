#include <cstdio>
#include <cstring>
#include <cinttypes>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

int clip(int val, int minVal, int maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}
int dist(char *str, int i, int j) {
	int len = strlen(str);
	i = clip(i, 0, len - 1);
	j = clip(j, 0, len - 1);
	if (j < i || j - i > 2)
		return -1;

	if (j - i == 0)
		return 1;
	else if (j - i == 1)
		return str[i] == str[j] ? 1 : 2;
	else if (j - i == 2)
	{
		if (str[i] == str[i + 1] && str[i + 1] == str[i + 2])
			return 1;
		else if (str[i] == str[i + 1] && str[i + 1] != str[i + 2])
			return 2;
		else if (str[i] != str[i + 1] && str[i + 1] == str[i + 2])
			return 2;
		else if (str[i] != str[i + 1] && str[i] == str[i + 2])
			return 2;
		else
			return 3;
	}
	else
		return -1;
}
int main() {
	int t;
	char str[1001];
	int len;
	long long ans = 1;
	int factor = 0;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s", str);
		len = strlen(str);
		ans = 1;
		for (int j = 0; j < len; j++)
		{
			factor = dist(str, j - 1, j + 1);
			ans *= factor;
			ans %= 1000000007;
		}
		printf("Case #%d: %" PRIu64 "\n", i, ans);
	}
	return 0;
}