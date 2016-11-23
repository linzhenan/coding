class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int k = primes.size();
		vector<int> idx(k, 0);
		vector<int> num(k, 1);
		vector<int> ugly(n);
		ugly[0] = 1;
		for (int j = 0; j < k; j++)
			num[j] *= ugly[idx[j]] * primes[j];
		for (int i = 1; i < n; i++) {
			int minnum = INT_MAX;
			for (int j = 0; j < k; j++) {
				if (num[j] < minnum)
					minnum = num[j];
			}
			ugly[i] = minnum;
			for (int j = 0; j < k; j++) {
				if (num[j] == minnum)
					num[j] = ugly[++idx[j]] * primes[j];
			}
		}
		return ugly[n - 1];
	}
};