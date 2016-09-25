#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
	if(n <= 0) return "";
	if(n == 1) return "1";
	string org = "1", tar;
	int i, j, k;
	for(i = 2; i <= n; ++i) {
	    stringstream sin;
	    for(j = 0; j < org.length(); ) {
		for(k = j; k < org.length() && org[k] == org[j]; ++k);
		sin << (k - j);
		sin << org[j];
		j = k;
	    }
	    org = sin.str();
	}
	return org;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
    return 0;
}
