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
    bool hasPathSum(TreeNode* root, int sum) {
	if(root == NULL) return false;
	if(root->left == NULL && root->right == NULL) {
	    if(sum == root->val) return true;
	    else return false;
	} 
	if(root->left != NULL) {
	    if(hasPathSum(root->left, sum - root->val)) return true;
	}
	if(root->right != NULL) {
	    if(hasPathSum(root->right, sum - root->val)) return true;
	}
	return false;
    }
};
