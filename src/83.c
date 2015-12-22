/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head)
        return head;
    struct ListNode *curr = head;
    struct ListNode *next = head->next;
    while (next) {
        if (next->val == curr->val) {
            curr->next = next->next;
            free(next);
            next = curr->next;
        }
        else {
            curr = curr->next;
            next = next->next;
        }
    }
    return head;
}