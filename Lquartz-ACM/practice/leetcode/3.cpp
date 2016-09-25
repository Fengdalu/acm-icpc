#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	if(s.length() == 0) return 0;
	int pre[300];
	memset(pre, -1, sizeof(pre));
	vector<int> mark(s.length() + 1);
	int ans = 1;
	int i, j, k;
	pre[s[0]] = 0, mark[0] = -1;
	for(i = 1; i < s.length(); ++i) {
	    mark[i] = pre[s[i]];
	    pre[s[i]] = i;
	    if(i - mark[i] < ans) continue;
	    for(k = mark[i], j = i - 1; j > k; --j) {
		if(mark[j] > k) k = mark[j];
	    }
	    if(ans < i - k) ans = i - k;
	}
	return ans;
    }
};
//-------------------------End Solution

int main() {
    Solution s;
    string s1 = "abcaabc";
    string s2 = "bbbb";
    cout << s.lengthOfLongestSubstring(s1) << endl;
    cout << s.lengthOfLongestSubstring(s2) << endl;
    return 0;
}
