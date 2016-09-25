#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
	vector<int> ret;
	if(matrix.size() == 0) return ret;
	vector<int> line(matrix[0].size() + 2);
	vector<vector<int> > g(matrix.size() + 2);
	int i, j, u, v;
	g[0] = g[matrix.size() + 1] = line;
	for(j = 1; j <= matrix[0].size(); ++j) line[j] = 1;
	for(i = 1; i <= matrix.size(); ++i) {
	    g[i] = line;
	}
	for(i = 0; i <= matrix.size() + 1; ++i) {
	    for(j = 0; j <= matrix[0].size() + 1; ++j) {
		cout << g[i][j] << " ";
	    }
	    cout << endl;
	}
	i = 1; j = 0;
	int cnt = matrix.size() * matrix[0].size();
	while(cnt) {
	    do {
		u = i; v = j + 1;
		if(cnt && g[u][v]) {
		    cnt--;
		    g[u][v] = 0;
		    ret.push_back(matrix[u - 1][v - 1]);
		    i = u; j = v;
		}
		else {
		    break;
		}
	    }while(1);
	    do {
		u = i + 1; v = j;
		if(cnt && g[u][v]) {
		    cnt--;
		    g[u][v] = 0;
		    ret.push_back(matrix[u - 1][v - 1]);
		    i = u; j = v;
		}
		else {
		    break;
		}
	    }while(1);
	    do {
		u = i; v = j - 1;
		if(cnt && g[u][v]) {
		    cnt--;
		    g[u][v] = 0;
		    ret.push_back(matrix[u - 1][v - 1]);
		    i = u; j = v;
		}
		else {
		    break;
		}
	    }while(1);
	    do {
		u = i - 1; v = j;
		if(cnt && g[u][v]) {
		    cnt--;
		    g[u][v] = 0;
		    ret.push_back(matrix[u - 1][v - 1]);
		    i = u; j = v;
		}
		else {
		    break;
		}
	    }while(1);
	}
	return ret;
    }
};


//-------------------------End Solution

int main() {
    Solution s;
    vector<vector<int> > g;
    int a[] = {1, 2};
    int b[] = {3, 4};
    g.push_back(vector<int>(a, a + 2));
    g.push_back(vector<int>(b, b + 2));
    for(int i = 0; i < g.size(); ++i) {
	for(int j = 0; j < g[i].size(); ++j) cout << g[i][j] << " "; cout << endl;
    }
    s.spiralOrder(g);
    return 0;
}
