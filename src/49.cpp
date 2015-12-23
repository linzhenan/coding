//Group Anagrams

//Test Cases:
//[""]
//["eat", "tea", "tan", "ate", "nat", "bat"]

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> group;
		for (auto &s : strs) {
			string key = s;
			sort(key.begin(), key.end());
			group[key].push_back(s);
		}

		for (auto it = group.begin(); it != group.end(); it++) {
			sort(it->second.begin(), it->second.end());
			result.push_back(it->second);
		}
		return result;
	}
};