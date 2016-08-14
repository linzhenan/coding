#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <cstdlib>
#include <algorithm>

//to be improved
//from http://blog.csdn.net/xishisugan/article/details/51763814
//to   https://www.quora.com/How-can-problem-D-Sums-of-sums-from-Round-E-of-the-Google-APAC-Test-2016-be-solved-for-the-large-dataset

using namespace std;

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

#define MAXN 200000
#define MAX_SUM (MAXN * 100)

int num[MAXN];
long long preSum[MAXN + 1];

long long apprCnt[MAX_SUM + 1];
long long apprCntSum[MAX_SUM + 1];
long long sumOfSum[MAX_SUM + 1];
long long maxSum;

long long getAns(long long lCnt, long long rCnt)
{
	long long sum;
	long long left, right;

	sum = lower_bound(apprCntSum + 1, apprCntSum + maxSum + 1, lCnt) - apprCntSum;
	if (apprCntSum[sum] == lCnt)
	{
		if (apprCnt[sum] == 1)
			left = sumOfSum[sum - 1];
		else
			left = sumOfSum[sum - 1] + sum * (apprCnt[sum] - 1);
	}
	else
	{
		left = sumOfSum[sum - 1] + sum * (lCnt - apprCntSum[sum - 1] - 1);
	}

	sum = lower_bound(apprCntSum + 1, apprCntSum + maxSum + 1, rCnt) - apprCntSum;
	if (apprCntSum[sum] == rCnt)
		right = sumOfSum[sum];
	else
		right = sumOfSum[sum - 1] + sum * (rCnt - apprCntSum[sum - 1]);

	return right - left;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		memset(num, 0, sizeof(int) * MAXN);
		memset(preSum, 0, sizeof(long long) * (MAXN + 1));

		memset(apprCnt, 0, sizeof(long long) * (MAX_SUM + 1));
		memset(apprCntSum, 0, sizeof(long long) * (MAX_SUM + 1));
		memset(sumOfSum, 0, sizeof(long long) * (MAX_SUM + 1));

		int N, Q;
		scanf("%d%d", &N, &Q);
		for (int i = 0; i < N; i++)
			scanf("%d", num + i);

		preSum[0] = 0;
		for (int i = 1; i <= N; i++)
			preSum[i] = preSum[i - 1] + num[i - 1];

		for (int i = 0; i < N; i++)
			for (int j = i + 1; j <= N; j++)
				apprCnt[preSum[j] - preSum[i]]++;

		for (int sum = MAX_SUM; sum >= 0; sum--)
			if (apprCnt[sum])
			{
				maxSum = sum;
				break;
			}

		sumOfSum[0] = 0;
		for (int sum = 1; sum <= maxSum; sum++)
			sumOfSum[sum] = sumOfSum[sum - 1] + sum * apprCnt[sum];

		apprCntSum[0] = 0;
		for (int sum = 1; sum <= maxSum; sum++)
			apprCntSum[sum] = apprCntSum[sum - 1] + apprCnt[sum];

		printf("Case #%d:\n", t);
		for (int i = 0; i < Q; i++)
		{
			long long L, R;
			scanf("%" PRIu64 "%" PRIu64, &L, &R);
			printf("%" PRIu64 "\n", getAns(L, R));
		}
	}
	return 0;
}
