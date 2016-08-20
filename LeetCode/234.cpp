#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
	ListNode* head;
	ListNode* dfs(ListNode *p) {
		if (!p)
			return head;
		ListNode *cmp = dfs(p->next);
		if (!cmp)
			return NULL;
		if (cmp->val == p->val)
			return cmp->next ? cmp->next : head;
		else
			return NULL;
	}
public:
	bool isPalindrome_dfs_stack(ListNode* head) {
		if (!head)
			return true;
		this->head = head;
		if (dfs(head))
			return true;
		else
			return false;
	}
	bool isPalindrome(ListNode* head) {
		int len = 0;
		ListNode* p = head;
		while (p) {
			len++;
			p = p->next;
		}
		if (len < 2)
			return true;

		ListNode dummy(0);
		dummy.next = head;
		ListNode* pre = &dummy;
		p = head;
		ListNode* head2;
		for (int i = 0; i < len / 2; i++) {
			pre = pre->next;
			p = p->next;
		}
		pre->next = NULL;
		head2 = len & 1 ? p->next : p;

		pre = head;
		p = head->next;
		while (p) {
			pre->next = p->next;
			p->next = dummy.next;
			dummy.next = p;
			p = pre->next;
		}

		head = dummy.next;
		while (head && head2) {
			if (head->val != head2->val)
				return false;
			head = head->next;
			head2 = head2->next;
		}
		return true;
	}
};

int main() {
	ListNode n0(1);
	ListNode n1(2);
	ListNode n2(2);
	ListNode n3(1);
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	Solution slu;
	slu.isPalindrome(&n0);
	return 0;
}