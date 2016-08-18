#include <cstdio>
#include <cstring>
#include <cinttypes>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
using namespace std;

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

#define MAXN 200000
int num[MAXN];
long long psum[MAXN], qsum[MAXN];
int N;

long long getSum(int left, int right)
{
	if (left == 0)
		return psum[right];
	else
		return psum[right] - psum[left - 1];
}
long long getSumOfSum(int left, int right)
{
	if (left == 0)
		return qsum[right] - (N - right - 1) * psum[right];
	else
		return qsum[right] - qsum[left - 1] - (N - right - 1) * (psum[right] - psum[left - 1]);
}
long long numOfSumsLEx(int x)
{
	long long cnt = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cnt = getSum(i, i);
		if (cnt > x)
			continue;
		
		cnt = getSum(i, N - 1);
		if (cnt <= x)
		{
			sum += cnt;
			continue;
		}

		int l = i;
		int r = N - 1;
		int m;
		while (l < r)
		{
			m = l + (r - l) / 2;
			if (getSum(l, m) > x)
				r = m;
			else
				l = m + 1;
		}
		assert(l == r);
		assert(getSum(i, l) > x);
		assert(getSum(i, l - 1) <= x);
		cnt = getSum(i, l - 1);
		sum += cnt;
	}
}
int findx(long long left)
{

}
long long getAns(long long left, long long right)
{
	long long l, r, m;
	l = 0;
	r = N * 100;
	m = l + (r - l) / 2;
	while (l < r)
	{
		
	}


}
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int Q;
		scanf("%d%d", &N, &Q);
		for (int i = 0; i < N; i++)
			scanf("%d", num + i);
		psum[0] = num[0];
		for (int i = 1; i < N; i++)
			psum[i] = psum[i - 1] + num[i];
		for (int i = 0; i < N; i++)
			qsum[i] = (N - i) * num[i];

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