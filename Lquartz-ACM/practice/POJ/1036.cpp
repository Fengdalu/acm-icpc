#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define Maxn 105
#define Maxt 30011

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define cmax(x,y) x=max(x,y)
int T[Maxn], P[Maxn], S[Maxn];

vector< pair<PII, int> > g;
int dp[Maxn];

int main() {
    int i, j, l, u, v, w;
    int n, k, t;
    while(scanf("%d%d%d", &n, &k, &t) != EOF) {
        for(i = 0; i < n; i++) scanf("%d", &T[i]);
        for(i = 0; i < n; i++) scanf("%d", &P[i]);
        g.clear();
        for(i = 0; i < n; i++) {
            scanf("%d", &S[i]);
            g.PB(MP(MP(T[i], S[i]), P[i]));
        }
        g.PB(MP(MP(0, 0),-Maxt));
        sort(g.BG, g.ED);
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= k; j++) {
                dp[i] = -1;
            }
        }
        dp[0] = 0;
        int ans = 0;
        for(i = 1; i <= n; i++) {
            int tt = g[i].AA.AA, ss = g[i].AA.BB, pp = g[i].BB;
            for(j = 0; j < i; j++) {
                if(dp[j] == -1) continue;
                if(tt - g[j].AA.AA >= abs(ss - g[j].AA.BB)) {
                    cmax(dp[i], dp[j] + pp);
                }
            } 
            cmax(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
