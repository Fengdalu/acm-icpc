#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
	int i, j;
	transform(s.begin(),s.end(),s.begin(), ::tolower);
	for(i = 0, j = s.length() - 1; i < j; ) {
	    while(i < j && !isalnum(s[i])) ++i;
	    while(i < j && !isalnum(s[j])) --j;
	    if(s[i] != s[j]) return false;
	    ++i; --j;
	}
	return true;
    }
};

int main() {

    return 0;
}
