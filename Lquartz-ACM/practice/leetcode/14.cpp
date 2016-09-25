#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	if(strs.size() == 0) return "";
	vector<int> g;
	int dmin = strs[0].size();
	int i, j, l, m;
	for(i = 0; i < strs.size(); ++i) {
	    g.push_back(strs[i].length());
	    dmin = min(dmin, (int)strs[i].length());
	}
	for(l = 1; l < strs.size(); l *= 2) {
	    for(i = 0; i + l < strs.size(); i += 2 * l) {
		m = dmin;
		for(j = 0; j < m; ++j) {
		    if(strs[i][j] != strs[i + l][j]) break;
		}
		dmin = min(dmin, j);
	    }
	    if(dmin == 0) break;
	}
	return strs[0].substr(0, dmin);
    }
};

int main() {
    Solution s;
    vector<string> g;
    g.push_back("a");
    g.push_back("a");
    g.push_back("b");
    cout << s.longestCommonPrefix(g);
    return 0;
}
