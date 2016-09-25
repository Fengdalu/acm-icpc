//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 101111
#define Maxm 111

int dp[Maxn];
int n, m, cash;
int nk[Maxm], dk[Maxm];
int have[Maxm];

#define NAME ""

int main() {
    int i, j, u, v, w, k;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(scanf("%d%d", &cash, &m) != EOF) {
        for(i = 0; i < m; i++) scanf("%d%d", &nk[i], &dk[i]);
        n = 0;
        for(i = 0; i <= cash; i++) dp[i] = 0;
        dp[0] = 1;
        for(i = 0; i < m; i++) {
            u = 1;
            do {
                v = min(u, nk[i]);
                nk[i] -= v;
                u <<= 1;
                have[n++] = v * dk[i];
            }while(nk[i] > 0);
        }
        for(i = 0; i < n; i++) {
            for(j = cash; j >= have[i]; j--) {
                if(dp[j - have[i]]) dp[j] = 1;
            }
        }
        for(j = cash; j >= 0; j--) {
            if(dp[j]) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
