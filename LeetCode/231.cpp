//Power of Two

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		int one = 0;
		for (int i = 0; i < 31; i++) {
			if (n & 0x01)
				one++;
			n = n >> 1;
			if (one > 1)
				return false;
		}
		return true;
	}
};