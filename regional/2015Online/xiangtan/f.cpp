#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200000;
const int inf = 1e9 + 7;
int f[maxn * 4], g[maxn * 4], pls[maxn * 4];

void update(int x) {
    f[x] = min(f[x * 2], f[x * 2 + 1]);
    g[x] = max(g[x * 2], g[x * 2 + 1]);
}

void cmax(int &a, int b) {
    a = max(a, b);
}

void cmin(int &a, int b) {
    a = min(a, b);
}

void add(int x, int w) {
    f[x] += w;
    g[x] += w;
    pls[x] += w;
}


void down(int x) {
    int l = x * 2, r = l + 1;
    add(l, pls[x]);
    add(r, pls[x]);
    pls[x] = 0;
    cmax(g[l], f[x]);
    cmax(g[r], f[x]);
    cmax(f[l], f[x]);
    cmax(f[r], f[x]);

    cmin(g[l], g[x]);
    cmin(g[r], g[x]);
    cmin(f[l], g[x]);
    cmin(f[r], g[x]);
}

void build(int x, int a, int b) {
    if(a < b) {
        int mid = (a + b) / 2;
        build(x * 2, a, mid);
        build(x * 2 + 1, mid + 1, b);
        update(x);
    }
    else {
        scanf("%d", &f[x]);
        g[x] = f[x];
    }
}

void op1(int x, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) add(x, w);
    else {
        down(x);
        int mid = (l + r) / 2;
        if(b <= mid) op1(x * 2, l, mid, a, b, w);
        else if(a > mid) op1(x * 2 + 1, mid + 1, r, a, b, w);
        else {
            op1(x * 2, l, mid, a, b, w);
            op1(x * 2 + 1, mid + 1, r, a, b, w);
        }
        update(x);
    }
}

void op2(int x, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) {
        cmax(f[x], w);
        cmax(g[x], w);
    }
    else {
        down(x);
        int mid = (l + r) / 2;
        if(b <= mid) op2(x * 2, l, mid, a, b, w);
        else if(a > mid) op2(x * 2 + 1, mid + 1, r, a, b, w);
        else {
            op2(x * 2, l, mid, a, b, w);
            op2(x * 2 + 1, mid + 1, r, a, b, w);
        }
        update(x);
    }
}

void op3(int x, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) {
        cmin(f[x], w);
        cmin(g[x], w);
    }
    else {
        down(x);
        int mid = (l + r) / 2;
        if(b <= mid) op3(x * 2, l, mid, a, b, w);
        else if(a > mid) op3(x * 2 + 1, mid + 1, r, a, b, w);
        else {
            op1(x * 2, l, mid, a, b, w);
            op1(x * 2 + 1, mid + 1, r, a, b, w);
        }
        update(x);
    }
}

pair<int, int> cal(int x, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) {
        return make_pair(f[x], g[x]);
    }
    else {
        down(x);
        int mid = (l + r) / 2;
        if(a <= mid) return cal(x * 2, l, mid, a, b, w);
        else if(b > mid) return cal(x * 2 + 1, mid + 1, r, a, b, w);
        else {
            pair<int, int>p, q;
            p = cal(x * 2, l, mid, a, b, w);
            q = cal(x * 2 + 1, mid + 1, r, a, b, w);
            cmin(p.first, q.first);
            cmax(p.second, q.second);
            return p;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
    }
    return 0;
}
