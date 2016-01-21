//Permutation Sequence

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<char> seq;
		for (int i = 1; i <= n; i++)
			seq.push_back(i + '0');
		int f[n] = { 0 };
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		string res;
		k--;
		for (int i = 1; i <= n; i++) {
			int idx = k / f[n - i];
			res += seq[idx];
			seq.erase(seq.begin() + idx);
			k = k % f[n - i];
		}
		return res;
	}
};