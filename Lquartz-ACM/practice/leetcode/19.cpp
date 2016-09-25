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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(head == NULL) return NULL;
	ListNode * p, * q;
	for(p = q = head; n >= 1; --n, q = q->next);
	if(q == NULL) return p->next;
	while(q->next != NULL) {
	    p = p->next;
	    q = q->next;
	}
	p->next = p->next->next;
	return head;
    }
};
