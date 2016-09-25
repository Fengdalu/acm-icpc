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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(l1 == NULL && l2 == NULL) return NULL;
	if(l1 == NULL) swap(l1, l2);
	if(l2 != NULL && l1->val > l2->val) swap(l1, l2);
	ListNode * p = l1, * q = l1;
	l1 = l1->next;
	p->next = NULL;
	while(l1 != NULL && l2 != NULL) {
	    if(l1->val < l2->val) {
		p->next = l1;
		l1 = l1->next;
		p = p->next;
		p->next = NULL;
	    }
	    else {
		p->next = l2;
		l2 = l2->next;
		p = p->next;
		p->next = NULL;
	    }
	}
	while(l1 != NULL) {
	    p->next = l1;
	    l1 = l1->next;
	    p = p->next;
	    p->next = NULL;
	}
	while(l2 != NULL) {
	    p->next = l2;
	    l2 = l2->next;
	    p = p->next;
	    p->next = NULL;
	}
	return q;
    }
};
