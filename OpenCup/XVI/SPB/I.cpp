#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e10;
long long dp[maxn][2];
int a[maxn], b[maxn];
int n;

void cmin(long long &a, long long b) {
    if(a == -1) a = b;
    else a = min(a, b);
}

int main() {
    freopen("space-cat.in", "r", stdin);
    freopen("space-cat.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
    dp[0][0] = 0;
    dp[0][1] = b[0] - a[0];
    for(int i = 0; i < n - 1; i++) {
        if(a[i] >= a[i + 1] && b[i + 1] > a[i]) {
            if(dp[i][0] != -1) cmin(dp[i + 1][0], dp[i][0]);
            if(dp[i][1] != -1) cmin(dp[i + 1][0], dp[i][1] + b[i] - a[i]);
        }
        if(b[i] <= b[i + 1] && a[i + 1] < b[i]) {
            if(dp[i][1] != -1) cmin(dp[i + 1][1], dp[i][1]);
            if(dp[i][0] != -1) cmin(dp[i + 1][1], dp[i][0] + b[i] - a[i]);
        }
    }
    //for(int i = 0; i < n; i++) cout << dp[i][0] << " " << dp[i][1] << endl;
    if(dp[n - 1][1] != -1) cmin(dp[n - 1][0], dp[n - 1][1] + b[n - 1] - a[n - 1]);
    if(dp[n - 1][0] == -1) puts("-1");
    else cout << dp[n - 1][0] << endl;
    return 0;
}
