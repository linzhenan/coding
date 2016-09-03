#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
	long long left, right, cover;
	Node *leftChild, *rightChild;
	Node() {
		left = right = cover = 0;
		leftChild = rightChild = NULL;
	}
	Node(long long left, long long right) {
		this->left = left;
		this->right = right;
		this->cover = 1;
		leftChild = rightChild = NULL;
	}
	Node(long long left, long long right, long long cover) {
		this->left = left;
		this->right = right;
		this->cover = cover;
		leftChild = rightChild = NULL;
	}
};

Node *insert(Node *root, long long left, long long right) {
	if (right < left)
		return root;
	if (!root) {
		root = new Node(left, right);
		return root;
	}
	if (right < root->left)
		root->leftChild = insert(root->leftChild, left, right);
	else if (left > root->right)
		root->rightChild = insert(root->rightChild, left, right);
	else if (root->left == left && right == root->right)
		root->cover++;
	else {
		long long cleft = max(left, root->left);
		long long cright = min(right, root->right);
		if (cleft > root->left) {
			Node *node = new Node(root->left, cleft - 1, root->cover);
			node->leftChild = root->leftChild;
			root->leftChild = node;
			root->left = cleft;
		}
		if (cright < root->right) {
			Node *node = new Node(cright + 1, root->right, root->cover);
			node->rightChild = root->rightChild;
			root->rightChild = node;
			root->right = cright;
		}
		root->cover++;
		root->leftChild = insert(root->leftChild, left, cleft - 1);
		root->rightChild = insert(root->rightChild, cright + 1, right);
	}
	return root;
}
Node *free(Node *node) {
	if (node) {
		node->leftChild = free(node->leftChild);
		node->rightChild = free(node->rightChild);
		delete node;
		return NULL;
	}
	return NULL;
}
long long coveredarea(Node * node) {
	long long area = 0;
	if (!node)
		return 0;
	area += node->right - node->left + 1;
	area += coveredarea(node->leftChild);
	area += coveredarea(node->rightChild);
	return area;
}
long long removearea(Node* node, long long left, long long right) {
	if (!node)
		return 0;
	if (right < left)
		return 0;
	long long area = 0;
	if (left <= node->left && node->right <= right && node->cover == 1)
		area += node->right - node->left + 1;
	area += removearea(node->leftChild, left, node->left - 1);
	area += removearea(node->rightChild, node->right + 1, right);
	return area;
}

int main() {
	long long T;
	scanf("%lld", &T);
	for (long long t = 1; t <= T; t++) {
		long long N, L1, R1, A, B, C1, C2, M;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
		long long x = L1;
		long long y = R1;
		long long left = min(x, y);
		long long right = max(x, y);
		Node *root = new Node(left, right);
		for (long long i = 2; i <= N; i++) {
			long long xlast = x;
			long long ylast = y;
			x = (A * xlast + B * ylast + C1) % M;
			y = (A * ylast + B * xlast + C2) % M;
			left = min(x, y);
			right = max(x, y);
			root = insert(root, left, right);
			xlast = x;
			ylast = y;
		}
		long long area = coveredarea(root);
		x = L1;
		y = R1;
		left = min(x, y);
		right = max(x, y);
		long long maxremove = removearea(root, left, right);
		for (long long i = 2; i <= N; i++) {
			long long xlast = x;
			long long ylast = y;
			x = (A * xlast + B * ylast + C1) % M;
			y = (A * ylast + B * xlast + C2) % M;
			left = min(x, y);
			right = max(x, y);
			long long curremove = removearea(root, left, right);
			if (curremove > maxremove)
				maxremove = curremove;
		}
		printf("Case #%lld: %lld\n", t, area - maxremove);
		free(root);
	}
	return 0;
}