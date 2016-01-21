//Maximum Product of Word Lengths

class Solution {
public:
	int maxProduct1(vector<string>& words) {
		if (words.size() < 2)
			return 0;
		int p = 0;
		for (int i = 0; i < words.size() - 1; i++) {
			int hash[26] = { 0 };
			for (int k = 0; k < words[i].size(); k++)
				hash[words[i][k] - 'a'] = 1;
			for (int j = i + 1; j < words.size(); j++) {
				int currp = words[i].size() * words[j].size();
				if (currp < p)
					continue;
				int k;
				for (k = 0; k < words[j].size(); k++)
					if (hash[words[j][k] - 'a'])
						break;
				if (k == words[j].size())
					p = max(p, currp);
			}
		}
		return p;
	}
	int maxProduct2(vector<string>& words) {
		if (words.size() < 2)
			return 0;
		int p = 0;
		vector<unordered_map<char, bool>> hash;
		for (int i = 0; i < words.size(); i++) {
			unordered_map<char, bool> map;
			for (int k = 0; k < words[i].size(); k++)
				map[words[i][k]] = true;
			hash.push_back(map);
		}
		for (int i = 0; i < words.size() - 1; i++)
			for (int j = i + 1; j < words.size(); j++) {
				int currp = words[i].size() * words[j].size();
				if (currp <= p)
					continue;
				for (char ch = 'a'; ch <= 'z'; ch++)
					if (hash[i][ch] && hash[j][ch]) {
						currp = 0;
						break;
					}
				p = max(p, currp);
			}

		return p;
	}
	int maxProduct(vector<string>& words) {
		return maxProduct2(words);
	}
};