#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

const int maxn = 1000010;
const int inf = 1e9;
struct point {
    int x[2];
} p[maxn];
struct node {
    int l, r, p;
    int mn[2], mx[2];
} f[maxn * 2];
int n;
int cur;
int cnt;
int mm, nn;
int operator < (const point &a, const point &b) { return a.x[cur] < b.x[cur]; }

void update(int rt) {
    int id = f[rt].p;
    int l = f[rt].l, r = f[rt].r;
    for(int i = 0; i < 2; i++) {
        f[rt].mn[i] = f[rt].mx[i] = p[id].x[i];
        if(l) cmin(f[rt].mn[i], f[l].mn[i]), cmax(f[rt].mx[i], f[l].mx[i]);
        if(r) cmin(f[rt].mn[i], f[r].mn[i]), cmax(f[rt].mx[i], f[r].mx[i]);
    }
}

int mn(int rt, point P) {
    int tot = 0;
    for(int i = 0; i < 2; i++) {
        int a = 0;
        if(P.x[i] < f[rt].mn[i]) tot += f[rt].mn[i] - P.x[i];
        else if(P.x[i] > f[rt].mx[i]) tot += -f[rt].mx[i] + P.x[i];
        tot += a;
    }
    return tot;
}

int mx(int rt, point P) {
    int tot = 0;
    for(int i = 0; i < 2; i++) {
        int a = -inf;
        cmax(a, abs(P.x[i] - f[rt].mn[i]));
        cmax(a, abs(P.x[i] - f[rt].mx[i]));
        tot += a;
    }
    return tot;
}


void build(int &rt, int l, int r, int mk) {
    if(l > r) return;
    int mid = (l + r) >> 1;
    rt = ++cnt;
    cur = mk;
    nth_element(p + l, p + mid, p + r + 1);
    //cout << p[rt].x[0] << " " << p[rt].x[1]  << " " << l << " " << r << endl;
    f[rt].p = mid;
    f[rt].l = f[rt].r = 0;
    build(f[rt].l, l, mid - 1, mk ^ 1);
    build(f[rt].r, mid + 1, r, mk ^ 1);
    update(rt);
}

int getdis(point &x, point &y) {
    int ans = 0;
    for(int i = 0; i < 2; i++) ans += abs(x.x[i] - y.x[i]);
    return ans;
}

void dfs1(int rt, point &P, int cur, int &m) {
    int l = f[rt].l, r = f[rt].r;
    point &t = p[f[rt].p];
    int tot = getdis(t, P);
    if(tot != 0) cmin(m, tot);
    int a = mn(l, P), b = mn(r, P);
    if(a < b) {
        if(l) if(m > a) dfs1(f[rt].l, P, cur ^ 1, m);
        if(r) if(m > b) dfs1(f[rt].r, P, cur ^ 1, m);
    }
    else {
        if(r) if(m > b) dfs1(f[rt].r, P, cur ^ 1, m);
        if(l) if(m > a) dfs1(f[rt].l, P, cur ^ 1, m);
    }
}

void dfs2(int rt, point &P, int cur, int &m) {
    int l = f[rt].l, r = f[rt].r;
    point &t = p[f[rt].p];
    cmax(m, getdis(t, P));
    int a = mx(l, P), b = mx(r, P);
    if(a > b) {
        if(l) if(m < a) dfs2(f[rt].l, P, cur ^ 1, m);
        if(r) if(m < b) dfs2(f[rt].r, P, cur ^ 1, m);
    }
    else {
        if(r) if(m < b) dfs2(f[rt].r, P, cur ^ 1, m);
        if(l) if(m < a) dfs2(f[rt].l, P, cur ^ 1, m);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &p[i].x[0], &p[i].x[1]);
    int root;
    build(root, 0, n - 1, 0);
    int ans = 1e9;
    cur = 0;
    cnt = 0;
    for(int i = 0; i < n; i++) {
        int mx = 0, mn = inf;
        dfs2(root, p[i], 0, mx); dfs1(root, p[i], 0, mn);
        cmin(ans, mx - mn);
    }
    printf("%d\n", ans);
    return 0;
}
