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
int isAdjacent(struct Cube cube[LEN][LEN][LEN], int x, int y, int z) {
	if (z == 1)
		return 1;
	if (cube[x - 1][y][z].placed || cube[x + 1][y][z].placed ||
		cube[x][y - 1][z].placed || cube[x][y + 1][z].placed ||
		cube[x][y][z - 1].placed || cube[x][y][z + 1].placed)
		return 1;
	return 0;
}
void dfs(struct Cube cube[LEN][LEN][LEN], int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0 ||
		x > 101 || y > 101 || z > 101)
		return;
	if (cube[x][y][z].visited)
		return;
	cube[x][y][z].visited = 1;
	if (cube[x][y][z].placed)
		return;
	dfs(cube, x - 1, y, z);
	dfs(cube, x, y - 1, z);
	dfs(cube, x, y, z - 1);
	dfs(cube, x + 1, y, z);
	dfs(cube, x, y + 1, z);
	dfs(cube, x, y, z + 1);
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
			if (!isAdjacent(cube, x, y, z)) {
				errflag = 1;
				break;
			}
			cube[x][y][z].placed = 1;
			pos[i].x = x;
			pos[i].y = y;
			pos[i].z = z;
		}
		if (!errflag) {
			//dfs(cube, 101, 101, 101);
			struct CubePos p = { 101, 101, 101 };
			q.push(p);
			while (!q.empty()) {
				x = q.front().x;
				y = q.front().y;
				z = q.front().z;
				q.pop();
				if (!cube[x][y][z].visited && !cube[x][y][z].placed) {
					p.x = x - 1; p.y = y; p.z = z;
					if (p.x >= 0) q.push(p);
					p.x = x; p.y = y - 1; p.z = z;
					if (p.y >= 0) q.push(p);
					p.x = x; p.y = y; p.z = z - 1;
					if (p.z > 0) q.push(p);

					p.x = x + 1; p.y = y; p.z = z;
					if (p.x <= 101) q.push(p);
					p.x = x; p.y = y + 1; p.z = z;
					if (p.y <= 101) q.push(p);
					p.x = x; p.y = y; p.z = z + 1;
					if (p.z <= 101) q.push(p);
				}
				cube[x][y][z].visited = 1;
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