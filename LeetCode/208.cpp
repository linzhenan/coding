//Implement Trie (Prefix Tree)

class TrieNode {
public:
	// Initialize your data structure here.
	bool isWordEnd;
	TrieNode *next[26];
	TrieNode() {
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
		isWordEnd = false;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			int idx = word[i] - 'a';
			if (node->next[idx]) {
				node = node->next[idx];
			}
			else {
				node->next[idx] = new TrieNode();
				node = node->next[idx];
			}
		}
		node->isWordEnd = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *node = root;
		for (int i = 0; i < word.size(); i++) {
			int idx = word[i] - 'a';
			if (!node->next[idx])
				return false;
			else
				node = node->next[idx];
		}
		if (node->isWordEnd)
			return true;
		else
			return false;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *node = root;
		for (int i = 0; i < prefix.size(); i++) {
			int idx = prefix[i] - 'a';
			if (!node->next[idx])
				return false;
			else
				node = node->next[idx];
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");