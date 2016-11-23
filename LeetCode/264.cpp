#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int min2(int a, int b) {
		return a < b ? a : b;
	}
	int min3(int a, int b, int c) {
		return min2(a, min2(b, c));
	}
	int nthUglyNumber(int n) {
		vector<int> ugly(n, 0);
		ugly[0] = 1;
		int i2, i3, i5;
		i2 = i3 = i5 = 0;
		int n2 = ugly[i2] * 2;
		int n3 = ugly[i3] * 3;
		int n5 = ugly[i5] * 5;
		for (int i = 1; i < n; i++) {
			int num = min3(n2, n3, n5);
			ugly[i] = num;
			if (num == n2)
				n2 = ugly[++i2] * 2;
			if (num == n3)
				n3 = ugly[++i3] * 3;
			if (num == n5)
				n5 = ugly[++i5] * 5;
		}
		return ugly[n - 1];
	}
};