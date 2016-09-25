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
    ListNode* reverseList(ListNode* head) {
	ListNode * p, * q;
	if(head == NULL) return head;
	p = head;
	head = head->next;
	p->next = NULL;
	while(head != NULL) {
	    q = head->next;
	    head->next = p;
	    p = head;
	    head = q;
	}
	return p;
    }
};
