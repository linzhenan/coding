//Dungeon Game

class Solution {
public:
	int fromLUtoRD(vector<vector<int>>& dungeon) {//error
		int h = dungeon.size();
		if (h == 0)
			return 1;
		int w = dungeon[0].size();
		if (w == 0)
			return 1;

		vector<vector<int>> minVal = vector<vector<int>>(dungeon);
		for (int x = 1; x < w; x++) {
			dungeon[0][x] += dungeon[0][x - 1];
			minVal[0][x] = min(minVal[0][x - 1], dungeon[0][x]);
		}
		for (int y = 1; y < h; y++) {
			dungeon[y][0] += dungeon[y - 1][0];
			minVal[y][0] = min(minVal[y - 1][0], dungeon[y][0]);
		}

		for (int y = 1; y < h; y++)
			for (int x = 1; x < w; x++) {
				if (minVal[y - 1][x] < minVal[y][x - 1]) {
					dungeon[y][x] += dungeon[y][x - 1];
					minVal[y][x] = min(minVal[y][x - 1], dungeon[y][x]);
				}
				else if (minVal[y - 1][x] > minVal[y][x - 1]) {
					dungeon[y][x] += dungeon[y - 1][x];
					minVal[y][x] = min(minVal[y - 1][x], dungeon[y][x]);
				}
				else {
					if (dungeon[y - 1][x] < dungeon[y][x - 1]) {
						dungeon[y][x] += dungeon[y][x - 1];
						minVal[y][x] = min(minVal[y][x - 1], dungeon[y][x]);
					}
					else {
						dungeon[y][x] += dungeon[y - 1][x];
						minVal[y][x] = min(minVal[y - 1][x], dungeon[y][x]);
					}
				}
			}
		return max(1, 1 - minVal[h - 1][w - 1]);
	}
	int fromRDtoLU(vector<vector<int>>& dungeon) {//error
		int h = dungeon.size();
		if (h == 0)
			return 1;
		int w = dungeon[0].size();
		if (w == 0)
			return 1;

		vector<vector<int>> minVal = vector<vector<int>>(dungeon);
		for (int x = w - 2; x >= 0; x--) {
			dungeon[h - 1][x] += dungeon[h - 1][x + 1];
			minVal[h - 1][x] = min(minVal[h - 1][x + 1], dungeon[h - 1][x]);
		}
		for (int y = h - 2; y >= 0; y--) {
			dungeon[y][w - 1] += dungeon[y + 1][w - 1];
			minVal[y][w - 1] = min(minVal[y + 1][w - 1], dungeon[y][w - 1]);
		}

		for (int y = h - 2; y >= 0; y--)
			for (int x = w - 2; x >= 0; x--) {
				if (minVal[y + 1][x] < minVal[y][x + 1]) {
					dungeon[y][x] += dungeon[y][x + 1];
					minVal[y][x] = min(minVal[y][x + 1], dungeon[y][x]);
				}
				else if (minVal[y + 1][x] > minVal[y][x + 1]) {
					dungeon[y][x] += dungeon[y + 1][x];
					minVal[y][x] = min(minVal[y + 1][x], dungeon[y][x]);
				}
				else {
					if (dungeon[y + 1][x] < dungeon[y][x + 1]) {
						dungeon[y][x] += dungeon[y][x + 1];
						minVal[y][x] = min(minVal[y][x + 1], dungeon[y][x]);
					}
					else {
						dungeon[y][x] += dungeon[y + 1][x];
						minVal[y][x] = min(minVal[y + 1][x], dungeon[y][x]);
					}
				}
			}
		return max(1, 1 - minVal[0][0]);
	}
	int minHP(int x) {
		if (x <= 0)
			return 1;
		else
			return x;
	}
	int calcMinHP(vector<vector<int>>& d) {
		int h = d.size();
		int w = d[0].size();
		vector<vector<int>> f = vector<vector<int>>(h, vector<int>(w));

		f[h - 1][w - 1] = minHP(1 - d[h - 1][w - 1]);
		for (int x = w - 2; x >= 0; x--)
			f[h - 1][x] = minHP(f[h - 1][x + 1] - d[h - 1][x]);
		for (int y = h - 2; y >= 0; y--)
			f[y][w - 1] = minHP(f[y + 1][w - 1] - d[y][w - 1]);
		for (int y = h - 2; y >= 0; y--)
			for (int x = w - 2; x >= 0; x--)
				f[y][x] = minHP(min(f[y + 1][x], f[y][x + 1]) - d[y][x]);
		return f[0][0];
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		return calcMinHP(dungeon);
	}
};