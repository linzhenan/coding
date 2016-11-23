#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void traverse(string from, vector<string>& route, unordered_map<string, multiset<string>>& port_map)
	{
		while (port_map[from].size())
		{
			auto next = port_map[from].begin();
			string nextstr = *next;
			port_map[from].erase(next);
			traverse(nextstr, route, port_map);
		}
		route.push_back(from);
	}
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets)
	{
		unordered_map<string, multiset<string>> port_map;
		for (auto& pair : tickets) port_map[pair.first].insert(pair.second);
		vector<string> route;
		traverse("JFK", route, port_map);
		return vector<string>(route.rbegin(), route.rend());
	}
};

int main() {
	vector<pair<string, string>> input = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	vector<pair<string, string>> input2 = { {"JFK", "bbb"}, {"JFK", "ccc"}, {"ccc", "ddd"}, {"ddd", "bbb"} };
	//[ ["JFK", "bbb"], [ "JFK", "ccc" ], [ "ccc", "ddd" ], [ "ddd", "bbb" ] ];
	Solution slu;
	vector<string> res;
	//res = slu.findItinerary(input);
	res = slu.findItinerary(input2);
	return 0;
}