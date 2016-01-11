/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<TreeLinkNode *> q;
        queue<int> qlevel;
        q.push(root);
        qlevel.push(0);
        while (!q.empty()) {
            TreeLinkNode *node = q.pop();
            int level = qlevel.pop();
            if (node->left) {
                q.push(node->left);
                q.push(node->right);
                qlevel.push(level + 1);
                qlevel.push(level + 1);
            }
            if (qlevel.empty() || level != qlevel.front())
                node->next = NULL;
            else
                node->next = q.front();
        }
    }
};