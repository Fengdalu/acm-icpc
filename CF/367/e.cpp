#include <bits/stdc++.h>
using namespace std;

struct node {
    int r, d;
    int w;
}f[2000000];
int cnt;
int x[2000], y[2000];
int nd[2000][2000];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            int x;
            nd[i][j] = ++cnt;
            if(i == 0 || j == 0) continue;
            if(i == n + 1 || j == m + 1) continue;
            scanf("%d", &x);
            f[cnt].w = x;
        }
    }

    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m; j++) {
            node &t = f[nd[i][j]];
            t.r = nd[i][j + 1];
        }
    }
    for(int j = 0; j <= m + 1; j++) {
        for(int i = 0; i <= n; i++) {
            node &t = f[nd[i][j]];
            t.d = nd[i + 1][j];
        }
    }
    node &t = f[nd[0][0]];
    t.r = nd[0][1];
    t.d = nd[1][0];
    while(q--) {
        int a, b, c, d, w, h; scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &h, &w);
        int p1 = nd[0][0], p2 = nd[0][0];
        for(int i = 0; i < a - 1; i++) p1 = f[p1].d; for(int i = 0; i < b - 1; i++) p1 = f[p1].r;
        for(int i = 0; i < c - 1; i++) p2 = f[p2].d; for(int i = 0; i < d - 1; i++) p2 = f[p2].r;
        int k1, k2;
        k1 = p1, k2 = p2;
        for(int i = 0; i < w; i++) {
            k1 = f[k1].r; k2 = f[k2].r;
            swap(f[k1].d, f[k2].d);
        }
        for(int i = 0; i < h; i++) {
            k1 = f[k1].d, k2 = f[k2].d;
            swap(f[k1].r, f[k2].r);
        }
        k1 = p1, k2 = p2;
        for(int i = 0; i < h; i++) {
            k1 = f[k1].d, k2 = f[k2].d;
            swap(f[k1].r, f[k2].r);
        }
        for(int i = 0; i < w; i++) {
            k1 = f[k1].r; k2 = f[k2].r;
            swap(f[k1].d, f[k2].d);
        }
    }
    for(int i = 1; i <= n; i++) {
        int k = nd[i][0];
        for(int j = 0; j < m; j++) {
            k = f[k].r;
            printf("%d ", f[k].w);
        }
        printf("\n");
    }
    return 0;
}
