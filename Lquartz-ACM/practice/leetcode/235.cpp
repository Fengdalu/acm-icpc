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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int ps, qs;
	while(1) {
	    if(root->val == p->val || root->val == q->val) break;
	    if(p->val < root->val) ps = 0;
	    else ps =1;
	    if(q->val < root->val) qs = 0;
	    else qs = 1;
	    if(ps != qs) break;
	    if(ps == 0) root = root->left;
	    else root = root->right;
	}
	return root;
    }
};
