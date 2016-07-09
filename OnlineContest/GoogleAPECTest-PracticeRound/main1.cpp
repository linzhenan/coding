#include <cstdio>
#include <cstring>
#include <cinttypes>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

int main() {
	int t;
	char str[1001];
	int len;
	long long ans = 1;
	int factor = 0;
	double ansd = 0.0;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s", str);
		len = strlen(str);
		ans = 1;
		ansd = 1.0;
		for (int j = 0; j < len; j++) {
			factor = 1;
			if (j > 0       && str[j - 1] != str[j])
				factor++;
			if (j < len - 1 && str[j + 1] != str[j])
				factor++;
			if (j > 0 && j < len - 1 && str[j - 1] == str[j + 1] && str[j - 1] != str[j])
				factor--;
			ans *= factor;
			ansd *= factor;
		}
		printf("Case #%d: %" PRIu64 "\n", i, ans % 1000000007);
		printf("Case #%d: %lf\n", i, ansd);
	}
	return 0;
}