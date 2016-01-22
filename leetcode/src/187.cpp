//Repeated DNA Sequences

class Solution {
public:
	vector<string> findRepeatedDnaSequences1(string s) {
		vector<string> res;
		int n = s.size();
		//for (int i = 0; i < s.size() - 10; i++) { //s.size() - 10 always returns an unsigned val
		for (int i = 0; i < n - 10; i++) {
			string temp1 = s.substr(i, 10);
			for (int j = i + 1; j <= n - 10; j++) {
				string temp2 = s.substr(j, 10);
				if (temp1 == temp2) {
					res.push_back(temp1);
					break;
				}
			}
		}
		return res;
	}
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> map;
		vector<string> res;
		int n = s.size();
		for (int i = 0; i <= n - 10; i++) {
			string temp = s.substr(i, 10);
			map[temp]++;
		}
		for (auto e : map)
			if (e.second > 1)
				res.push_back(e.first);
		return res;
	}
};