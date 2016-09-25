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
    int dfs(int dep, int n) {
	int ret = 0;
	if(dep >= n) {
	    return 1;
	}
	for(int i = 0; i < n; ++i) {
	    if(check(i, dep, n)) {
		used[i] = 1;
		b[i + dep] = 1;
		c[n + i - dep] = 1;
		a[dep] = i;
		ret += dfs(dep + 1, n);
		used[i] = 0;
		b[i + dep] = 0;
		c[n + i - dep] = 0;
		a[dep] = 0;
	    }
	}
	return ret;
    }
public:
    int totalNQueens(int n) {
	a = vector<int>(n + 1);
	used = vector<int>(n + 1);
	b = vector<int>(2 * n + 1);
	c = vector<int>(2 * n + 1);
	return dfs(0, n);
        
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    cout << s.totalNQueens(4) << endl;
    cout << s.totalNQueens(5) << endl;
    return 0;
}
