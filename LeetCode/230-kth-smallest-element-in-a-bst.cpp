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
    void kthLDR(TreeNode* root, int k, int &num, bool &find, int &idx) {
        if (!root)
            return;
        if (!find) {
            kthLDR(root->left, k, num, find, idx);
            if (!find) {
                idx++;
                if (idx == k) {
                    num = root->val;
                    find = true;
                }
            }
            if (!find)
                kthLDR(root->right, k, num, find, idx);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int num;
        bool find = false;
        int idx = 0;
        kthLDR(root, k, num, find, idx);
        return num;
    }
};