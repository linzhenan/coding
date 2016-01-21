/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *buffer[k];
    int buffer_len = 0;
    struct ListNode *p = head;
    struct ListNode *head_new = NULL, *p_new;
    if (!head || k == 1)
        return head;
    while (p) {
        buffer[buffer_len++] = p;//push
        p = p->next;
        if (buffer_len == k) {
            if (!head_new) {
                head_new = buffer[--buffer_len];//pop
                p_new = head_new;
            }
            while (buffer_len) {
                p_new->next = buffer[--buffer_len];//pop
                p_new = p_new->next;
            }
        }
    }
    if (!head_new) {//num of nodes < k
        head_new = head;
    }
    else {
        if (buffer_len)//attach tailing nodes
            for (int i = 0; i < buffer_len; i++) {
                p_new->next = buffer[i];
                p_new = p_new->next;
            }
        p_new->next = NULL;
    }
    return head_new;
}