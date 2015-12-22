/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool travese(struct TreeNode *leftT, struct TreeNode *rightT) {
    if (!leftT && !rightT)
        return true;
    if (!leftT)
        return false;
    if (!rightT)
        return false;
    if (leftT->val != rightT->val)
        return false;
    return travese(leftT->left, rightT->right) && travese(leftT->right, rightT->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return travese(root->left, root->right);
}