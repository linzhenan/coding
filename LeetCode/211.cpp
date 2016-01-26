//Add and Search Word - Data structure design

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

class WordDictionary {
private:
	TrieNode *root;
public:
	WordDictionary() {
		root = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			int idx = word[i] - 'a';
			if (!node->next[idx])
				node->next[idx] = new TrieNode();
			node = node->next[idx];
		}
		node->isWordEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word, TrieNode *root) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != '.') {
				int idx = word[i] - 'a';
				if (!node->next[idx])
					return false;
				else
					node = node->next[idx];
			}
			else {
				for (int idx = 0; idx < 26; idx++)
					if (node->next[idx] && search(word.substr(i + 1), node->next[idx]))
						return true;
				return false;
			}
		}
		if (node->isWordEnd)
			return true;
		else
			return false;
	}
	bool search(string word) {
		return search(word, root);
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");