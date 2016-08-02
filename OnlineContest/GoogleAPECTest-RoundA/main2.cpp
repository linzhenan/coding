#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 50

struct Point {
	int i, j;
	Point(int i = 0, int j = 0) {
		this->i = i;
		this->j = j;
	}
};
int V[MAXN][MAXN];
int H[MAXN][MAXN];
int R, C;
int visited(int i, int j) {
	if (i < 0 || j < 0 || i > R - 1 || j > C - 1)
		return 1;
	else
		return V[i][j];
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%d", &H[i][j]);
				V[i][j] = 0;
			}
		}
		queue<Point> E;
		int Vcnt = 0;
		int Wcnt = 0;

		for (int j = 0; j < C; j++) {
			E.push(Point(0, j));
			V[0][j] = 1;
			Vcnt++;
			if (R > 1) {
				E.push(Point(R - 1, j));
				V[R - 1][j] = 1;
				Vcnt++;
			}
		}

		for (int i = 1; i < R - 1; i++) {
			E.push(Point(i, 0));
			V[i][0] = 1;
			Vcnt++;
			if (C > 1) {
				E.push(Point(i, C - 1));
				V[i][C - 1] = 1;
				Vcnt++;
			}
		}

		while (Vcnt < R * C) {
			queue<Point> Q;
			int edgechange = 1;
			while (edgechange) {
				edgechange = 0;
				while (!E.empty()) {
					Point p = E.front();
					E.pop();
					int i = p.i;
					int j = p.j;
					if (!visited(i + 1, j) && H[i + 1][j] >= H[i][j]) {
						Q.push(Point(i + 1, j));
						V[i + 1][j] = 1;
						edgechange = 1;
						Vcnt++;
					}
					if (!visited(i - 1, j) && H[i - 1][j] >= H[i][j]) {
						Q.push(Point(i - 1, j));
						V[i - 1][j] = 1;
						edgechange = 1;
						Vcnt++;
					}
					if (!visited(i, j + 1) && H[i][j + 1] >= H[i][j]) {
						Q.push(Point(i, j + 1));
						V[i][j + 1] = 1;
						edgechange = 1;
						Vcnt++;
					}
					if (!visited(i, j - 1) && H[i][j - 1] >= H[i][j]) {
						Q.push(Point(i, j - 1));
						V[i][j - 1] = 1;
						edgechange = 1;
						Vcnt++;
					}
					if (visited(i + 1, j) && visited(i - 1, j) && visited(i, j + 1) && visited(i, j - 1))
						edgechange = 1;
					else
						Q.push(p);
				}
				while (!Q.empty()) {
					Point p = Q.front();
					Q.pop();
					E.push(p);
				}
			}

			Point l;
			if (!E.empty())
				l = E.front();
			while (!E.empty()) {
				Point p = E.front();
				E.pop();
				if (H[p.i][p.j] < H[l.i][l.j])
					l = p;
				Q.push(p);
			}

			while (!Q.empty()) {
				Point p = Q.front();
				Q.pop();
				int i = p.i;
				int j = p.j;
				if (!visited(i + 1, j) && H[i + 1][j] < H[l.i][l.j]) {
					Wcnt += H[l.i][l.j] - H[i + 1][j];
					H[i + 1][j] = H[l.i][l.j];
				}
				if (!visited(i - 1, j) && H[i - 1][j] < H[l.i][l.j]) {
					Wcnt += H[l.i][l.j] - H[i - 1][j];
					H[i - 1][j] = H[l.i][l.j];
				}
				if (!visited(i, j + 1) && H[i][j + 1] < H[l.i][l.j]) {
					Wcnt += H[l.i][l.j] - H[i][j + 1];
					H[i][j + 1] = H[l.i][l.j];
				}
				if (!visited(i, j - 1) && H[i][j - 1] < H[l.i][l.j]) {
					Wcnt += H[l.i][l.j] - H[i][j - 1];
					H[i][j - 1] = H[l.i][l.j];
				}
				E.push(p);
			}
		}

		printf("Case #%d: %d\n", t, Wcnt);
	}
	return 0;
}