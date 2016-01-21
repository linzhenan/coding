//Ugly Number II

class Solution {
public:
	bool isUglyNumber(int num) {
		if (num <= 0)
			return false;
		while (num) {
			if (num == 1)
				return true;
			else if (num % 2 == 0)
				num = num / 2;
			else if (num % 3 == 0)
				num = num / 3;
			else if (num % 5 == 0)
				num = num / 5;
			else
				return false;
		}
	}
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;
		int num = 0;
		while (n) {
			num++;
			if (isUglyNumber(num))
				n--;
		}
		return num;
	}
};