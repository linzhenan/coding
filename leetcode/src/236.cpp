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
    vector<TreeNode *> path0;
    vector<TreeNode *> path;
    TreeNode *LCA;
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || LCA)
            return;
        path.push_back(root);
        if (root == p || root == q) {
            if (path0.size() == 0) {
                path0 = vector<TreeNode *>(path);
            }
            else {
                for (int i = 0; i < path.size(); i++)
                    if (path[i] != path0[i]) {
                        LCA = path[i - 1];
                        break;
                    }
            }
        }
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA = NULL;
        dfs(root, p, q);
        return LCA;
    }
};