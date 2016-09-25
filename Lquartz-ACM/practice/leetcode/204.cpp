#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
	int * ispri;
	int i, j, ret = 0;
	ispri = (int *) malloc(sizeof(int) * (n + 2));
	for(i = 2; i < n; ++i) ispri[i] = 1;
	for(i = 2; i < n; ++i) {
	    if(!ispri[i]) continue;
	    ret++;
	    for(j = 2; j * i <= n; ++j) {
		ispri[i * j] = 0;
	    }
	}
	return ret;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(2) << endl;
    return 0;
}
