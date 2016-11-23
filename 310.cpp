#include<vector>

using namespace std;

class Solution {
private:
	int cutLeaves(vector<vector<int>> &nodelink, vector<bool> &flag) {
		vector<int> leaves;
		for (int i = 0; i < nodelink.size(); i++) {
			if (nodelink[i].size() == 1)
				leaves.push_back(i);
		}
		for (auto leaf : leaves) {
			int j = nodelink[leaf][0];
			for (int i = 0; i < nodelink[j].size(); i++) {
				if (nodelink[j][i] == leaf) {
					nodelink[j].erase(nodelink[j].begin() + i);
					break;
				}
			}
			nodelink[leaf].pop_back();
			flag[leaf] = false;
		}
		return leaves.size();
	}
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> res;
		vector<vector<int>> nodelink(n);
		vector<bool> flag(n, true);

		for (auto p : edges) {
			nodelink[p.first].push_back(p.second);
			nodelink[p.second].push_back(p.first);
		}
		while (n > 2)
			n -= cutLeaves(nodelink, flag);

		for (int i = 0; i < nodelink.size(); i++) {
			if (flag[i])
				res.push_back(i);
		}

		return res;
	}
};

int main() {
	vector<pair<int, int>> input = {{1, 0}, {1, 2}, {1, 3}};
	Solution slu;
	vector<int> res = slu.findMinHeightTrees(4, input);
	return 0;
}