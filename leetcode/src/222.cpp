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
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int count = 1;
        count += dfs(root->left);
        count += dfs(root->right);
        return count;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode *node;
        
        node = root;
        int left = 0;
        while (node) {
            node = node->left;
            left++;
        }
        
        node = root;
        int right = 0;
        while (node) {
            node = node->right;
            right++;
        }
        
        if (left == right)
            return (1 << left) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};