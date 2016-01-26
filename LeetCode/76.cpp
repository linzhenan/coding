//Minimum Window Substring

class Solution {
public:
	string minWindow(string s, string t) {
		if (!s.size() || !t.size() || s.size() < t.size())
			return "";
		const int ASCII_MAX = 256;
		int appeared_count[ASCII_MAX] = { 0 };
		int expected_count[ASCII_MAX] = { 0 };
		for (int i = 0; i < t.size(); i++)
			expected_count[t[i]]++;
		int appeared = 0;
		int w_start = 0;

		int min_width = INT_MAX;
		int min_start = 0;
		for (int w_end = 0; w_end < s.size(); w_end++) {
			if (expected_count[s[w_end]]) {
				appeared_count[s[w_end]]++;
				if (appeared_count[s[w_end]] <= expected_count[s[w_end]])
					appeared++;
			}
			if (appeared == t.size()) {
				while (appeared_count[s[w_start]] > expected_count[s[w_start]] ||
					expected_count[s[w_start]] == 0) {
					appeared_count[s[w_start]]--;
					w_start++;
				}
				if (w_end - w_start + 1 < min_width) {
					min_width = w_end - w_start + 1;
					min_start = w_start;
				}
			}
		}
		if (min_width == INT_MAX)
			return "";
		else
			return s.substr(min_start, min_width);
	}
};