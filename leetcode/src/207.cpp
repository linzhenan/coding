//Course Schedule
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int n = numCourses;
		if (n == 0)
			return false;
		int m = prerequisites.size();
		if (m == 0)
			return true;

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
			for (auto e : outNode[node]) {
				inDegree[e]--;
				if (inDegree[e] == 0)
					q.push(e);
			}
		}
		for (int i = 0; i < n; i++)
			if (inDegree[i])
				return false;
		return true;
	}
};