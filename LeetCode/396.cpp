class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		if (n == 0) return 0;
		int sum = 0;
		int mulsum = 0;
		for (int i = 0; i < n; i++) {
			sum += A[i];
			mulsum += i * A[i];
		}
		int maxVal = mulsum;
		for (int i = 1; i < n; i++) {
			mulsum += sum - n * A[n - i];
			maxVal = max(maxVal, mulsum);
		}
		return maxVal;
	}
};