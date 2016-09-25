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
    ListNode* deleteDuplicates(ListNode* head) {
	if(head == NULL || head->next == NULL) return head;
	ListNode * p, * q;
	for(p = head->next, q = head; p != NULL; ) {
	    if(p->val == q->val) {
		q->next = p->next;
		p = p->next;
	    }
	    else {
		q = q->next;
		p = p->next;
	    }
	}
	return head;
    }
};
