#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
	vector<vector<int> > mat;
	mat.clear();
	if(numRows <= 0) return mat;
	vector<int> g;
	g.push_back(1);
	mat.push_back(g);
	int i, j;
	for(i = 2; i <= numRows; ++i) {
	    g.clear();
	    for(j = 0; j < i; ++j) {
		if(j == 0) g.push_back(mat[i - 2][j]);
		else if(j == i - 1) g.push_back(mat[i - 2][j - 1]);
		else g.push_back(mat[i - 2][j] + mat[i - 2][j - 1]);
	    }
	    mat.push_back(g);
	}
	return mat;
    }
};


void print(vector<vector<int> > g) {
    for(int i = 0; i < g.size(); ++i) {
	for(int j = 0; j < g[i].size(); ++j) cout << g[i][j] << " "; cout << endl;
    }
}
int main() {
    Solution s;
    vector< vector<int> > g = s.generate(1);
    print(g);
    g = s.generate(2);
    print(g);
    g = s.generate(3);
    print(g);
    g = s.generate(4);
    print(g);

    return 0;
}
