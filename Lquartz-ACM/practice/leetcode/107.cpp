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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
	vector<vector<int> > ret;
	int id;
	if(root == NULL) return ret;
	queue<pair<TreeNode *, int> > que;
	que.push(make_pair(root, 0));
	while(!que.empty()) {
	    root = que.front().first;
	    id = que.front().second;
	    que.pop();
	    if(ret.size() <= id) {
		ret.push_back(vector<int>());
	    }
	    ret[id].push_back(root->val);
	    if(root->left != NULL) que.push(make_pair(root->left, id + 1));
	    if(root->right != NULL) que.push(make_pair(root->right, id + 1));
	}
	reverse(ret.begin(), ret.end());
	return ret;
    }
};
