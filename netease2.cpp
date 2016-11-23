#include <cstdio>
#include <cstdlib>

using namespace std;
char grid[8][9];
int isSameSide(int x, int y, int t) {
	if (x < 0 || y < 0 || x >= 8 || y >= 8)
		return 0;
	char step = t ? 'o' : '*';
	if (grid[x][y] == step)
		return 1;
	else
		return 0;
}
void printfgrid() {
	printf("========\n");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	printf("========\n");
}
int main() {
	int S;
	scanf("%d", &S);
	char ch;
	scanf("%d", &ch);
	for (int s = 0; s < S; s++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%c", &grid[i][j]);
			}
			scanf("%c", &grid[i][8]);
		}
		int n;
		scanf("%d", &n);
		//if (s == 1)
		//	printfgrid();
		int x, y, t;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &x, &y, &t);
			scanf("%c", &ch);
			char step = t ? 'o' : '*';
			char anti = t ? '*' : 'o';
			grid[x][y] = step;
			
			int k, l;
			
			for (k = x - 1; k >= 0 && grid[k][y] == anti; k--);
			if (k >= 0 && grid[k][y] == step)
				for (k = x - 1; k >= 0 && grid[k][y] == anti; k--)
					grid[k][y] = step;
			
			for (k = x + 1; k < 8 && grid[k][y] == anti; k++);
			if (k < 8 && grid[k][y] == step)
				for (k = x + 1; k < 8 && grid[k][y] == anti; k++)
					grid[k][y] = step;

			for (l = y - 1; l >= 0 && grid[x][l] == anti; l--);
			if (l >= 0 && grid[x][l] == step)
				for (l = y - 1; l >= 0 && grid[x][l] == anti; l--)
					grid[x][l] = step;

			for (l = y + 1; l < 8 && grid[x][l] == anti; l++);
			if (l < 8 && grid[x][l] == step)
				for (l = y + 1; l < 8 && grid[x][l] == anti; l++)
					grid[x][l] = step;

			for (k = x - 1, l = y - 1; k >= 0 && l >= 0 && grid[k][l] == anti; k--, l--);
			if (k >= 0 && l >= 0 && grid[k][l] == step)
				for (k = x - 1, l = y - 1; k >= 0 && l >= 0 && grid[k][l] == anti; k--, l--)
					grid[k][l] = step;

			for (k = x - 1, l = y + 1; k >= 0 && l < 8 && grid[k][l] == anti; k--, l++);
			if (k >= 0 && l < 8 && grid[k][l] == step)
				for (k = x - 1, l = y + 1; k >= 0 && l < 8 && grid[k][l] == anti; k--, l++)
					grid[k][l] = step;

			for (k = x + 1, l = y - 1; k < 8 && l >= 0 && grid[k][l] == anti; k++, l--);
			if (k < 8 && l >= 0 && grid[k][l] == step)
				for (k = x + 1, l = y - 1; k < 8 && l >= 0 && grid[k][l] == anti; k++, l--)
					grid[k][l] = step;

			for (k = x + 1, l = y + 1; k < 8 && l < 8 && grid[k][l] == anti; k++, l++);
			if (k < 8 && l < 8 && grid[k][l] == step)
				for (k = x + 1, l = y + 1; k < 8 && l < 8 && grid[k][l] == anti; k++, l++)
					grid[k][l] = step;
/*
			if (s == 1)
				printfgrid();*/
			/*if (isSameSide(x - 2, y    , t)) grid[x - 1][y    ] = step;
			if (isSameSide(x - 2, y - 2, t)) grid[x - 1][y - 1] = step;
			if (isSameSide(x    , y - 2, t)) grid[x    ][y - 1] = step;
			if (isSameSide(x + 2, y - 2, t)) grid[x + 1][y - 1] = step;
			if (isSameSide(x + 2, y    , t)) grid[x + 1][y    ] = step;
			if (isSameSide(x + 2, y + 2, t)) grid[x + 1][y + 1] = step;
			if (isSameSide(x    , y + 2, t)) grid[x    ][y + 1] = step;
			if (isSameSide(x - 2, y + 2, t)) grid[x - 1][y + 1] = step;*/
			//printfgrid();
		}
		int white, black;
		white = black = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (grid[i][j] == '*') black++;
				else if (grid[i][j] == 'o') white++;
			}
		}
		printf("%d %d\n", black, white);
	}
	return 0;
}