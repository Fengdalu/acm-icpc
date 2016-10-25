#include <bits/stdc++.h>

int a[200010];
bool dp[200010][2];
int n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    dp[0][0] = true;
    for(int i = 0; i < n; i++) {
        if(dp[i][1]) {
            int nt = a[i + 1] - 1;
            if(nt >= 0) {
                if(nt % 2 == 0) dp[i + 1][0] = true;
                else dp[i + 1][1] = true;
            }
        }
        if(dp[i][0]) {
            int nt = a[i + 1];
            if(nt % 2 == 0) dp[i + 1][0] =  true;
            else dp[i + 1][1] = true;
        }
    }
    if(dp[n][0]) puts("YES");
    else puts("NO");
    return 0;
}
