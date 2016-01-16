//Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildSubTree(vector<int>& postorder, int& idx,
                            vector<int>& inorder, vector<int>::iterator start, vector<int>::iterator end) {
        if (idx < 0 || start >= end)
            return NULL;
        int rootpos = idx--;
        TreeNode *root = new TreeNode(postorder[rootpos]);
        root->right = buildSubTree(postorder, idx,
                                    inorder, find(start, end, postorder[rootpos]) + 1, end);
        root->left = buildSubTree(postorder, idx,
                                    inorder, start, find(start, end, postorder[rootpos]));
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return buildSubTree(postorder, idx,
                            inorder, inorder.begin(), inorder.end());
    }
};