/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head)
        return head;
    struct ListNode* pFast, *pSlow, *pLast;
    pFast = head;
    pSlow = head;
    int distance = 0;
    while (pFast) {
        distance++;
        pFast = pFast->next;
        if (distance == n)
            break;
    }
    while (pFast) {
        pFast = pFast->next;
        pLast = pSlow;
        pSlow = pSlow->next;
    }
    //what result should be returned in the case : [1, 2, 3, 4, 5] 6 ?
    //if (distance == n) {
        if (pSlow == head)
            head = head->next;
        else
            pLast->next = pSlow->next;
    //}
    
    //what result should be returned in the case : [] 0 ? 
    return head;
}