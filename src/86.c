//Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (!head)
        return head;
    struct ListNode lt_dummy = { 0 };
    struct ListNode ge_dummy = { 0 };
    struct ListNode *p = head;
    struct ListNode *lt = &lt_dummy;
    struct ListNode *ge = &ge_dummy;
    while (p) {
        if (p->val < x) {
            lt->next = p;
            lt = lt->next;
        }
        else {
            ge->next = p;
            ge = ge->next;
        }
        p = p->next;
    }
    lt->next = ge_dummy.next;
    ge->next = NULL;
    return lt_dummy.next;
}