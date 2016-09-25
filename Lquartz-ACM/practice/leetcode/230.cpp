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
    int countNum(TreeNode * root) {
	if(root == NULL) return 0;
	int ret = 1;
	if(root->left != NULL) ret += countNum(root->left);
	if(root->right != NULL) ret += countNum(root->right);
	return ret;
    }
    int kthSmallest(TreeNode* root, int k) {
	if(root == NULL) return 0;
	int have = 0;
	if(root->left != NULL) {
	    have = countNum(root->left);
	}
	if(have >= k) {
	    return kthSmallest(root->left, k);
	}
	else {
	    if(have == k - 1) return root->val;
	    else return kthSmallest(root->right, k - have - 1);
	}
    }
};
