#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//------------------------Start Solution

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int p = 0, v1, v2;
	ListNode * head = NULL, * q;
	while(l1 != NULL || l2 != NULL) {
	    v1 = v2 = 0;
	    if(l1 != NULL) {
		v1 = l1->val;
		l1 = l1->next;
	    }
	    if(l2 != NULL) {
		v2 = l2->val;
		l2 = l2->next;
	    }
	    p = p + v1 + v2;
	    if(head == NULL) {
		head = new ListNode(p % 10);
		q = head;
	    }
	    else {
		q->next = new ListNode(p % 10);
		q = q->next;
	    }
	    p /= 10;
	}
	if(p || head == NULL) {
	    if(head == NULL) {
		head = new ListNode(p);
	    }
	    else {
		q->next = new ListNode(p);
	    }
	}
	return head;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    ListNode * l1, * l2;
    l1 = new ListNode(1);
    l2 = new ListNode(9);
    l2->next = new ListNode(9);
    ListNode * p;
    p = s.addTwoNumbers(l1, l2);
    while(p != NULL) {
	printf("%d --> ", p->val);
	p = p->next;
    }
    printf("\n");
    return 0;
}
