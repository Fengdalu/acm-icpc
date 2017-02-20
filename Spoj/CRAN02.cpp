#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    int T; 
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        int n, sum = 0;
        long long ans = 0;
        scanf("%d", &n);
        map<int, int> dp;
        dp[0]++;
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
            ans += 1LL * dp[sum];
            dp[sum]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}