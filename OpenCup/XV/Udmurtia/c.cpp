#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

long double ans[12][200];
long double f[200], g[200];
int a[100];
int n;
char buf[100];
bool vis[100];
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int ii = 0; ii < n; ii++) {
        int m, cnt;
        scanf("%d%d", &cnt, &m);
        memset(vis, 0, sizeof vis);
        for(int j = 0; j < m; j++) {
            scanf("%s", buf);
            if(buf[0] == '+') vis[j] = true;
            sscanf(buf, "%d", &a[j]);
        }
        memset(f, 0, sizeof f);
        f[0] = 1.0;
        for(int i = 0; i < cnt; i++) {
            memset(g, 0, sizeof g);
            for(int k = 0; k <= 120; k++) {
                for(int j = 0; j < m; j++) if(vis[j] && j + a[j] <= 120){
                        f[k + a[j]] += f[k] * 1.0 / m;
                    }
                }
            for(int j = 0; j < m; j++) {
                if(!vis[j]) {
                    for(int k = 0; k + a[j] <= 120; k++)
                        g[k + a[j]] += f[k] * 1.0 / m;
                }
            }
            swap(f, g);
        }
        long double tot = 0;
        for(int i = 0; i <= 120; i++) {
            tot += f[i];
            ans[ii][i] = tot;
        }
    }

    int q; scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int p = 0;
        for(int j = 0; j < n; j++)
        if(ans[j][i] < ans[p][i]) p = j;
        printf("%d\n", p + 1);
    }
    return 0;
}
