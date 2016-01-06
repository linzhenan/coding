//Restore IP Addresses

class Solution {
public:
	void dfs(vector<string>& res, string& s, vector<string>& seg, int start) {
		if (seg.size() == 4 && start == s.size()) {
			for (int i = 0; i < 4; i++) {
				if (atoi(seg[i].c_str()) > 255)
					return;
			}
			res.push_back(seg[0] + "." + seg[1] + "." + seg[2] + "." + seg[3]);
		}
		else if (seg.size() < 4) {
			for (int len = 1; len <= 3; len++) {
				if (start + len <= s.size()) {
					string tmp = s.substr(start, len);
					if (tmp.size() == 2 && tmp[0] == '0' ||
						tmp.size() == 3 && tmp[0] == '0')
						continue;
					seg.push_back(tmp);
					dfs(res, s, seg, start + len);
					seg.pop_back();
				}
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> seg;
		vector<string> res;
		dfs(res, s, seg, 0);
		return res;
	}
};