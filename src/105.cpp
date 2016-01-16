//Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode *buildSubTree(vector<int>& preorder, int& idx,
                            vector<int>& inorder, vector<int>::iterator start, vector<int>::iterator end) {
        if (idx == preorder.size() || start >= end)                            
            return NULL;
        int rootpos = idx++;
        TreeNode* root = new TreeNode(preorder[rootpos]);
        root->left = buildSubTree(preorder, idx,
                                    inorder, start, find(start, end, preorder[rootpos]));
        root->right = buildSubTree(preorder, idx,
                                    inorder, find(start, end, preorder[rootpos]) + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return buildSubTree(preorder, idx, inorder, inorder.begin(), inorder.end());
    }
};