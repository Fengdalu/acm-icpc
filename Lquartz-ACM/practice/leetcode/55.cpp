#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
	if(nums.size() == 0) return true;
	int r, i;
	r = 1;
	for(i = 0; i < r; ++i) {
	    r = max(r, i + 1 + nums[i]);
	    if(r >= nums.size()) break;
	}
	if(r < nums.size()) return false;
	return true;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    int a[] = {2, 5, 0, 0};
    vector<int> g(a, a + 4);
    cout << s.canJump(g) << endl;
    return 0;
}
