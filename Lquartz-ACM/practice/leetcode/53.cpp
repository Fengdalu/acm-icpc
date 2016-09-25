#include <bits/stdc++.h>
using namespace std;

//------------------------Start Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
	dp[0] = nums[0];
	int ret = dp[0];
	for(int i = 1; i < nums.size(); ++i) {
	    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
	    ret = max(ret, dp[i]);
	}
	return ret;
    }
};


//-------------------------End Solution

int main() {
    Solution s;
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> g(a, a + sizeof(a) / 4);
    cout << s.maxSubArray(g) << endl;
    return 0;
}
