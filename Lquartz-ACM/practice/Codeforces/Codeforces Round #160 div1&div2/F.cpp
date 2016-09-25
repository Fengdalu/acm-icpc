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

#define Maxn 5111
#define Maxm 111111

vector<int> g, have;
int te, n, maxb, t;
int mmp[Maxm];
PII dp[Maxn][Maxn];

int main() {
    int i, j, k, u, v, w;
    while(scanf("%d%d%d%d", &te, &n, &maxb, &t) != EOF) {
        while(te--) {
            g.clear();
            have.clear();
            for(i = 0; i < n; i++) {
                scanf("%d", &w);
                g.PB(w);
                have.PB(w);
            }
            sort(have.BG, have.ED);
            have.erase(unique(have.BG, have.ED), have.ED);
            //for(i = 0; i < have.SZ; i++) printf("%d ", have[i]); printf("\n");
            for(i = 0; i < have.SZ; i++) {
                mmp[have[i]] = i + 1;
            }
            //for(i = 0; i < 10; i++) printf("%d ", mmp[i]); printf("\n");
            for(i = 0; i < n; i++) {
                g[i] = mmp[g[i]];
            }
            //for(i = 0; i < n; i++) printf("%d ", g[i]); printf("\n");
            for(i = 0; i <= have.SZ; i++) {
                for(j = 0; j <= have.SZ; j++) {
                    dp[i][j] = MP(t + 2, n + 2);
                }
            }
            for(i = 0; i < n; i++) {
                cmin(dp[1][g[i]], MP(0, i));
            }
            for(i = 2; i <= have.SZ; i++) {
                for(j = 2; j <= have.SZ; j++) {
                    cmin(dp[i - 1][j], dp[i - 1][j - 1]);
                }
                for(j = 0; j < n; j++) {
                    PII p = dp[i - 1][g[j] - 1];
                    if(p.BB >= j) {
                        cmin(dp[i][g[j]], MP(p.AA + 1, j));
                    }
                    else {
                        cmin(dp[i][g[j]], MP(p.AA, j));
                    }
                }
            }
            int ans = -1;
            for(i = 1; i <= have.SZ; i++) {
                for(j = 0; j <= have.SZ; j++) {
                    //printf("(%d, %d) ", dp[i][j].AA, dp[i][j].BB);
                }
                //printf("\n");
            }
            for(i = have.SZ; i >= 1; i--) {
                for(j = 0; j <= have.SZ; j++) {
                    if(dp[i][j].AA < t) {
                        ans = i;
                        break;
                    }
                }
                if(ans != -1) break;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
