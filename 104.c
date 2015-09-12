/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int leftMaxDepth, rightMaxDepth;
    if (root)
    {
        leftMaxDepth = maxDepth(root->left);
        rightMaxDepth = maxDepth(root->right);
        if (leftMaxDepth > rightMaxDepth)
            return leftMaxDepth + 1;
        else
            return rightMaxDepth + 1;
    }
    else
    {
        return 0;
    }
}