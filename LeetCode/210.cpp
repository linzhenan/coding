//Course Schedule II

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		int n = numCourses;
		int m = prerequisites.size();
		vector<int> res = vector<int>();
		if (n == 0)
			return res;
		if (m == 0) {
			for (int i = 0; i < n; i++)
				res.push_back(i);
			return res;
		}

		unordered_map<int, int> inDegree;
		unordered_map<int, vector<int>> outNode;
		for (int i = 0; i < n; i++) {
			inDegree[i] = 0;
			outNode[i] = vector<int>();
		}
		for (auto p : prerequisites) {
			inDegree[p.first]++;
			outNode[p.second].push_back(p.first);
		}

		queue<int> q;
		for (int i = 0; i < n; i++)
			if (inDegree[i] == 0)
				q.push(i);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (auto i : outNode[node]) {
				inDegree[i]--;
				if (inDegree[i] == 0)
					q.push(i);
			}
		}

		for (int i = 0; i < n; i++)
			if (inDegree[i] != 0) {
				res.clear();
				break;
			}
		return res;
	}
};