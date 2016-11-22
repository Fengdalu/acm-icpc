#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>

struct obj {
    int a, b;
    int c, d;
    int id;
}f[100100];
int fa[100100];
set<PII>s;
int n, m;

int find(int x) {
    if(fa[x] == x) return fa[x];
    fa[x] = find(fa[x]);
    return fa[x];
}

int Union(int x, int y) {
    return fa[find(x)] = find(y);
}

int cmp1(obj a, obj b) {
    if(a.c == b.c) return a.d > b.d;
    return a.c < b.c;
}

int cmp2(obj a, obj b) {
    return a.id < b.id;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        f[i].id = i;
        scanf("%d%d", &f[i].c, &f[i].d);
    }
    sort(f, f + m, cmp1);
    for(int i = 1; i <= n; i++) fa[i] = i;
    int b = 3, t = 2;
    int q = 2;
    for(int i = 0; i < m; i++) {
        if(f[i].d == 0) {
            if(b > n || find(b) != find(t)) {
                puts("-1"); return 0;
            }
            f[i].a = b; f[i].b = t;
            t++;
            if(t == b) { b++; t = 2; }
        }
        else {
            if(q <= n) {
                f[i].a = 1;
                f[i].b = q;
                Union(1, q);
                q++;
            }
            else {
                puts("-1");
                return 0;
            }
        }
    }
    sort(f, f + m, cmp2);
    for(int i = 0; i < m; i++) {
        printf("%d %d\n", f[i].a, f[i].b);
    }
    return 0;
}
