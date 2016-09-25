/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode * p, TreeNode * q) {
	if(p->val != q->val) return false;
	bool ret;
	if(p->left != NULL) {
	    if(q->left == NULL || !check(p->left, q->left)) return false;
	}
	else if(q->left != NULL) return false;

	if(p->right != NULL) {
	    if(q->right == NULL || !check(p->right, q->right)) return false;
	}
	else if(q->right != NULL) return false;

	return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
	if(p == NULL && q == NULL) return true;
	if(p == NULL || q == NULL) return false;
	return check(p, q);
    }
};
