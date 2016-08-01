#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define MAXN 12
#define MAXK 10
int L[MAXN];
int K[MAXN];
int A[MAXN][MAXK];
int C[MAXN][MAXK - 1];

int smalldata() {
	int T;
	scanf("%d", &T);
	int f[1001];
	for (int t = 1; t <= T; t++) {
		int M, N;
		scanf("%d%d", &M, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &K[i], &L[i]);
			for (int l = 0; l < K[i]; l++)
				scanf("%d", &A[i][l]);
			for (int l = 0; l < K[i] - 1; l++)
				scanf("%d", &C[i][l]);
		}
		for ()
		for (int i = 0; i < N; i++) {
			for (int l = L[i]; l < K[i]; l++) {

			}
		}
	}
	return 0;
}
int main() {


	return 0;
}