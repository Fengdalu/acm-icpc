#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
	vector<int> g;
	long long n = 1;
	g.push_back(n);
	for(int i = 1; i <= rowIndex; ++i) {
	    n *= (long long )(rowIndex - i + 1);
	    n /= (long long)i;
	    g.push_back(n);
	}
	return g;
    }
};

int main() {
    Solution s;
    vector<int> g = s.getRow(5);
    for(int i = 0; i < g.size(); i++) printf("%d ", g[i]); printf("\n");

    return 0;
}
