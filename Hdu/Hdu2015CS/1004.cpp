#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define LL long long

struct node {
    int a, b;
    int c;
}e[100010];

int cmp(node a, node b) {
    return a.c > b.c;
}

int fa[200];

int find(int x) {
    if(fa[x] == x) return fa[x];
    fa[x] = find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
            int v; scanf("%d", &v);
            if(i < j) {
                e[cnt].a = i;
                e[cnt].b = j;
                e[cnt].c = v;
                cnt++;
            }
        }
        for(int i = 1; i <= n; i++) fa[i] = i;
        sort(e, e + cnt, cmp);
        LL ans = 0;
        for(int i = 0; i < cnt; i++) if(find(e[i].a) != find(e[i].b)) {
            ans += e[i].c;
            Union(e[i].a, e[i].b);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
