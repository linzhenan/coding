//Word Ladder

class Solution {
public:
	int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordList) {
		if (beginWord == endWord)
			return 1;
		vector<string> str;
		str.push_back(beginWord);
		for (auto s : wordList)
			str.push_back(s);
		str.push_back(endWord);
		int n = str.size();
		int m = beginWord.size();
		vector<vector<bool>> graph = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				string curr = str[i];
				string cand = str[j];
				int diff = 0;
				for (int k = 0; k < m; k++)
					if (curr[k] != cand[k]) {
						diff++;
						if (diff > 1)
							break;
					}
				if (diff == 1) {
					graph[i][j] = graph[j][i] = true;
				}
			}
		vector<bool> visit = vector<bool>(n, false);
		queue<int> qindex;
		qindex.push(0);
		queue<int> qlevel;
		qlevel.push(1);
		visit[0] = true;
		while (!qindex.empty()) {
			int index = qindex.front();
			qindex.pop();
			int level = qlevel.front();
			qlevel.pop();
			if (str[index] == endWord)
				return level;
			for (int j = 0; j < n; j++)
				if (!visit[j] && graph[index][j]) {
					visit[j] = true;
					qindex.push(j);
					qlevel.push(level + 1);
				}
		}
		return 0;
	}
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if (beginWord == endWord)
			return 1;

		wordList.insert(endWord);
		unordered_map<string, bool> visit;
		for (auto e : wordList)
			visit[e] = false;

		queue<string> qwords;
		queue<int> qlevel;
		qwords.push(beginWord);
		qlevel.push(1);

		while (!qwords.empty()) {
			string word = qwords.front();
			qwords.pop();
			int level = qlevel.front();
			qlevel.pop();

			string copy = word;
			for (int i = 0; i < word.size(); i++) {
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (word[i] != ch) {
						word[i] = ch;
						if (visit.find(word) != visit.end() && !visit[word]) {
							if (word == endWord)
								return level + 1;
							visit[word] = true;
							qwords.push(word);
							qlevel.push(level + 1);
						}
						word = copy;
					}
				}
			}
		}
		return 0;
	}
};