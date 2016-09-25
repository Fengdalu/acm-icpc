#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 100100
int deg[Maxn], node[Maxn], cnt[Maxn], fa[Maxn];
int n, m;

int getfa(int x) {
    if(fa[x] == x) return x;
    else return (fa[x] = getfa(fa[x]));
}

int main() {
    int i, j, u, v, x, y;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            cnt[i] = 0; node[i] = 1; fa[i] = i;deg[i] = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            deg[u] ^= 1; deg[v] ^= 1;
            x = getfa(u); y = getfa(v);
            if(x != y) {
                fa[y] = x;
                node[x] += node[y];
            }
        }
        int ans = 0;
        for(i = 1; i <= n; i++) {
            if(deg[i] & 1) cnt[getfa(i)]++;
        }
        for(i = 1; i <= n; i++) {
            u = getfa(i);
            if(u == i) {
                if(node[u] > 1) {
                    if(cnt[u] > 0) {
                        ans += cnt[u] / 2;
                    }
                    else {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
