//Bitwise AND of Numbers Range

class Solution {
public:
	int rangeBitwiseAnd1(int m, int n) {
		int ret = m;
		for (int i = m + 1; m <= n; i++)
			ret = ret & i;
		return ret;
	}
	int rangeBitwiseAnd(int m, int n) {
		int ret = 0;
		int bitpos = 0;
		while (m || n) {
			if (m == n) {
				ret += (m & 0x01) << bitpos;
			}
			m = m >> 1;
			n = n >> 1;
			bitpos++;
		}
		return ret;
	}
};