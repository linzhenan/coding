//Flatten Binary Tree to Linked List

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
    TreeNode* flattenHelp(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode *leftTail, *rightTail;
        if (root->left)
            leftTail = flattenHelp(root->left);
        if (root->right)
            rightTail = flattenHelp(root->right);
        if (root->left && root->right) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return rightTail;
        }
        else if (root->left) {
            root->right = root->left;
            root->left = NULL;
            return leftTail;
        }
        else if (root->right) {
            return rightTail;
        }
        else {
            return root;
        }
    }
    void flatten(TreeNode* root) {
        flattenHelp(root);
    }
};