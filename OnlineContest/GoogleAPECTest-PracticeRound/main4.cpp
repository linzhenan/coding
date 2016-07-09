#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <cstdlib>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

int num[1000];
long long sum[1000 * (1000 + 1) / 2];

int cmp(const void *a, const void *b) {
	if (*(long long*)a < *(long long*)b)
		return -1;
	else if (*(long long*)a > *(long long*)b)
		return 1;
	else
		return 0;
}
int main() {

	int t;
	int n, q;

	scanf("%d", &t);
	for (int id = 1; id <= t; id++) {
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			if (i)
				num[i] += num[i - 1];
		}

		int idx = 0;
		for (int len = 1; len <= n; len++)
			for (int pos = 0; pos < n - len + 1; pos++) {
				if (pos == 0)
					sum[idx++] = num[pos + len - 1];
				else
					sum[idx++] = num[pos + len - 1] - num[pos - 1];
			}

		qsort(sum, idx, sizeof(long long), cmp);
		for (int i = 1; i < idx; i++) {
			sum[i] += sum[i - 1];
		}
		printf("Case #%d:\n", id);
		for (int i = 0; i < q; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a == 1)
				printf("%" PRIu64 "\n", sum[b - 1]);
			else
				printf("%" PRIu64 "\n", sum[b - 1] - sum[a - 2]);
		}
	}
	return 0;
}