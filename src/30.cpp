//Substring with Concatenation of All Words

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (!s.size() || !words.size())
			return res;
		int slen = s.size();
		int wlen = words[0].size();

		unordered_map<string, int> expect;
		for (int i = 0; i < words.size(); i++)
			expect[words[i]]++;

		int wnd_width = words.size() * words[0].size();
		for (int offset = 0; offset < wlen; offset++) {
			for (int wnd_start = offset; wnd_start + wnd_width <= slen; wnd_start += wlen) {
				unordered_map<string, int> appear;
				int appear_count = 0;
				for (int pos = wnd_start; pos < wnd_start + wnd_width; pos += wlen) {
					string sub = s.substr(pos, wlen);
					if (expect.find(sub) == expect.end()) {
						break;
					}
					else if (appear[sub] < expect[sub]) {
						appear[sub]++;
						appear_count++;
						if (appear_count == words.size()) {
							res.push_back(wnd_start);
							break;
						}
					}
					else {
						break;
					}
				}
			}
		}
		return res;
	}
};