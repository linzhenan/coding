//http://www.geeksforgeeks.org/interval-tree/

#include <stdlib.h>
#include <stdio.h>

struct Interval {
	int low;
	int high;
};
struct ITNode {
	Interval *i;
	int maxval;
	ITNode *left, *right;
	ITNode (Interval i) {
		this->i = new Interval(i);
		this->maxval = i.high;
		this->left = NULL;
		this->right = NULL;
	}
};
ITNode *insert(ITNode *root, Interval& i) {
	if (!root) {
		root = new ITNode(i);
		return root;
	}

	if (i.low < root->i->low)
		root->left = insert(root->left, i);
	else
		root->right = insert(root->right, i);

	if (root->maxval < i.high)
		root->maxval = i.high;

	return root;
}
bool isOverlap(Interval& i1, Interval& i2) {
	//i2    --------------
	//i1 -----------

	//i2 ----------
	//i1    --------------

	//i2   -----
	//i1 -----------

	//i2 -----------------
	//i1   ---------
	if (i2.low <= i1.high && i2.high >= i1.low)
		return true;
	else
		return false;
}
Interval* overlapSearch(ITNode *root, Interval& i) {
	if (!root)
		return NULL;
	if (isOverlap(*root->i, i))
		return root->i;
	if (root->left && i.low <= root->left->maxval)
		return overlapSearch(root->left, i);
	return overlapSearch(root->right, i);
}
void main() {
#define COUNT 6
	Interval ints[COUNT] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}};
	ITNode *root = NULL;
	for (int i = 0; i < COUNT; i++)
		root = insert(root, ints[i]);
	Interval x = {60, 120};
	Interval *res = overlapSearch(root, x);
	if (res) {
		printf("Found {%d, %d}.\n", res->low, res->high);
	}
	else {
		printf("No found.\n");
	}
}