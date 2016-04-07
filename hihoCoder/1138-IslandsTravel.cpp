#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 100000
#define DISMAX 1000000000
int dis[NMAX];
int X[NMAX];
int Y[NMAX];
int inc[NMAX];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> X[i] >> Y[i];
	
	dis[0] = 0;
	inc[0] = 1;
	for (int i = 1; i < N; i++) {
		dis[i] = min(abs(X[i] - X[0]), abs(Y[i] - Y[0]));
		inc[i] = 0;
	}

	for (int i = 1; i < N; i++) {
		int minDis = DISMAX;
		int pos = 0;
		for (int j = 1; j < N; j++)
			if (!inc[j] && dis[j] < minDis) {
				minDis = dis[j];
				pos = j;
			}
		inc[pos] = 1;
		if (pos == N - 1)
			break;
		for (int j = 1; j < N; j++) {
			if (inc[j]) continue;
			int distmp = min(abs(X[j] - X[pos]), abs(Y[j] - Y[pos]));
			distmp += dis[pos];
			if (distmp < dis[j])
				dis[j] = distmp;
		}
	}
	cout << dis[N - 1] << endl;
	return 0;
}