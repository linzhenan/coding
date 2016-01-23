//Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *curr = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};