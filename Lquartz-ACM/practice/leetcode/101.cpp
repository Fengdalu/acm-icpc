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
    bool check(TreeNode * lr, TreeNode * rr) {
	if(lr->val != rr->val) return false;
	bool ret = true;
	if(lr->left != NULL) {
	    if(rr->right == NULL) return false;
	    ret = check(lr->left, rr->right);
	    if(!ret) return false;
	}
	if(lr->right != NULL) {
	    if(rr->left == NULL) return false;
	    ret = check(lr->right, rr->left);
	    if(!ret) return false;
	}
	return ret;
    }
    bool isSymmetric(TreeNode* root) {
	if(root == NULL) return true;
	return check(root, root);
    }
};
