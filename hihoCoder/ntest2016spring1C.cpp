#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Line {
	int x0;
	int x1;
	int y0;
	int y1;
	double b;
	int z0;
	int z1;
};

void swap(int *a, int *b) {
	if (a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
static bool cmp(Line a, Line b) {
	if (a.b < b.b)
		return true;
	else if (a.b == b.b) {
		if (a.z0 < b.z0)
			return true;
		else
			return false;
	}
	else
		return false;
}
void main(void) {
	vector<Line> lines[4];
	int cnt[4];
	int S, N;
	
	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> N;
		for (int k = 0; k < 4; k++) {
			lines[k].clear();
			cnt[k] = 0;
		}
		for (int j = 0; j < N; j++) {
			Line line;
			cin >> line.x0 >> line.y0 >> line.x1 >> line.y1;
			if (line.x0 == line.x1) {//垂直
				line.b = line.x0;
				if (line.y0 > line.y1)
					swap(&line.y0, &line.y1);
				line.z0 = line.y0;
				line.z1 = line.y1;
				lines[0].push_back(line);
			}
			else if (line.y0 == line.y1) {//水平
				line.b = line.y0;
				if (line.x0 > line.x1)
					swap(&line.x0, &line.x1);
				line.z0 = line.x0;
				line.z1 = line.x1;
				lines[1].push_back(line);
			}
			else if (line.y1 - line.y0 == line.x1 - line.x0) {//45度
				line.b = 1.0 * (line.y1 - line.y0) / (line.x1 - line.x0) * (0 - line.x0) + line.y0;
				if (line.x0 > line.x1) {
					swap(&line.x0, &line.x1);
					swap(&line.y0, &line.y1);
				}
				line.z0 = line.x0;
				line.z1 = line.x1;
				lines[2].push_back(line);
			}
			else {//负45度
				line.b = 1.0 * (line.y1 - line.y0) / (line.x1 - line.x0) * (0 - line.x0) + line.y0;
				if (line.x0 > line.x1) {
					swap(&line.x0, &line.x1);
					swap(&line.y0, &line.y1);
				}
				line.z0 = line.x0;
				line.z1 = line.x1;
				lines[3].push_back(line);
			}
		}
		for (int k = 0; k < 4; k++)
			sort(lines[k].begin(), lines[k].end(), cmp);
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			if (lines[k].size() > 0) {
				cnt++;
				int last_b = lines[k][0].b;
				int last_z = lines[k][0].z1;
				for (int j = 1; j < lines[k].size(); j++) {
					if (lines[k][j].b != last_b) {
						cnt++;
						last_b = lines[k][j].b;
						last_z = lines[k][j].z1;
					}
					else {
						if (lines[k][j].z0 > last_z)
							cnt++;
						last_z = max(lines[k][j].z1, last_z);
					}
				}
			}
		}
		cout << cnt << endl;
	}
}