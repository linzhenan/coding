//Unique Binary Search Trees

class Solution {
public:
	int numTrees(int left, int right) {
		if (left == right)
			return 1;
		int num = 0;
		num += numTrees(left + 1, right);
		num += numTrees(left, right - 1);
		for (int i = left + 1; i <= right - 1; i++)
			num += numTrees(left, i - 1) * numTrees(i + 1, right);
		return num;
	}
	int numTrees(int n) {
		//return numTrees(1, n);
		int f[n + 1];

		f[0] = 1;
		if (n == 0)
			return f[0];

		f[1] = 1;
		if (n == 1)
			return f[1];

		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 1];
			for (int root = 2; root <= i - 1; root++)
				f[i] += f[root - 1] * f[i - root];
		}
		return f[n];
	}
};