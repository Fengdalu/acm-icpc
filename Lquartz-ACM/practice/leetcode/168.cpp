#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
	string ret;
	do{
	    n--;
	    int m = n % 26;
	    n /= 26;
	    ret = (char)('A' + m) + ret;
	}while(n);
	//reverse(ret.begin(), ret.end());
	return ret;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
    return 0;
}
