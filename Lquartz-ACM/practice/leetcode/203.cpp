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
    ListNode* removeElements(ListNode* head, int val) {
	ListNode * p, * q;
	while(head != NULL && head->val == val) head = head->next;
	if(head == NULL) return head;
	for(p = head->next, q = head; p != NULL; ) {
	    if(p->val == val) {
		q->next = p->next;
		p = p->next;
	    }
	    else {
		q = p; 
		p = p->next;
	    }
	}
	return head;
    }
};
