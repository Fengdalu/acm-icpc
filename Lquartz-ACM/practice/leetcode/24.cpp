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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * p = head;
        while(head != NULL) {
            int & pre = head->val;
            head = head->next;
            if(head != NULL) {
                swap(pre, head->val);
                head = head->next;
            }
        }
        return p;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
