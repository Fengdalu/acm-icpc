#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define cmax(x, y) x = max(x, y)
int a[5001];
LL dp[5001];
int n;

int main(){
    while(true) {
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++) {
            dp[i] = a[i];
            for(int j = 0; j < i; j++) if(a[j] < a[i])
                cmax(dp[i], dp[j] + (LL)a[i]);
        }
        LL ans = 0;
        for(int i = 0; i < n; i++) cmax(ans, dp[i]);
        printf("%I64d\n", ans);
    }
}
