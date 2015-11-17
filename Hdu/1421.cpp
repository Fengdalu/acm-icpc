#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
int n, k;
const LL INF = (1LL << 62);
LL dp[2010][1010];
int c[2010];

LL sqr(int x) { return x * x; }

int main(){
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
        sort(c + 1, c + n + 1);
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            for(int j = 0; j <= k; j++)
                if(dp[i][j] != INF) {
                    cmin(dp[i + 2][j + 1], dp[i][j] + sqr(c[i + 1] - c[i + 2]));
                    cmin(dp[i + 2][j], dp[i][j]);
                    cmin(dp[i + 1][j], dp[i][j]);
                }
        }
        printf("%I64d\n", dp[n][k]);
    }
    return 0;
}
