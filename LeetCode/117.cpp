//Populating Next Right Pointers in Each Node II

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
        queue<TreeLinkNode*> qnode;
        queue<int> qlevel;
        qnode.push(root);
        qlevel.push(0);
        while (!qnode.empty()) {
            TreeLinkNode *node = qnode.front();
            qnode.pop();
            int level = qlevel.front();
            qlevel.pop();
            if (qlevel.empty() || level != qlevel.front())
                node->next = NULL;
            else
                node->next = qnode.front();
            if (node->left) {
                qnode.push(node->left);
                qlevel.push(level + 1);
            }
            if (node->right) {
                qnode.push(node->right);
                qlevel.push(level + 1);
            }
        }
    }
};