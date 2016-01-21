//Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode dummy1 = ListNode(0);
        ListNode dummy2 = ListNode(0);
        dummy1.next = head;
        dummy2.next = head->next;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2) {
            p1->next = p2->next;
            if (p1->next)
                p2->next = p1->next->next;
            else
                p2->next = NULL;
            if (p1->next)
                p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = dummy2.next;
        return dummy1.next;
    }
};