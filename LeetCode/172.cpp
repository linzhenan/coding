//Factorial Trailing Zeroes

class Solution {
public:
	int trailingZeroes(int n) {
		int num = 0;
		while (n / 5) {
			num += n / 5;
			n = n / 5;
		}
		return num;
	}
};