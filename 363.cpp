#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (!matrix.size())
			return 0;
		if (!matrix[0].size())
			return 0;
		int res = INT_MIN;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < col; i++) {
			vector<int> sums(row, 0);
			for (int j = i; j < col; j++) {
				for (int r = 0; r < row; r++)
					sums[r] += matrix[r][j];
				set<int> sumset;
				sumset.insert(0);
				int currsum = 0;
				int maxsum = INT_MIN;
				for (int r = 0; r < row; r++) {
					currsum += sums[r];
					//TLE
					//auto it = sumset.lower_bound(sumset.begin(), sumset.end(), currsum - k);
					auto it = sumset.lower_bound(currsum - k);
					if (it != sumset.end()) maxsum = max(maxsum, currsum - *it);
					sumset.insert(currsum);
				}
				res = max(res, maxsum);
			}
		}
		return res;
	}
};