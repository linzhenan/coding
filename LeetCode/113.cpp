//Path Sum II

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
    void pathSum(TreeNode* root, vector<vector<int>>& res, vector<int>&path, int sum, int currSum) {
        if (!root)
            return;
        path.push_back(root->val);
        currSum += root->val;
        if (!root->left && !root->right)
            if (sum == currSum)
                res.push_back(path);
        if (root->left)
            pathSum(root->left, res, path, sum, currSum);
        if (root->right)
            pathSum(root->right, res, path, sum, currSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        pathSum(root, res, path, sum, 0);
        return res;
    }
};