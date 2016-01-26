//Binary Search Tree Iterator

#include <stack>
#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
private:
    stack<TreeNode *> stk;
public:

    BSTIterator(TreeNode *root) {
        /*
        if (root) {
            stk.push(root);
            root = root->left;
            BSTIterator(root->left);//Constructor cannot call itself for recursive!
        }
        */
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stk.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        /*
        TreeNode *node = stk.top();
        stk.pop();
        BSTIterator(node->right);//Constructor cannot call itself for recursive!
        return node->val;
        */
        TreeNode *node = stk.top();
        stk.pop();
        int ret = node->val;
        node = node->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

void main() {
	TreeNode *node1 = new TreeNode(5);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(9);
	node1->left = node2;
	node1->right = node3;
	BSTIterator i = BSTIterator(node1);
	while (i.hasNext()) cout << i.next();
}