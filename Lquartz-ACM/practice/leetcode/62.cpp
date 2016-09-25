#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
public:
    int uniquePaths(int m, int n) {
	if(m < n) swap(m, n);
	long long ret = 1;
	int N = n + m - 2;
	for(long long i = 1, j = N; i < n; ++i, --j) {
	    ret *= j;
	    ret /= i;
	}
	return ret;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    cout << s.uniquePaths(3, 1) << endl;
    cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(3, 3) << endl;
    cout << s.uniquePaths(51, 9) << endl;
    return 0;
}
