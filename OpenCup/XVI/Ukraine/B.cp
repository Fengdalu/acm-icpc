#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>


const int maxn = 200000;
const int maxnode = 4 * 2 * 1000000 + 100;
struct st {
    struct {
        int l, r;
        int sum;
    }f[maxnode];
    int root;
    int cnt;
    int build(int l, int r) {
        int cur = cnt++;
        f[cur].sum = 0;
        if(l < r) {
            int mid = (l + r) / 2;
            f[cur].l = build(l, mid);
            f[cur].r = build(mid + 1, r);
        }
        return cur;
    }
    void update(int cur) {
        f[cur].sum = f[f[cur].l].sum + f[f[cur].r].sum;
    }
    void insert(int cur, int l, int r, int p) {
        if(l == r) {
            f[cur].sum++;
        }
        else {
            int mid = (l + r) / 2;
            if(p <= mid) insert(f[cur].l, l, mid, p);
            else insert(f[cur].r, mid + 1, r, p);
            update(cur);
        }
    }

    int query(int cur, int l, int r, int a, int b) {
        if(a <= l && r <= b) {
            return f[cur].sum;
        }
        else {
            int mid = (l + r) / 2;
            if(b <= mid) return query(f[cur].l, l, mid, a, b);
            else if(a > mid) return query(f[cur].r, mid + 1, r, a, b);
            else return query(f[cur].l, l, mid, a, b) + query(f[cur].r, mid + 1, r, a, b);
        }
    }
}t;

int n, m;
int a[maxn], b[maxn];
int x[maxn], y[maxn];
int p;
int h[maxn];
int cnt;
long long cal() {
    t.cnt = 0;
    t.root = t.build(0, 4 * n);
    long long tot = 0;
    cnt = 0;
    for(int i = 0; i < p; i++) h[cnt++] = y[i] - x[i];
    std::sort(h, h + cnt);
    cnt = std::unique(h, h + cnt) - h;
    for(int i = 0; i < cnt; i++) {
        t.insert(t.root, 0, 4 * n, 2 * n + h[i]);
        tot += (long long)n - (long long)std::abs(h[i]);
    }
    int tot1 = 0;
    cnt = 0;
    for(int i = 0; i < p; i++) h[cnt++] = x[i] + y[i];
    std::sort(h, h + cnt);
    cnt = std::unique(h, h + cnt) - h;
    for(int i = 0; i < cnt; i++) {
        tot += (long long)n - (long long)std::abs(h[i] - n - 1);
        if(h[i] > n + 1) h[i] = n + 1 - (h[i] - n - 1);
        int tmp = t.query(t.root, 0, 4 * n, 2 * n - h[i] + 1, 2 * n + h[i] - 1);
        tot -= (long long)tmp;
    }
    return tot;
}

int main() {
    //freopen("B.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d%d", &a[i], &b[i]);
    p = 0;
    long long ans = 0;
    for(int i = 0; i < m; i++)
    if((a[i] + b[i]) & 1) {
        x[p] = a[i];
        y[p] = b[i];
        p++;
    }
    ans += cal();
    p = 0;
    for(int i = 0; i < m; i++)
    if(((a[i] + b[i]) & 1) == 0) {
        x[p] = a[i];
        y[p] = b[i];
        p++;
    }
    ans += cal();
    std::cout << (long long)n * (long long)n - (long long)ans << std::endl;
    return 0;
}
