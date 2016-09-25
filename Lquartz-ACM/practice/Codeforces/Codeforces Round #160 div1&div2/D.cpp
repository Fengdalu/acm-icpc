#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 55
int a[Maxn], n, p;
double A[Maxn];
double dp[Maxn][Maxn][Maxn];

int main() {
    int i, j, k, u, v, w;
    while(scanf("%d", &n) != EOF) {
        for(i = 1; i <= n; i++) scanf("%d", &a[i]);
        scanf("%d", &p);
        A[0] = 1;
        A[1] = 1;
        for(i = 2; i <= n; i++) A[i] = A[i - 1] * i;
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                for(k = 0; k <= p; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for(i = 1; i <= n; i++) {
            for(j = 0; j <= i; j++) {
                for(k = 0; k <= p; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
            for(j = 1; j <= i; j++) {
                for(k = a[i]; k <= p; k++) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
                }
            }
        }
        double ans = 0;
        for(j = 1; j <= n; j++) {
            for(k = 1; k <= p; k++) {
                //printf("dp[%d][%d][%d] = %.8f\n", n, j, k, dp[n][j][k]);
                ans += dp[n][j][k] * A[n - j] * A[j];
            }
        }
        ans /= A[n];
        printf("%.8f\n", ans);
    }
    
    return 0;
}

