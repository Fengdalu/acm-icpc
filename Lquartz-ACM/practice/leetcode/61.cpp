#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
	if(head == NULL) return NULL;
	int n = 0;
	ListNode * p, * q;
	for(p = head; p != NULL; p = p->next) {
	    ++n;
	}
	k = k % n;
	k = (n - k) % n;
	if(k == 0) return head; 
	p = head;
	q = p->next;
	while(--k > 0) {
	    q = q->next;
	    p = p->next;
	}

	p->next = NULL;
	p = head;
	head = q;
	while(q != NULL && q->next != NULL) q = q->next;
	q->next = p;
	return head;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
