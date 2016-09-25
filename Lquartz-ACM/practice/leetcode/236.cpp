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
    bool findNode(TreeNode * root, TreeNode * p, stack<TreeNode *>& sta) {
	sta.push(root);
	if(root == p) return true;
	if(root->left != NULL) {
	    if(findNode(root->left, p, sta)) return true;
	}
	if(root->right != NULL) {
	    if(findNode(root->right, p, sta)) return true;
	}
	sta.pop();
	return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL) return NULL;
	if(p == NULL || q == NULL) return NULL;
        stack<TreeNode * > sp, sq;
	if(!findNode(root, p, sp)) return NULL;
	if(!findNode(root, q, sq)) return NULL;
	if(sp.size() < sq.size()) swap(sp, sq);
	while(sp.size() > sq.size()) sp.pop();
	while(sp.top() != sq.top()) sp.pop(), sq.pop();
	return sp.top();
    }
};
