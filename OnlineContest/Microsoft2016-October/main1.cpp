#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

	int odd, even;
	int n;
	int num;
	
	cin >> n;
	odd = even = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num & 1)
			odd++;
		else
			even++;
	}

	cout << abs(odd - even) << endl;
}