#include <stdio.h>
#include <malloc.h>
#include <string.h>

#pragma warning(disable:4996)

struct Trie {
	int id;
	int rule;
	struct Trie *next[2];
};
Trie* insert(Trie *root, unsigned int ip, int mask, int rule, int id) {
	if (!root) {
		root = (Trie*)malloc(sizeof(Trie));
		root->rule = 0;
		root->id = 0;
		root->next[0] = NULL;
		root->next[1] = NULL;
	}
	if (mask == 0) {
		if (!root->rule) {
			root->rule = rule;
			root->id = id;
		}
		return root;
	}
	unsigned int bitval = ip & 0x80000000;
	if (bitval)
		root->next[1] = insert(root->next[1], ip << 1, mask - 1, rule, id);
	else
		root->next[0] = insert(root->next[0], ip << 1, mask - 1, rule, id);

	return root;
}
Trie *search(Trie *root, unsigned int ip, int mask) {
	if (!root)
		return NULL;

	Trie *child;
	int bitval = ip & 0x80000000;
	if (bitval)
		child = search(root->next[1], ip << 1, mask - 1);
	else
		child = search(root->next[0], ip << 1, mask - 1);

	if (!child)
		return root;
	if (root->rule && child->rule) {
		if (root->id < child->id)
			return root;
		else
			return child;
	}
	else if (root->rule)
		return root;
	else if (child->rule)
		return child;
	else
		return root;
}
int contain_sprit(char *s) {
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == '/')
			return 1;
	return 0;
}
int main() {
	int N, M;
	char line[100];
	scanf("%d%d", &N, &M); fgets(line, 100, stdin);
	Trie *root = NULL;
	char rule[6];
	int a[4];
	unsigned int ip;
	int mask;
	for (int i = 0; i < N; i++) {
		fgets(line, 100, stdin);
		if (contain_sprit(line)) {
			sscanf(line, "%s%d.%d.%d.%d/%d", rule, &a[0], &a[1], &a[2], &a[3], &mask);
		}
		else {
			sscanf(line, "%s%d.%d.%d.%d", rule, &a[0], &a[1], &a[2], &a[3]);
			mask = 32;
		}
		ip = (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
		if (rule[0] == 'a')
			root = insert(root, ip, mask, 1, i + 1);
		else
			root = insert(root, ip, mask, -1, i + 1);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		ip = (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
		Trie *node = search(root, ip, 32);
		if (!node || node->rule == 0 || node->rule == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}