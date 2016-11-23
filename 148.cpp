#include <cstdlib>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoSortList(ListNode *l1, ListNode *l2) {
		ListNode dummy(0);
		ListNode *p = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
				p = p->next;
			}
		}
		p->next = l1 ? l1 : l2;
		return dummy.next;
	}
	ListNode* sortList_merge(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL;
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(fast);
		return mergeTwoSortList(l1, l2);
	}

	void qsortList_TLE(ListNode* &head, ListNode* &tail) {
		if (!head || !head->next) {
			tail = head;
			return;
		}
		int pivot = head->val;
		ListNode left_dummy(0), right_dummy(0);
		ListNode *left = &left_dummy;
		ListNode *right = &right_dummy;
		ListNode *p = head->next;
		while (p) {
			if (p->val < pivot) {
				left->next = p;
				left = left->next;
			}
			else {
				right->next = p;
				right = right->next;
			}
			p = p->next;
		}
		left->next = NULL;
		right->next = NULL;
		qsortList_TLE(left_dummy.next, left);
		qsortList_TLE(right_dummy.next, right);
		if (!left_dummy.next) {
			head->next = right_dummy.next;
			tail = right_dummy.next ? right : head;
		}
		else {
			left->next = head;
			tail = right_dummy.next ? right : head;
			head->next = right_dummy.next;
			head = left_dummy.next;
		}
	}
	void qsortList(ListNode* &head, ListNode* &tail) {
		if (!head || !head->next) {
			tail = head;
			return;
		}
		int standard = head->val;
		ListNode left_dummy(0), pivot_dummy(0), right_dummy(0);
		ListNode *left = &left_dummy;
		ListNode *pivot = &pivot_dummy;
		ListNode *right = &right_dummy;
		ListNode *p = head;
		while (p) {
			if (p->val < standard) {
				left->next = p;
				left = left->next;
			}
			else if (p->val == standard) {
				pivot->next = p;
				pivot = pivot->next;
			}
			else {
				right->next = p;
				right = right->next;
			}
			p = p->next;
		}
		left->next = pivot->next = right->next = NULL;
		qsortList(left_dummy.next, left);
		qsortList(right_dummy.next, right);
		if (!left_dummy.next) {
			head = pivot_dummy.next;
		}
		else {
			head = left_dummy.next;
			left->next = pivot_dummy.next;
		}
		pivot->next = right_dummy.next;
		tail = right_dummy.next ? right : pivot;
	}
	ListNode* sortList(ListNode* head) {
		ListNode* tail = head;
		qsortList(head, tail);
		return head;
	}
};

int main() {
	ListNode n0(5), n1(4), n2(3), n3(2), n4(1);
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	Solution slu;
	slu.sortList(&n0);
}