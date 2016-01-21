//Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        RandomListNode *p = head;
        RandomListNode dummy(0);
        RandomListNode *q = &dummy;
        unordered_map<RandomListNode *, vector<RandomListNode *>> map;
        while (p) {
            q->next = new RandomListNode(p->label);
            q = q->next;
            if (p->random)
                map[p->random].push_back(q);
            p = p->next;
        }
        p = head;
        q = dummy.next;
        while (p) {
            if (map.find(p) != map.end()) {
                for (auto& e : map[p])
                    e->random = q;
            }
            p = p->next;
            q = q->next;
        }
        return dummy.next;
    }
};