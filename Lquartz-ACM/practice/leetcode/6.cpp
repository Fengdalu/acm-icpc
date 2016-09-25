#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
	vector<vector<char> > mat;
	int i, j, k;
	for(i = 0; i < numRows; ++i) mat.push_back(vector<char>());
	for(k = 0; k < s.length(); ) {
	    for(i = 0; i < numRows && k < s.length(); ++i, ++k) {
		mat[i].push_back(s[k]);
	    }
	    //printf("1 %d %d\n", i, k);
	    if(k >= s.length()) break;
	    for(i = 0; i < numRows; ++i) mat[i].push_back('\0');
	    for(i = numRows - 2; i > 0 && k < s.length(); --i) mat[i][mat[i].size() - 1] = s[k++];
	    //printf("2 %d %d\n", i, k);
	    if(k >= s.length()) break;
	}
	string ret;
	char ch;
	for(i = 0; i < numRows; ++i) {
	    for(j = 0; j < mat[i].size(); ++j) {
		ch = mat[i][j];
		if(ch != '\0') ret += ch;
	    }
	}
	return ret;
    }
};

int main() {
    Solution s;
    cout << s.convert("ABC", 2) << endl;
    return 0;
}
