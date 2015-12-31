//Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !k)
        return head;
    struct ListNode *p = head;
    int len = 1;
    while (p->next) {
        p = p->next;
        len++;
    }
    k = len - k % len;
    p->next = head;
    for (int i = 0; i < k; i++)
        p = p->next;
    head = p->next;
    p->next = NULL;
    return head;
}