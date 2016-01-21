/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int cflag = 0;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *p1_last = NULL;
    struct ListNode *p2_last = NULL;
    struct ListNode *tail = NULL;
    
    while (p1)
    {
        if (p2)
        {
            p1->val = p1->val + p2->val + cflag;
            if (p1->val > 9)
            {
                p1->val = p1->val % 10;
                cflag = 1;
            }
            else
            {
                cflag = 0;
            }
            p2_last = p2;
            p2 = p2->next;
        }
        else
        {
            p1->val = p1->val + cflag;
            if (p1->val > 9)
            {
                p1->val = p1->val % 10;
                cflag = 1;
            }
            else
            {
                cflag = 0;
                break;
            }
        }
        p1_last = p1;
        p1 = p1->next;
    }
    
    if (p2)//len2 > len1
    {
        //move tail of l2 to l2
        p1_last->next = p2;
        p2_last->next = NULL;
        p1 = p2;
    }
    
    while (cflag) 
    {
        if (p1)
        {
            p1->val = p1->val + cflag;
            if (p1->val > 9)
            {
                p1->val = p1->val % 10;
                cflag = 1;
            }
            else
            {
                cflag = 0;
            }
        }
        else
        {
            tail = malloc(sizeof(struct ListNode));
            tail->val = 1;//cflag
            tail->next = NULL;
            p1_last->next = tail;
            break;//cflag = 0
        }
        p1_last = p1;
        p1 = p1->next;
    }
    
    return l1;
}