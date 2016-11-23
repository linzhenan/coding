#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct PairHash
{
public:
	size_t operator()(const pair<int, int> &s) const
	{
		size_t h1 = hash<int>()(s.first);
		size_t h2 = hash <int>()(s.second);
		return h1 ^ (h2 << 1);
	}
};

typedef numeric_limits<double> dbl;
typedef vector<vector<char>> Matrix;
typedef unordered_map<pair<int, int>, int, PairHash> CountMap;

vector<pair<int, int>> GetNeighbors(int R, int C, int r, int c)
{
	vector<pair<int, int>> neighbors;
	if (r > 0) neighbors.push_back(make_pair(r - 1, c));
	if (c > 0) neighbors.push_back(make_pair(r, c - 1));
	if (r < R - 1) neighbors.push_back(make_pair(r + 1, c));
	if (c < C - 1) neighbors.push_back(make_pair(r, c + 1));
	return neighbors;
}

double CatchMonsters(const Matrix &grid, const CountMap &path, double p, double q)
{
	double monsters = 0;
	for (auto kv : path)
	{
		double prob = grid[kv.first.first][kv.first.second] == 'A' ? p : q;
		monsters += 1 - pow(1 - prob, kv.second);
	}
	return monsters;
}

void MaxMonsters(int R, int C, int i, int j, int S, double p, double q, const Matrix &grid,
	int n, CountMap &path, double &max_monsters)
{
	if (n == S)
	{
		max_monsters = max(max_monsters, CatchMonsters(grid, path, p, q));
		return;
	}
	for (auto pos : GetNeighbors(R, C, i, j))
	{
		++path[pos];
		MaxMonsters(R, C, pos.first, pos.second, S, p, q, grid, n + 1, path, max_monsters);
		--path[pos];
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int R, C, i, j, S;
		double P, Q;
		cin >> R >> C >> i >> j >> S >> P >> Q;
		Matrix grid(R, vector<char>(C));
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
				cin >> grid[r][c];
		}
		CountMap path;
		double max_monsters = 0;
		MaxMonsters(R, C, i, j, S, P, Q, grid, 0, path, max_monsters);
		//cout.precision(dbl::digits10);
		//cout << "Case #" << t << ": " << max_monsters << endl;
		printf("Case #%d: %.7lf\n", t, max_monsters);
	}
	return 0;
}