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
    int maxDepth(TreeNode* root) {
	if(root == NULL) return 0;
	int ret = 1;
	if(root->left != NULL) ret = max(ret, maxDepth(root->left) + 1);
	if(root->right != NULL) ret = max(ret, maxDepth(root->right) + 1);
	return ret;
    }
};
