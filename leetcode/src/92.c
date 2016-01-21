/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head)
        return head;
    if (m == n)
        return head;
        
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode *prev = head;
    struct ListNode *curr = head->next;
    head = dummy;
    for (int i = 0; i < m - 1; i++) {
        head = head->next;
        prev = prev->next;
        curr = curr->next;
    }
    for (int i = 0; i < n - m; i++) {
        prev->next = curr->next;
        curr->next = head->next;
        head->next = curr;
        curr = prev->next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}