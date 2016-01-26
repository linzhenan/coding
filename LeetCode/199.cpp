//Binary Tree Right Side View

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
    void dfs(TreeNode* root, vector<int>& res, int level) {
        if (root) {
            if (level < res.size()) {
                res[level] = root->val;
            }
            else {
                res.push_back(root->val);
            }
            dfs(root->left, res, level + 1);
            dfs(root->right, res, level + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};