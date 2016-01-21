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
    void dfs(TreeNode* root, vector<string>& res, vector<int>& path) {
        if (root)
            path.push_back(root->val);
        else
            return;
        if (!root->left && !root->right) {
            stringstream ss;
            ss << path[0];
            for (int i = 1; i < path.size(); i++) {
                ss << "->";
                ss << path[i];
            }
            res.push_back(ss.str());
        }
        else {
            dfs(root->left, res, path);
            dfs(root->right, res, path);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        dfs(root, res, path);
        return res;
    }
};