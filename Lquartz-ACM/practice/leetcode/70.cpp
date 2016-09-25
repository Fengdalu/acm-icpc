class Solution {
public:
    int climbStairs(int n) {
	int * dp = new int[n + 2]();
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(i = 1; i <= n; ++i) {
	    dp[i] += dp[i - 1];
	    if(i > 1) dp[i] += dp[i - 2];
	}
	return dp[n];
    }
};
