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
    bool flag;
public:
    int diff(TreeNode * root) {
	if(root == NULL) return 0;
	int dl = 0, dr = 0;
	if(root->left != NULL) dl = diff(root->left);
	if(root->right != NULL) dr = diff(root->right);
	if(abs(dl - dr) > 1) flag = false;
	return max(dl, dr) + 1;
    }
    bool isBalanced(TreeNode* root) {
	if(root == NULL) return true;
	flag = true;
	diff(root);
	return flag;
    }
};
