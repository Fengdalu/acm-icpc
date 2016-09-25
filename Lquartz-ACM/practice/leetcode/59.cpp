#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
    void FillLine(int& cur, int& x, int& y, int n, int dx, int dy, vector<vector<int> >& ret) {
	if(n <= 0) return;
	while(n--) {
	    ret[x][y] = cur++;
	    if(n) {x += dx; y += dy;}
	}
    }
    void fill(int& cur, int& x, int& y, int n, vector<vector<int> >& ret) {
	if(n <= 0) return;
	FillLine(cur, x, y, n, 0, 1, ret);
	++x;
	FillLine(cur, x, y, n - 1, 1, 0, ret);
	--y;
	FillLine(cur, x, y, n - 1, 0, -1, ret);
	--x;
	FillLine(cur, x, y, n - 2, -1, 0, ret);
	++y;
    }
public:
    vector<vector<int> > generateMatrix(int n) {
	vector<vector<int> > ret;        
	vector<int> line(n);
	int i, j, cur;
	for(i = 0; i < n; ++i) ret.push_back(line);
	i = 0, j = 0, cur = 1;
	while(n > 0) {
	    fill(cur, i, j, n, ret);
	    n-=2;
	}
	return ret;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    vector<vector<int> > g;
    g = s.generateMatrix(1);
    for(int i = 0; i < g.size(); ++i) {
	for(int j = 0; j < g[i].size(); ++j) {
	    cout << g[i][j] << " ";
	}
	cout << endl;
    }
    cout << "------------------------" << endl;
    g = s.generateMatrix(2);
    for(int i = 0; i < g.size(); ++i) {
	for(int j = 0; j < g[i].size(); ++j) {
	    cout << g[i][j] << " ";
	}
	cout << endl;
    }
    cout << "------------------------" << endl;
    g = s.generateMatrix(4);
    for(int i = 0; i < g.size(); ++i) {
	for(int j = 0; j < g[i].size(); ++j) {
	    cout << g[i][j] << " ";
	}
	cout << endl;
    }
    return 0;
}
