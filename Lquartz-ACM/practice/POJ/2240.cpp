#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define Maxn 33
#define Maxm 3000
int n, m;
map<string, int> mp;
double g[Maxn][Maxn];
char ch[100];
int main() {
    int i, j, k, u, v, ca = 0;
    double w;
    while(scanf("%d", &n) != EOF && n) {
        mp.clear();
        for(i = 1; i <= n; i++) {
            scanf("%s", ch);
            mp[string(ch)] = i;
            for(j = 1; j <= n; j++) {
                g[i][j] = -1;
            }
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++) {
            scanf("%s", ch);
            u = mp[string (ch)];
            scanf("%lf", &w);
            scanf("%s", ch);
            v = mp[string (ch)];
            g[u][v] = w;
        }
        #define cmax(x,y) x=max(x,y)
        for(k = 1; k <= n; ++k) {
            for(i = 1; i <= n; ++i) {
                if(g[i][k] > 0) {
                    for(j = 1; j <= n; ++j) {
                        if(g[k][j] > 0) {
                            cmax(g[i][j], g[i][k] * g[k][j]);
                        }
                    }
                }
            }
        }
        int flag = 0;
        for(i = 1; i <= n; i++) {
            if(g[i][i] > 1) flag = 1;
        }
        ca++;
        if(flag) printf("Case %d: Yes\n", ca);
        else printf("Case %d: No\n", ca);
    }
    return 0;
}
