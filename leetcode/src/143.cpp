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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            prev = prev->next;
        }
        
        ListNode* head2 = prev->next;
        prev->next = NULL;
        
        dummy.next = head2;
        ListNode* curr2 = head2;
        while (curr2->next) {
            dummy.next = curr2->next;
            curr2->next = curr2->next->next;
            dummy.next->next = head2;
            head2 = dummy.next;
        }
        
        ListNode* curr = head;
        curr2 = head2;
        //L2 >= L1
        while (curr) {
            ListNode* prev = curr;
            ListNode* prev2 = curr2;
            curr = curr->next;
            curr2 = curr2->next;
            prev->next = prev2;
            if (curr)
                prev2->next = curr;
        }
    }
};