/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* findPrevPos(struct ListNode *head, int val) {
    struct ListNode *prev = NULL;
    for (struct ListNode *curr = head; curr && curr->val <= val; prev = curr, curr = curr->next)
        ;
    return prev;
}
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy = { 0 };
    dummy.val = INT_MIN;
    dummy.next = NULL;
    struct ListNode *curr = head;
    while (curr) {
        struct ListNode *pos = findPrevPos(&dummy, curr->val);
        struct ListNode *tmp = curr->next;
        curr->next = pos->next;
        pos->next = curr;
        curr = tmp;
    }
    return dummy.next;
}