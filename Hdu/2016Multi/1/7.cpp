#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ONES(x) __builtin_popcount(x)

typedef long long ll;
const int mod = 1e9 + 7;
ll dp[20][20];
ll thr[500];
ll tri[20][20];

int main() {
    thr[0] = 1;
    for(int i = 1; i < 500; i++) thr[i] = thr[i - 1] * 3 % mod;
    dp[0][0] = 1;
    tri[0][0] = 1;
    for(int i = 1; i < 20; i++) {
        tri[i][0] = 1;
        for(int j = 1; j <= i; j++)
            tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
    }

    for(int i = 1; i < 20; i++)
        for(int j = 0; j < 20; j++) {
            dp[i][j] = thr[i * j];
            for(int a = 1; a <= i; a++)
                for(int b = 0; b <= j; b++) if(i != a || b != j) {
                    dp[i][j] -= tri[i - 1][a - 1] * tri[j][b] % mod * thr[(j - b) * (i - a)] % mod * dp[a][b] % mod;
                    if(dp[i][j] < 0) dp[i][j] += mod;
            }
        }
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        cout << dp[n][m] << endl;
    }
    return 0;
}
