#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

typedef long long ll;
const int inf = 1e9 + 7;
const int N = 200010;
int mx[N<<2], mn[N<<2];
ll sum[N<<2], add[N<<2];
int w[N];

void build(int rt, int l, int r) {
    mx[rt] = -1; mn[rt] = inf;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void down(int rt) {
    int l = rt << 1, r = rt << 1 | 1;
    cmax(mx[l], mx[rt]);
    cmax(mx[r], mx[rt]);
    cmin(mn[l], mn[rt]);
    cmin(mn[r], mn[rt]);
    mx[rt] = -1;
    mn[rt] = inf;
}

void update(int rt) {
    int l = rt << 1, r = rt << 1 | 1;
    mx[rt] = max(mx[l], mx[r]);
    mn[rt] = min(mn[l], mn[r]);
}

void deal(int rt, int i) {
    cmax(mx[rt], i);
    cmin(mn[rt], i);
}

void update(int rt, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) {
        deal(rt, w);
        return;
    }
    down(rt);
    int mid = (l + r) >> 1;
    if(b <= mid) update(rt << 1, l, mid, a, b, w);
    else if(a > mid) update(rt << 1 | 1, mid + 1, r, a, b, w);
    else {
        update(rt << 1, l, mid, a, b, w);
        update(rt << 1 | 1, mid + 1, r, a, b, w);
    }
    //update(rt);
}

int q1(int rt, int l, int r, int a) {
    if(l == r) {
        return mx[rt];
    }
    down(rt);
    int mid = (l + r) >> 1;
    if(a <= mid) return q1(rt << 1, l, mid, a);
    else return q1(rt << 1 | 1, mid + 1, r, a);
}

int q2(int rt, int l, int r, int a) {
    if(l == r) {
        return mn[rt];
    }
    down(rt);
    int mid = (l + r) >> 1;
    if(a <= mid) return q2(rt << 1, l, mid, a);
    else return q2(rt << 1 | 1, mid + 1, r, a);
}

void build2(int rt, int l, int r) {
    sum[rt] = add[rt] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build2(rt << 1, l, mid);
    build2(rt << 1 | 1, mid + 1, r);
}

void deal2(int rt, int l, int r, ll w) {
    sum[rt] += 1ll * (r - l + 1) * w;
    add[rt] += w;
}

void down2(int rt, int l, int r) {
    if(!add[rt]) return;
    int mid = (l + r) >> 1;
    deal2(rt << 1, l, mid, add[rt]);
    deal2(rt << 1 | 1, mid + 1, r, add[rt]);
    add[rt] = 0;
}

void update2(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void add2(int rt, int l, int r, int a, int b, int w) {
    if(a <= l && r <= b) {
        deal2(rt, l, r, w);
        return;
    }
    down2(rt, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) add2(rt << 1, l, mid, a, b, w);
    else if(a > mid) add2(rt << 1 | 1, mid + 1, r, a, b, w);
    else {
        add2(rt << 1, l, mid, a, b, w);
        add2(rt << 1 | 1, mid + 1, r, a, b, w);
    }
    update2(rt);
}

ll qq(int rt, int l, int r, int p) {
    if(l == r) {
        return sum[rt];
    }
    down2(rt, l, r);
    int mid = (l + r) >> 1;
    if(p <= mid) return qq(rt << 1, l, mid, p);
    return qq(rt << 1 | 1, mid + 1, r, p);
}

int run() {
    int n, m;
    int res = scanf("%d%d", &n, &m);
    if(res == -1) return res;
    build(1, 1, n - 1);
    for(int i = 1; i <= n - 1; i++) scanf("%d", &w[i]);
    for(int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        update(1, 1, n - 1, a, b - 1, i);
    }
    ll ans = 0;
    build2(1, 0, m - 1);
    for(int i = 1; i <= n - 1; i++) {
        int r = q1(1, 1, n - 1, i);
        int l = q2(1, 1, n - 1, i);
        //cout << "INT "<< l << " " << r << " " << w[i] << endl;
        if(l < 0 || r > m - 1 || l > r) continue;
        //cout << l << " " << r << " " << w[i] << endl;
        add2(1, 0, m - 1, l, r, w[i]);
    }
    //cout << "PPPP" << endl;
    for(int i = 0; i < m; i++) {
        printf("%I64d\n", qq(1, 0, m - 1, i));
    }
    return 1;
}

int main() {
    while(~run());
    return 0;
}
