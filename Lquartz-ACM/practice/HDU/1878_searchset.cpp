#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1111
int n, m;
int fa[Maxn], deg[Maxn];
int getfa(int x) {
    if(fa[x] == x) return x;
    else return (fa[x] = getfa(fa[x]));
}
int main() {
    int i, j, u, v;
    while(scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        for(i = 1; i <= n; i++) {
            deg[i] = 0;
            fa[i] = i;
        }
        int cnt = 0;
        for(i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            deg[u]++, deg[v]++;
            int x = getfa(u), y = getfa(v);
            if(x != y) {
                if(x < y)
                    fa[x] = y;
                else fa[y] = x;
                cnt++;
            }
        }
        if(cnt < n - 1) {
            printf("0\n");
        }
        else {
            for(i = 1; i <= n; i++) {
                if(deg[i] & 1) break;
            }
            if(i > n) printf("1\n");
            else printf("0\n");
        }

    }
    return 0;
}
