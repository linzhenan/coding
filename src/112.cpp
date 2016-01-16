//Path Sum

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
    bool hasPathSum(TreeNode* root, int sum, int pathSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            if (sum == pathSum + root->val)
                return true;
        if (root->left && hasPathSum(root->left, sum, pathSum + root->val))
            return true;
        if (root->right && hasPathSum(root->right, sum, pathSum + root->val))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum(root, sum, 0);
    }
};