#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int round = 0;

	cin >> n;
	vector<int> num(n + 1, 0);
	vector<bool> visit(n + 1, 0);
	vector<bool> curr(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++)
	{
		if (num[i] == i) {
			round++;
			visit[i] = true;
		}
	}
	while (1) {
		int start = -1;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				start = i;
				break;
			}
		}
		if (start == -1)
			break;
		for (int i = 1; i <= n; i++)
			curr[i] = false;
		while (!visit[start]) {
			visit[start] = true;
			curr[start] = true;
			start = num[start];
			if (curr[start]) {
				round++;
				break;
			}
		}
	}
	cout << round;
}