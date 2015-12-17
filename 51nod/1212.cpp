#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
const int Maxn = 1001;
const int Maxm = 50010;

struct obj {
    int a, b, c;
}f[Maxm];
int fa[Maxn];
int n, m;

int find(int x) {
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void Union(int x, int y) {
    fa[find(x)] = find(y);
}

int cmp(obj a, obj b) {
    return a.c < b.c;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d%d%d", &f[i].a, &f[i].b, &f[i].c);
    sort(f, f + m, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    int ans = 0;
    for(int i = 0; i < m; i++) if(find(f[i].a) != find(f[i].b)) {
        ans += f[i].c;
        Union(f[i].a, f[i].b);
    }
    printf("%d\n", ans);
    return 0;
}
