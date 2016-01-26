/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *tmp;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
}