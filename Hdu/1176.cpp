#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define cmax(x, y) x = max(x, y)
int n;
int dp[110010][11];
int c[110010][11];

int main(){
    while(true) {
        scanf("%d", &n);
        if(!n) break;
        memset(c, 0, sizeof c);
        memset(dp, -1, sizeof dp);
        int m = 0;
        for(int i = 0; i < n; i++) {
            int T, x; scanf("%d%d", &x, &T);
            c[T][x]++;
            cmax(m, T);
        }
        dp[0][5] = 0;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j < 11; j++) if(dp[i][j] != -1){
                cmax(dp[i + 1][j], dp[i][j] + c[i + 1][j]);
                if(j + 1 < 11) cmax(dp[i + 1][j + 1], dp[i][j] + c[i + 1][j + 1]);
                if(j - 1 >= 0) cmax(dp[i + 1][j - 1], dp[i][j] + c[i + 1][j - 1]);
            }
        }

        int ans = 0;
        for(int i = 0; i < 11; i++)
            if(dp[m][i] != -1) cmax(ans, dp[m][i]);
        printf("%d\n", ans);
    }
    return 0;
}
