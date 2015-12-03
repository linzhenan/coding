/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (!head)
        return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next= head;
    
    struct ListNode *prev = head;
    struct ListNode *curr = head->next;
    while (curr) {
        prev->next = curr->next;
        curr->next = dummy->next;
        dummy->next = curr;
        curr = prev->next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}