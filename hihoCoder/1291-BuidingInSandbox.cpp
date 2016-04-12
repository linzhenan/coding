#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <queue>
using namespace std;
#define LEN 102
#define MAXN 100000
struct Cube {
	int placed;
	int visited;
}cube[LEN][LEN][LEN];
struct CubePos {
	int x;
	int y;
	int z;
}pos[MAXN];
queue<struct CubePos> q;
int isValid(struct Cube cube[LEN][LEN][LEN], int x, int y, int z) {
	if (cube[x][y][z].placed)
		return 0;
	if (z == 1)
		return 1;
	if (cube[x - 1][y][z].placed || cube[x + 1][y][z].placed ||
		cube[x][y - 1][z].placed || cube[x][y + 1][z].placed ||
		cube[x][y][z - 1].placed || cube[x][y][z + 1].placed)
		return 1;
	return 0;
}
int isEmpty(struct Cube cube[LEN][LEN][LEN], int x, int y, int z) {
	if (0 <= x && x < LEN &&
		0 <= y && y < LEN &&
		0 <= z && z < LEN &&
		!cube[x][y][z].visited)
	{
		cube[x][y][z].visited = 1;
		if (!cube[x][y][z].placed)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

int main() {
	int T, N;
	int x, y, z;
	int errflag;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		errflag = 0;
		memset(cube, 0, sizeof(struct Cube) * LEN * LEN * LEN);
		memset(pos, 0, sizeof(struct CubePos) * MAXN);
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &x, &y, &z);
			if (!isValid(cube, x, y, z)) {
				errflag = 1;
				break;
			}
			cube[x][y][z].placed = 1;
			pos[i].x = x;
			pos[i].y = y;
			pos[i].z = z;
		}
		for (int x = 0; x < LEN; x++)
			for (int y = 0; y < LEN; y++)
				cube[x][y][0].placed = 1;
		if (!errflag) {
			struct CubePos p = { LEN - 1, LEN - 1, LEN - 1 };
			if (isEmpty(cube, LEN - 1, LEN - 1, LEN - 1)) q.push(p);//always true
			while (!q.empty()) {
				x = q.front().x;
				y = q.front().y;
				z = q.front().z;
				q.pop();

				p.x = x - 1; p.y = y; p.z = z;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);
				p.x = x; p.y = y - 1; p.z = z;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);
				p.x = x; p.y = y; p.z = z - 1;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);

				p.x = x + 1; p.y = y; p.z = z;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);
				p.x = x; p.y = y + 1; p.z = z;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);
				p.x = x; p.y = y; p.z = z + 1;
				if (isEmpty(cube, p.x, p.y, p.z)) q.push(p);
			}
			for (int i = 0; i < N; i++)
				if (!cube[pos[i].x][pos[i].y][pos[i].z].visited) {
					errflag = 1;
					break;
				}
		}
		if (errflag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}