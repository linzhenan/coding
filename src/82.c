//Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;
    while (curr && curr->next) {
        struct ListNode *fast = curr->next;
        if (fast->val == curr->val) {
            while (fast->next && fast->next->val == curr->val)
                fast = fast->next;
            prev->next = fast->next;
            curr = prev->next;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return dummy.next;
}