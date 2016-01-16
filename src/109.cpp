//Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int listLength(ListNode *head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* nthNode(ListNode *head, int n) {
        while (--n && head)
            head = head->next;
        return head;
    }
    TreeNode* buildSubTree(ListNode* head, int len) {
        if (len == 0)
            return NULL;
        if (len == 1)
            return new TreeNode(head->val);
        TreeNode* root = new TreeNode(nthNode(head, len / 2 + 1)->val);
        root->left = buildSubTree(head, len / 2);
        root->right = buildSubTree(nthNode(head, len / 2 + 2), len - len / 2 - 1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildSubTree(head, listLength(head));
    }
};