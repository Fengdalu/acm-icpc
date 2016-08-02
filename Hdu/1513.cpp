#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


char buf[5010];
int dp[5010][2];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        memset(dp, -1, sizeof dp);
        scanf("%s", buf + 1);
        int x = 0, y = 1;
        int len = strlen(buf + 1);
        memset(dp, 0, sizeof dp);
        for(int i = len; i >= 1; i--) {
            for(int j = i; j <= len; j++) dp[j][x] = n + 1;
            for(int j = i; j <= len; j++)
            if(buf[i] == buf[j]) dp[j][x] = dp[j - 1][y];
            else dp[j][x] = min(dp[j - 1][x], dp[j][y]) + 1;
            swap(x, y);
        }
        cout << dp[len][y] << endl;
    }
    return 0;
}
