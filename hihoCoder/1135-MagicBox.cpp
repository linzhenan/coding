#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void swap(int *a, int *b) {
	if (a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
void sort3(int *a, int *b, int *c) {
	if (*a > *b) swap(a, b);
	if (*a > *c) swap(a, c);
	if (*b > *c) swap(b, c);
}
int main() {
	string str;
	int Cr, Cy, Cb;
	int x, y, z;
	int diff[3];

	cin >> x >> y >> z; getline(cin, str);
	sort3(&x, &y, &z);
	getline(cin, str);
	int n = str.size();
	int currcnt = 0;
	int maxcnt = 0;
	Cr = Cy = Cb = 0;
	for (int i = 0; i < n; i++) {
		switch (str[i]) {
		case 'R': Cr++; break;
		case 'Y': Cy++; break;
		case 'B': Cb++; break;
		}
		currcnt++;
		maxcnt = max(maxcnt, currcnt);
		diff[0] = abs(Cr - Cy);
		diff[1] = abs(Cy - Cb);
		diff[2] = abs(Cb - Cr);
		sort3(&diff[0], &diff[1], &diff[2]);
		if (x == diff[0] &&
			y == diff[1] &&
			z == diff[2]) {
			Cr = 0;
			Cy = 0;
			Cb = 0;
			currcnt = 0;
		}
	}
	cout << maxcnt << endl;
	return 0;
}