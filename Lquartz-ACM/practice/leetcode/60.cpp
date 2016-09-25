#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
    string ans;
    vector<int> used;
    vector<int> have;
public:
    string getPermutation(int n, int k) {
	ans = string(n, '0');
	used = vector<int>(n, 0);
	have = vector<int>(n, 0);
	int i, j, l, p;
	for(i = 1, j = n - 2, have[n - 1] = 1; i < n; ++i, j--) {
	    have[j] = have[j + 1] * (i + 1);
	}
	for(i = 0; i < n; ++i) cout << have[i] << endl;
	for(i = 0; i < n - 1; ++i) {
	    l = k / have[i + 1];
	    if(k % have[i + 1] == 0) l--;
	    k -= l * have[i + 1];
	    for(j = 0; j < n; ++j) {
		if(!used[j]) {
		    p = j;
		    if(l <= 0) {
			used[j] = 1;
			ans[i] = '1' + j;
			break;
		    }
		    --l;
		}
	    }
	}
	for(j = 0; j < n; ++j) if(!used[j]) ans[n - 1] = '1' + j;
	return ans;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    cout << s.getPermutation(3, 1) << endl;
    cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(3, 6) << endl;
    return 0;
}
