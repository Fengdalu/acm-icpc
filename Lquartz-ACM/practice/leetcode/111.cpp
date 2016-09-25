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
    int minDepth(TreeNode* root) {
	if(root == NULL) return 0;
	queue<pair<TreeNode *, int> > que;
	int dep;
	que.push(make_pair(root, 1));
	while(!que.empty()) {
	    root = que.front().first;
	    dep = que.front().second;
	    que.pop();
	    if(root->left == NULL && root->right == NULL) return dep;
	    if(root->left != NULL) {
		que.push(make_pair(root->left, dep + 1));
	    }
	    if(root->right != NULL) {
		que.push(make_pair(root->right, dep + 1));
	    }
	}
    }
};
