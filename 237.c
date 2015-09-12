#include <malloc.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    struct ListNode *curr_node = node;
    struct ListNode *next_node = node->next;
    curr_node->val = next_node->val;
    curr_node->next = next_node->next;
    free(next_node);
}

