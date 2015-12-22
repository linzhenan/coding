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
    void recursiveTraversal(struct TreeNode *root, vector<int> &result) {
        if (root) {
            result.push_back(root->val);
            recursiveTraversal(root->left, result);
            recursiveTraversal(root->right, result);
        }
    }
    void stackTraversal(struct TreeNode *root, vector<int> &result) {
        struct TreeNode *p;
        stack<struct TreeNode *> s;
        
        p = root;
        if (p)
            s.push(p);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
        }
    }
    vector<int> preorderTraversal(struct TreeNode* root) {
        vector<int> result;
        //recursiveTraversal(root, result);
        stackTraversal(root, result);
        return result;
    }
};