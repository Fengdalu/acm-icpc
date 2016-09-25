#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
	int n = obstacleGrid.size();
	if(n == 0) return 0;
	int m = obstacleGrid[0].size();
	int i, j;
	vector<long long> line(m, 0);
	vector<vector<long long > > ret(n, line);
	ret[0][0] = 1;
	if(obstacleGrid[0][0]) ret[0][0] = 0;
	for(i = 1; i < n; ++i) {
	    if(obstacleGrid[i][0]) ret[i][0] = 0;
	    else ret[i][0] = ret[i - 1][0];
	}
	for(j = 1; j < m; ++j) {
	    if(obstacleGrid[0][j]) ret[0][j] = 0;
	    else ret[0][j] = ret[0][j - 1];
	}
	for(i = 1; i < n; ++i) {
	    for(j = 1; j < m; ++j) {
		if(obstacleGrid[i][j]) ret[i][j] = 0;
		else ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
	    }
	}
	return ret[n - 1][m - 1]; 
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
