#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#pragma warning(disable:4996)

#define N 21

int main() {
	int64_t map[N][N] = { 0 };
	int posi[9], posj[9];
	int bi, bj, ci, cj;
	scanf("%d%d%d%d", &bi, &bj, &ci, &cj);
	posi[0] = ci; posj[0] = cj;
	posi[1] = ci - 2; posj[1] = cj - 1;
	posi[2] = ci - 2; posj[2] = cj + 1;
	posi[3] = ci - 1; posj[3] = cj - 2;
	posi[4] = ci - 1; posj[4] = cj + 2;
	posi[5] = ci + 1; posj[5] = cj - 2;
	posi[6] = ci + 1; posj[6] = cj + 2;
	posi[7] = ci + 2; posj[7] = cj - 1;
	posi[8] = ci + 2; posj[8] = cj + 1;
	map[0][0] = 1;
	for (int j = 1; j < N; j++) {
		map[0][j] = map[0][j - 1];
		for (int k = 0; k < 9; k++)
			if (posi[k] == 0 && posj[k] == j) {
				map[0][j] = 0;
				break;
			}
	}
	for (int i = 1; i < N; i++) {
		map[i][0] = map[i - 1][0];
		for (int k = 0; k < 9; k++)
			if (posi[k] == i && posj[k] == 0) {
				map[i][0] = 0;
				break;
			}
	}
	for (int i = 1; i <= bi; i++) {
		for (int j = 1; j <= bj; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1];
			for (int k = 0; k < 9; k++)
				if (posi[k] == i && posj[k] == j) {
					map[i][j] = 0;
					break;
				}
		}
	}
	printf("%" PRId64 "\n", map[bi][bj]);

	return 0;
}