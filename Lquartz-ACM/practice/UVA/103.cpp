#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define PB push_back
#define BG begin()
#define ED end()
#define SZ size()
#define Maxn 44
#define Maxm 14
vector<int> g[Maxn];
vector<int> ans;
int n, m;
int checkin(int a, int b) {
    int j;
    for(j = 0; j < m; j++) {
        if(g[a][j] >= g[b][j]) return false;
    }
    return true;
}
int dp[Maxn], pre[Maxn];
int main() {
    int i,j,u,v,w;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            g[i].clear();
            for(j = 0; j < m; j++) {
                scanf("%d", &v);
                g[i].PB(v);
            }
            sort(g[i].BG, g[i].ED);
            g[i].PB(i);
        }
        sort(g, g + n);
        for(i = 1; i <= n; i++) {
            dp[i] = 1;
            pre[i] = -1;
        }
        dp[0] = 0; pre[0] = -1;
        for(i = 2; i <= n; i++) {
            for(j = 1; j < i; j++) {
                if(checkin(j, i)) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }
        int dmax = 0, u = 0;
        for(i = 1; i <= n; i++) {
            if(dmax < dp[i]) {
                dmax = dp[i];
                u = i;
            }
        }
        printf("%d\n", dmax);
        ans.clear();
        while(u > 0) {
            ans.PB(g[u][m]);
            u = pre[u];
        }
        reverse(ans.BG, ans.ED);
        for(i = 0; i < ans.SZ; i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
