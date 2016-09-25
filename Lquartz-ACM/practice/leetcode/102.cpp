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
    vector<vector<int> > levelOrder(TreeNode* root) {
	vector<vector<int> > mat;
	if(root == NULL) return mat;
	queue<pair<TreeNode *, int> > que;
	int id;
	que.push(make_pair(root, 0));
	while(!que.empty()) {
	    root = que.front().first;
	    id = que.front().second;
	    que.pop();
	    if(mat.size() <= id) mat.push_back(vector<int>());
	    mat[id].push_back(root->val);
	    if(root->left != NULL) que.push(make_pair(root->left, id + 1));
	    if(root->right != NULL) que.push(make_pair(root->right, id + 1));
	}
	return mat;
    }
};
