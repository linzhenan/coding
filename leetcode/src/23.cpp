//Merge k Sorted Lists

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
bool cmp(ListNode *a,ListNode *b) {
    if (a && b)
        return a->val > b->val;
    else if (a)
        return false;
    else
        return true;
}
ListNode *mergeKLists(vector<ListNode *> &lists) {
    int k = lists.size();
    if (k == 0)
        return NULL;
    vector<ListNode *> heap[k];
    for (int i = 0; i < k; i++)
        heap[i] = lists[i];
    ListNode dummy;
    ListNode* p = &dummy;
    make_heap(heap.begin(), heap.end(), cmp);
    while (true) {
        pop_heap(heap.begin(), heap.end(), cmp);
        p->next = heap[k - 1];
        p = p->next;
        if (!heap[k - 1])
            break;
        else {
            heap[k - 1] = heap[k - 1]->next;
            push_heap(heap.begin(), heap.end(), cmp);
        }
    }
    return dummy.next;
};