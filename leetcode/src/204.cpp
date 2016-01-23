//Count Primes

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime = vector<bool>(n, true);
		for (int i = 2; i * i < n; i++)
			if (isPrime[i])
				for (int k = i * i; k < n; k += i)
					isPrime[k] = false;
		int num = 0;
		for (int i = 2; i < n; i++)
			if (isPrime[i])
				num++;
		return num;
	}
};