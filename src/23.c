//Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;
    struct ListNode *p1, *p2, *head, *p;
    p1 = l1;
    p2 = l2;
    if (p1->val < p2->val) {
        head = p1;
        p1 = p1->next;
    }
    else {
        head = p2;
        p2 = p2->next;
    }
    p = head;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        else {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
    }
    if (p1)
        p->next = p1;
    else if (p2)
        p->next = p2;
    else
        p->next = NULL;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    struct ListNode *list = mergeTwoLists(lists[0], lists[1]);
    for (int i = 2; i < listsSize; i++)
        list = mergeTwoLists(list, lists[i]);
    return list;
}