#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

int getHostId(string res) {
	int pos = 0;
	for (; pos < res.size(); pos++)
		if (res[pos] == ',')
			break;
	string hostId = res.substr(0, pos + 1);
	return atoi(hostId.c_str());
}
vector <string> paginate(int num, vector<string> results) {
	//return results;
	set<int> idxset;
	int n = results.size();
	for (int i = 0; i < n; i++)
		idxset.insert(i);

	vector<int> resultsHostId;
	for (int i = 0; i < results.size(); i++)
		resultsHostId.push_back(getHostId(results[i]));

	vector<string> output;

	while (!idxset.empty()) {
		unordered_map<int, bool> hash;
		int cnt = 0;

		vector<int> del;

		for (auto idx : idxset) {
			int hostId = resultsHostId[idx];
			if (hash.find(hostId) == hash.end()) {
				output.push_back(results[idx]);
				hash[hostId] = true;
				//idxset.erase(idx);
				del.push_back(idx);
				cnt++;
				if (cnt == num)
					break;
			}
		}
		for (auto idx : del)
			idxset.erase(idx);
		
		
		if (cnt < num && !idxset.empty()) {
			del.clear();
			for (auto idx : idxset) {
				output.push_back(results[idx]);
				//idxset.erase(idx);
				del.push_back(idx);
				cnt++;
				if (cnt == num)
					break;
			}
			for (auto idx : del)
				idxset.erase(idx);
		}


		if (!idxset.empty())
			output.push_back("");
	}

	return output;
}
int main() {
	vector<string> input = {
		"1,28,0,0",
		"4,5,0,0",
		"20,7,0,0",
		"6,8,0,0",
		"6,10,0,0",
		"1,16,0,0",
		"6,29,0,0",
		"7,20,0,0",
		"6,21,0,0",
		"2,18,0,0",
		"2,30,0,0",
		"3,76,0,0",
		"2,14,0,0"
	};
	paginate(5, input);
	return 0;
}