#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
	input = input;
	vector<int> g;
	vector<char> opt;
	int i, j, k, l;
	for(i = 0; i < input.length(); ) {
	    while(i < input.length() && !isdigit(input[i])) ++i;
	    for(j = i; j < input.length() && isdigit(input[j]); ++j);
	    g.push_back(atoi(input.substr(i, j - i).c_str()));
	    i = j;
	    if(i < input.length()) opt.push_back(input[i]);
	}
	int n = g.size();
	multiset<int> dp[n + 2][n + 2];        
	multiset<int>::iterator I, J;
	//for(i = 0; i < n + 2; ++i) for(j = 0; j < n + 2; ++j) dp[i][j]();
	for(i = 0; i < n; ++i) {
	    dp[i][i].insert(g[i]);
	}
	for(l = 2; l <= n; l++) {
	    for(i = 0; i < n; ++i) {
		j = i + l - 1;
		if(j >= n) break;
		//printf("doit [%d, %d]\n", i, j);
		for(k = i; k < j; ++k) {
		    //printf("\t [%d, %d] %c [%d, %d]\n", i, k, opt[k], k + 1, j);
		    if(opt[k] == '-') {
			for(I = dp[i][k].begin(); I != dp[i][k].end(); ++I) {
			    for(J = dp[k + 1][j].begin(); J != dp[k + 1][j].end(); ++J) {
				dp[i][j].insert((*I) - (*J));
			    }
			}
		    }
		    if(opt[k] == '+') {
			for(I = dp[i][k].begin(); I != dp[i][k].end(); ++I) {
			    for(J = dp[k + 1][j].begin(); J != dp[k + 1][j].end(); ++J) {
				dp[i][j].insert((*I) + (*J));
			    }
			}
		    }
		    if(opt[k] == '*') {
			for(I = dp[i][k].begin(); I != dp[i][k].end(); ++I) {
			    for(J = dp[k + 1][j].begin(); J != dp[k + 1][j].end(); ++J) {
				dp[i][j].insert((*I) * (*J));
			    }
			}
		    }
		}
		//printf("size %d\n", dp[i][j].size());
	    }
	}
	return vector<int>(dp[0][n - 1].begin(), dp[0][n - 1].end());
    }
};

int main() {
    Solution s;
    vector<int> g;
    g = s.diffWaysToCompute("2*3-4*5");
    for(int i = 0; i < g.size(); ++i) cout << g[i] << " "; cout << endl;
    return 0;
}
