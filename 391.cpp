#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct pairhash {//double hash function for pair key
public:
	template <typename T, typename U>
	size_t operator()(const pair<T, U> &rhs) const {
		size_t l = hash<T>()(rhs.first);
		size_t r = hash<U>()(rhs.second);
		return l + 0x9e3779b9 + (r << 6) + (r >> 2);
	}
};

class Solution {
private:
	unordered_map<pair<int, int>, int, pairhash> corner;
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
		for (auto rec : rectangles) {
			minx = min(minx, rec[0]);
			maxx = max(maxx, rec[2]);
			miny = min(miny, rec[1]);
			maxy = max(maxy, rec[3]);
			int& m1 = corner[make_pair(rec[0], rec[1])];
			if (m1 & 1) return false; else m1 |= 1;
			int& m2 = corner[make_pair(rec[2], rec[1])];
			if (m2 & 2) return false; else m2 |= 2;
			int& m3 = corner[make_pair(rec[0], rec[3])];
			if (m3 & 4) return false; else m3 |= 4;
			int& m4 = corner[make_pair(rec[2], rec[3])];
			if (m4 & 8) return false; else m4 |= 8;
		}
		for (const auto& kv : corner) {
			pair<int, int> pos; int mask;
			tie(pos, mask) = kv;
			if ((pos.first == minx || pos.first == maxx) && (pos.second == miny || pos.second == maxy)) {
				if (mask != 1 && mask != 2 && mask != 4 && mask != 8)
					return false;
			}
			else {
				if (mask != 3 && mask != 5 && mask != 10 && mask != 12 && mask != 15)
					return false;
			}
		}
		return true;
	}
};

int main() {
	Solution slu;
	vector<vector<int>> input = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
	slu.isRectangleCover(input);
	return 0;
}