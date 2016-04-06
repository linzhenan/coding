#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

#pragma warning(disable:4996)

#ifdef DEBUG
#undef DEBUG
#endif
using namespace std;

struct Trie {
	int *state;
	int *id;
	int count;
	struct Trie *next[2];
};

void printf_ip_mask(unsigned int ip, int mask, int state) {
	if (state == -1)
		printf("deny  ");
	else if (state == 1)
		printf("allow ");
	else
		printf("access");
	int show = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 8; k++) {
			unsigned int bit = 1 << (8 * (3 - j) + (7 - k));
			if (show == mask) {
				printf(" ");
			}
			else {
				printf("%d", (ip & bit) ? 1 : 0);
				show++;
			}
		}
		printf(" ");
	}
	printf("%d\n", mask);
}
Trie* insert(Trie *root, unsigned int ip, int bit, int state, int id) {
	if (!root) {
		root = (Trie*)malloc(sizeof(Trie));
		root->state = NULL;
		root->id = NULL;
		root->count = 0;
		root->next[0] = NULL;
		root->next[1] = NULL;
	}
	if (bit == 0) {
		root->count++;
		root->state = (int*)realloc(root->state, root->count);
		root->id = (int*)realloc(root->id, root->count);
		root->state[root->count - 1] = state;
		root->id[root->count - 1] = id;
		return root;
	}
	unsigned int bitval = ip & 0x80000000;
	if (bitval)
		root->next[1] = insert(root->next[1], ip << 1, bit - 1, state, id);
	else
		root->next[0] = insert(root->next[0], ip << 1, bit - 1, state, id);

	return root;
}
Trie *search(Trie *root, unsigned int ip, int bit) {
	if (!root)
		return NULL;

	Trie *child;
	int bitval = ip & 0x80000000;
	if (bitval)
		child = search(root->next[1], ip << 1, bit - 1);
	else
		child = search(root->next[0], ip << 1, bit - 1);

	if (root->count == 0)
		return child;
	if (!child || child->count == 0)
		return root;
	if (root->id[0] < child->id[0])
		return root;
	else
		return child;
}
int get_state(string str) {
	if (str == "allow")
		return 1;
	else
		return -1;
}
unsigned int get_ip(string str) {
	int n = str.size();
	unsigned int num = 0;
	unsigned int ip = 0;
	int seg = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '/')
			break;
		if (str[i] == '.' || i == n - 1) {
			ip |= num << (8 * (3 - seg));
			num = 0;
			seg++;
		}
		else {
			num = num * 10 + str[i] - '0';
		}
	}
	return ip;
}
int get_mask(string str) {
	int n = str.size();
	bool findMask = false;
	int mask = 0;
	for (int i = 0; i < n; i++) {
		if (findMask)
			mask = mask * 10 + str[i] - '0';
		if (str[i] == '/')
			findMask = true;
	}
	if (findMask)
		return mask;
	else
		return 32;
}
int main() {
	int N, M;
	cin >> N >> M;
	Trie *root = NULL;

	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		int state = get_state(str1);
		unsigned int ip = get_ip(str2);
		int mask = get_mask(str2);
#ifdef DEBUG
		printf_ip_mask(ip, mask, state);
#endif
		root = insert(root, ip, mask, state, i);
	}
#ifdef DEBUG
	printf("\n");
#endif
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		unsigned int ip = get_ip(str);
#ifdef DEBUG
		printf_ip_mask(ip, 32, 0);
#endif
		Trie *node = search(root, ip, 32);
		if (!node || node->count == 0 || node->state[0] == 1)
			cout << "YES" << endl;
		else if (node->state[0] == -1)
			cout << "NO" << endl;
	}

	return 0;
}