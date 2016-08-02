#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<iostream>
using namespace std;
int main() {
	long long h;
	while (cin >> h) {
		int x = (int)(sqrt(h + 0.25) - 0.5);
		printf("%d\n", x);
	}

	return 0;
}