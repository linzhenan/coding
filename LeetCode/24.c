/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p0, *p1, *p2;
    p1 = head;
    if (head)
        p2 = head->next;
    else
        p2 = NULL;
    if (!p1 || !p2)
        return head;
    //p1(head) -> p2 -> ...
    head = p2;
    p1->next = p2->next;
    p2->next = p1;
    //p2(head) -> p1 -> ...
    if (p1->next && p1->next->next) {
        p0 = p1;
        p1 = p0->next;
        p2 = p1->next;
    }
    else {
        return head;
    }
    //... -> p0 -> p1 -> p2 -> ...
    while (1) {
        //swap p1 and p2
        p1->next = p2->next;
        p2->next = p1;
        p0->next = p2;
        //... -> p0 -> p2 -> p1 -> ...
        if (p1->next && p1->next->next) {
            p0 = p1;
            p1 = p0->next;
            p2 = p1->next;
            //... -> p0 -> p1 -> p2 -> ...
        }
        else {
            return head;
        }
    }
    
}