//Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int balancedDepth(TreeNode *root) {
        if (!root)
            return 0;
        int left = balancedDepth(root->left);
        if (left == -1)
            return -1;
        int right = balancedDepth(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        else
            return left > right ? left + 1 : right + 1;
    }
    bool isBalanced(TreeNode* root) {
        int depth = balancedDepth(root);
        if (depth == -1)
            return false;
        else
            return true;
    }
};