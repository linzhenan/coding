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
    int dfs(TreeNode* root, string& num) {
        if (!root)
            return 0;
            
        if (!root->left && !root->right) {
            num.push_back('0' + root->val);
            int val = atoi(num.c_str());
            num.pop_back();
            return val;
        }
        else {
            num.push_back('0' + root->val);
            int l = dfs(root->left, num);
            int r = dfs(root->right, num);
            num.pop_back();
            return l + r;
        }
    }
    int sumNumbers(TreeNode* root) {
        string num = "";
        return dfs(root, num);
    }
};