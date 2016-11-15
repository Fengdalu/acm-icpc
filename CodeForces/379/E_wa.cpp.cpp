#include <bits/stdc++.h>

const int N = 2e5+1000;
int fa[N], c[N];

int get(int x) {
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", c + i);
    for(int i = 0; i < n; i++) fa[i] = i;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        if(c[u] == c[v]) fa[get(u)] = get(v);
    }
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) if(get(i) == i) {
        if(c[i]) a++; else b++;
    }
    printf("%d\n", std::min(a, b));
    return 0;
}
