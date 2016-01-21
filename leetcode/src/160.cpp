//Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA->next) {
            pA = pA->next;
            lenA++;
        }
        while (pB->next) {
            pB = pB->next;
            lenB++;
        }
        if (pA != pB)
            return NULL;
        pA = headA;
        pB = headB;
        if (lenA > lenB)
            for (int i = 0; i < lenA - lenB; i++)
                pA = pA->next;
        else if (lenB > lenA)
            for (int i = 0; i < lenB - lenA; i++)
                pB = pB->next;
        while (pA) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
    }
};