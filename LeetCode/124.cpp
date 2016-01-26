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
    int maxSum;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if (l > 0)
            sum += l;
        if (r > 0)
            sum += r;
        maxSum = max(maxSum, sum);
        return max(l, r) > 0 ? root->val + max(l, r) : root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        int sum = dfs(root);
        //maxSum = max(maxSum, sum);
        return maxSum;
    }
};