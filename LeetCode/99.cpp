/**
 * Definition for a binary tree node.
 //Recover Binary Search Tree

 //Space O(1), Morris Traverse?
 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void LDR(TreeNode* root, vector<TreeNode *>& vec) {
        if (!root)
            return;
        LDR(root->left, vec);
        vec.push_back(root);
        LDR(root->right, vec);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> vec;
        LDR(root, vec);
        int i, j;
        for (i = 0; i < vec.size() - 1; i++)
            if (vec[i]->val >= vec[i + 1]->val)
                break;
        for (j = vec.size() - 1; j >= 1; j--)
            if (vec[j - 1]->val >= vec[j]->val)
                break;
        swap(vec[i]->val, vec[j]->val);
    }
};