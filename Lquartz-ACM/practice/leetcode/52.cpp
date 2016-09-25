#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
    vector<string> g;
    vector<int> a, b, c, used;
    bool check(int i, int dep, int n) {
	if(used[i]) return false;
	if(b[i + dep]) return false;
	if(c[n + i - dep]) return false;
	return true;
    }
    void dfs(int dep, int n, vector<vector<string> > & ret) {
	if(dep >= n) {
	    ret.push_back(g);
	    int m = ret.size() - 1;
	    for(int i = 0; i < n; ++i) {
		ret[m][i][a[i]] = 'Q';
	    }
	    return;
	}
	for(int i = 0; i < n; ++i) {
	    if(check(i, dep, n)) {
		used[i] = 1;
		b[i + dep] = 1;
		c[n + i - dep] = 1;
		a[dep] = i;
		dfs(dep + 1, n, ret);
		used[i] = 0;
		b[i + dep] = 0;
		c[n + i - dep] = 0;
		a[dep] = 0;
	    }
	}
    }
public:
    vector<vector<string> > solveNQueens(int n) {
	vector<vector<string> > ret;        
	g.clear();
	string line = "";
	for(int i = 0; i < n; ++i) line.append(".");
	for(int i = 0; i < n; ++i) {
	    g.push_back(line);
	}
	a = vector<int>(n + 1);
	used = vector<int>(n + 1);
	b = vector<int>(2 * n + 1);
	c = vector<int>(2 * n + 1);
	dfs(0, n, ret);
	return ret;
    }
};


//-------------------------End Solution

int main() {
    Solution s;
    vector<vector<string> > ret = s.solveNQueens(4);
    for(int i = 0; i < ret.size(); ++i) {
	for(int j = 0; j < ret[i].size(); ++j) {
	    cout << ret[i][j] << endl;
	}
	cout << endl;
    }
    return 0;
}
