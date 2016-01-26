class TrieNode {
public:
	bool isWordEnd;
	TrieNode *next[26];
	TrieNode() {
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
		isWordEnd = false;
	}
};
class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}
	void add(string word) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			int idx = word[i] - 'a';
			if (!node->next[idx])
				node->next[idx] = new TrieNode();
			node = node->next[idx];
		}
		node->isWordEnd = true;
	}
	bool startWith(string prefix) {
		TrieNode *node = root;
		for (int i = 0; i < prefix.size(); i++) {
			int idx = prefix[i] - 'a';
			if (!node->next[idx])
				return false;
			node = node->next[idx];
		}
		return true;
	}
	//0: not exist
	//1: start with
	//2: exist
	int search(string word) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			int idx = word[i] - 'a';
			if (!node->next[idx])
				return 0;
			node = node->next[idx];
		}
		if (node->isWordEnd)
			return 2;
		else
			return 1;
	}
};
class Solution {
private:
	int w;
	int h;
	unordered_map<string, bool> map;
public:
	void dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, Trie& trie, string& str, int x, int y) {
		if (0 <= x && x < w && 0 <= y && y < h && !visit[y][x]) {
			visit[y][x] = true;
			str += board[y][x];
			int ret = trie.search(str);
			if (ret) {
				if (ret == 2)
					map[str] = true;
				dfs(board, visit, trie, str, x + 1, y);
				dfs(board, visit, trie, str, x - 1, y);
				dfs(board, visit, trie, str, x, y + 1);
				dfs(board, visit, trie, str, x, y - 1);
			}
			str = str.substr(0, str.size() - 1);
			visit[y][x] = false;
		}
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		h = board.size();
		if (h == 0)
			return res;
		w = board[0].size();
		if (w == 0)
			return res;

		Trie trie;
		for (int i = 0; i < words.size(); i++)
			trie.add(words[i]);

		vector<vector<bool>> visit = vector<vector<bool>>(h, vector<bool>(w, false));
		string str = "";

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				dfs(board, visit, trie, str, x, y);

		for (auto e : map)
			res.push_back(e.first);
		sort(res.begin(), res.end());

		return res;
	}
};