//Binary Tree Zigzag Level Order Traversal

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
    void dfs(TreeNode *root, vector<vector<int>>& res, int level) {
        if (!root)
            return;
        if (level > res.size())
            res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 1);
        return res;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res = levelOrder(root);
        for (int i = 0; i < res.size(); i++)
            if (i & 0x01)
                reverse(res[i].begin(), res[i].end());
        return res;
    }
};