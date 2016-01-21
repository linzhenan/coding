//Bulb Switcher

class Solution {
public:
	int factorNum(int num) {
		int n = 0;
		for (int i = 1; i <= sqrt(num); i++) {
			if (num % i == 0) {
				int j = num / i;
				if (i == j)
					n++;
				else
					n += 2;
			}
		}
		return n;
	}
	int bulbSwitchOverstack(int n) {
		if (n == 0)
			return 0;
		bool f[n];
		for (int i = 0; i < n; i++)
			f[i] = false;
		for (int r = 1; r <= n; r++) {
			for (int pos = r - 1; pos < n; pos += r)
				f[pos] = !f[pos];
		}
		int num = 0;
		for (int i = 0; i < n; i++)
			if (f[i])
				num++;
		return num;
	}
	int bulbSwitch(int n) {
		int root = sqrt(n);
		return root;

		if (n == 0)
			return 0;
		int num = 1;
		for (int i = 2; i < n; i++) {
			//if (factorNum(i) & 0x01)
			int root = sqrt(i);
			if (root * root == i)
				num++;
		}
		return num;
	}
};