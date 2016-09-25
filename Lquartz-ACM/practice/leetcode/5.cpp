#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
public:
    string longestPalindrome(string s) {
	int i, j, k, p, len = -1;
	for(i = 0; i < s.length(); ++i) {
	    for(j = i - 1, k = i + 1; j >= 0 && k < s.length() && s[j] == s[k]; --j, ++k);
	    if(len < k - j - 1) {
		len = k - j - 1;
		p = j + 1;
	    }
	    for(j = i, k = i + 1; j >= 0 && k < s.length() && s[j] == s[k]; --j, ++k);
	    if(len < k - j - 1) {
		len = k - j - 1;
		p = j + 1;
	    }
	}
	return s.substr(p, len);
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    string s1 = "aaabaa";
    string s2 = "aaabbbbaa";
    cout << s.longestPalindrome(s1) << endl;
    cout << s.longestPalindrome(s2) << endl;
    return 0;
}
