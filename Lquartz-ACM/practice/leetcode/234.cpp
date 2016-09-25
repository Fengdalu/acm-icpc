#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int countList(ListNode * head) {
        int ret = 0;
        while(head != NULL) {
            head = head->next;
	    ++ret;
        }
        return ret;
    }

    ListNode * reverseHalf(ListNode * head, int n) {
	ListNode * p = head, * q;
	int m = n / 2 - 1;
	head = head->next;
	p->next = NULL;
	while(m > 0) {
	    m--;
	    q = head->next;
	    head->next = p;
	    p = head;
	    head = q;
	}
	q = p;
	while(p->next != NULL) p = p->next;
	p->next = head;
	return q;
    }

    bool checkList(ListNode * head, int n) {
	ListNode * p = head, * q = head;
	int m = (n + 1) / 2;
	while(m--) {
	    q = q->next;
	}
	while(q != NULL) {
	    if(p->val != q->val) return false;
	    p = p->next;
	    q = q->next;
	}
	return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
	if(head == NULL) return true;
        int n = countList(head);
	head = reverseHalf(head, n);
	bool ret = checkList(head, n);
	head = reverseHalf(head, n);
	//cout << head->val << " " << head->next->val << endl;
	return ret;
    }
};

int main() {
    ListNode p(1), q(2);
    Solution s;
    p.next = &q;
    s.isPalindrome(&p);
    return 0;
}
