#include <bits/stdc++.h>

typedef long long ll;
int a[100000];
int X[10000];
ll dp[2][4000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i] -= i;
        X[i] = a[i];
    }
    std::sort(X, X + n);
    int cnt = std::unique(X, X + n) - X;
    int cur = 1, pre = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < cnt; j++) {
            dp[cur][j] = std::abs(a[i] - X[j]) + dp[pre][j];
        }
        //for(int i = 0; i < cnt; i++) std::cout << dp[cur][i] << " "; std::cout << std::endl;
        for(int i = 1; i < cnt; i++)
            dp[cur][i] = std::min(dp[cur][i - 1], dp[cur][i]);
        std::swap(cur, pre);
    }
    std::cout << dp[pre][cnt - 1];
    return 0;
}
