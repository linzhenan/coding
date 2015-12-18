/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoSortedList(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = { 0 };
    struct ListNode *p = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy.next;
}
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow;
    slow = slow->next;
    fast->next = NULL;
    struct ListNode *l1 = sortList(head);
    struct ListNode *l2 = sortList(slow);
    return mergeTwoSortedList(l1, l2);
}