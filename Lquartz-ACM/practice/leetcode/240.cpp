#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
	int n = matrix.size();
	if(n == 0) return false;
	int m = matrix[0].size();
	int nn, mm;
	int i;
	if(target < matrix[0][0] || target > matrix[n - 1][m - 1]) return false;
	for(i = 0; i < n; ++i) {
	    if(matrix[i][0] > target) return false;
	    mm = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
	    if(mm < m && matrix[i][mm] == target) return true;
	}
	return false;
    }
};

int main() {
    Solution s;
    vector<vector<int> > g;
    g.clear();
    //[[1,3,5]], 2
    g.push_back(vector<int>());
    g[0].push_back(1); g[0].push_back(3); g[0].push_back(5);
    cout << s.searchMatrix(g, 2) << endl;
    
    g.clear();
    //[[1,2,3,4,5]], 1
    g.push_back(vector<int>());
    g[0].push_back(1); g[0].push_back(2); g[0].push_back(3); g[0].push_back(4); g[0].push_back(5);
    cout << s.searchMatrix(g, 1) << endl;
    
    g.clear();
    //[[1,3,5]], 1
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    g[0].push_back(1); g[1].push_back(3); g[2].push_back(5);
    cout << s.searchMatrix(g, 1) << endl;

    g.clear();
    g.push_back(vector<int>());
    g[0].push_back(-1); g[0].push_back(3);
    cout << s.searchMatrix(g, 1) << endl;
    
    g.clear();
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    g[0].push_back(5);
    g[1].push_back(6);
    cout << s.searchMatrix(g, 5) << endl;

    g.clear();
    g.push_back(vector<int>());
    g[0].push_back(-5); 
    cout << s.searchMatrix(g, -5) << endl;

    g.clear();
    g.push_back(vector<int>());
    g.push_back(vector<int>());
    g[0].push_back(5); 
    g[1].push_back(6); 
    cout << s.searchMatrix(g, 6) << endl;

    int valuesxx[][6] = {
	{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
    };
    g.clear();
    for(int i = 0; i < 5; ++i) {
	g.push_back(vector<int>());
	for(int j = 0; j < 5; ++j) g[i].push_back(valuesxx[i][j]);
    }
    cout << s.searchMatrix(g, 5) << endl;
    return 0;
}
