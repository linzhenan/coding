/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *left, *right;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
        {
            return root;
        }
        else if (left == NULL && right == NULL)
        {
            if (root == p || root == q)
                return root;
            else
                return NULL;
        }
        else
        {
            if (root == p || root == q)
            {
                return root;
            }
            else
            {
                if (left != NULL)
                    return left;
                else
                    return right;
            }
        }
    }
}