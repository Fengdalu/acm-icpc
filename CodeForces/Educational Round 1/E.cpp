#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long
#define ccmin(x, y) if(x == -1) x = y; else x = min(x, y)
#define INF 1000000009
const int Maxn = 52;


LL dp[Maxn][Maxn][Maxn];

LL cal(int x, int y, int k) {
    if(k == 0) return 0;
    if(x * y < k) return INF;
    if(x * y == k) return 0;
    if(dp[x][y][k] != -1) return dp[x][y][k];
    for(int i = 1; i < x; i++)
        for(int j = 0; j <= k; j++)
            ccmin(dp[x][y][k], cal(i, y, j) + cal(x - i, y, k - j) + y * y);
    for(int i = 1; i < y; i++)
        for(int j = 0; j <= k; j++)
            ccmin(dp[x][y][k], cal(x, i, j) + cal(x, y - i, k - j) + x * x);
    return dp[x][y][k];
}



int main() {
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= 30; i++) for(int j = 1; j <= 30; j++)
    for(int k = 1; k <= 50; k++) cal(i, j, k);

    int T; scanf("%d", &T);
    for(int C = 1; C <= T; C++) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("%I64d\n", cal(n, m, k));
    }
    return 0;
}
