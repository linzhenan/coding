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
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        bool found = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                found = true;
                break;
            }
        }
        ListNode *slow2 = head;
        if (found) {
            while (slow != slow2) {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
        return NULL;
    }
};