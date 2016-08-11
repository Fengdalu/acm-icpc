#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 100020;
ll eq[N << 2], sum[N << 2], add[N << 2];

void update(int rt) {
    sum[rt] = sum[rt << 1 | 1] + sum[rt << 1];
    eq[rt] = (eq[rt << 1] == eq[rt << 1 | 1]) ? eq[rt << 1] : -1;
}

void deal(int rt, int a, int b, ll c) {
    sum[rt] += 1ll * (b - a + 1) * c;
    add[rt] += c;
    if(eq[rt] != -1) eq[rt] += c;
}

void down(int rt, int a, int b) {
    int l = rt << 1, r = rt << 1 | 1;
    int mid = (a + b) >> 1;
    if(add[rt]) {
        deal(l, a, mid, add[rt]);
        deal(r, mid + 1, b, add[rt]);
        add[rt] = 0;
    }
    if(~eq[rt]) {
        sum[l] = eq[rt] * (mid - a + 1); sum[r] = sum[rt] - sum[l];
        add[l] = add[r] = 0;
        eq[l] = eq[r] = eq[rt];
    }
}

void build(int rt, int l, int r) {
    add[rt] = 0;
    if(l == r) {
        scanf("%lld", &sum[rt]);
        eq[rt] = sum[rt];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid); build(rt << 1 | 1, mid + 1, r);
    update(rt);
}

ll cal(int rt, int l, int r, int a, int b) {
    if(a <= l && r <= b) {
        return sum[rt];
    }
    down(rt, l, r); int mid = (l + r) >> 1;
    if(b <= mid) return cal(rt << 1, l, mid, a, b);
    else if(a > mid) return cal(rt << 1 | 1, mid + 1, r, a, b);
    else return cal(rt << 1, l, mid, a, b) + cal(rt << 1 | 1, mid + 1, r, a, b);
}

void pls(int rt, int l, int r, int a, int b, ll c) {
    if(a <= l && r <= b)  {
        deal(rt, l, r, c);
        return;
    }
    down(rt, l, r); int mid = (l + r) >> 1;
    if(b <= mid) pls(rt << 1, l, mid, a, b, c);
    else if(a > mid) pls(rt << 1 | 1, mid + 1, r, a, b, c);
    else pls(rt << 1, l, mid, a, b, c), pls(rt << 1 | 1, mid + 1, r, a, b, c);
    update(rt);
}

void SQRT(int rt, int l, int r, int a, int b) {
    if(a <= l && r <= b)  {
        if(eq[rt] != -1) {
            eq[rt] = (ll)sqrt(eq[rt]);
            sum[rt] = 1ll * (r - l + 1) * eq[rt];
            return ;
        }
    }
    down(rt, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) SQRT(rt << 1, l, mid, a, b);
    else if(a > mid) SQRT(rt << 1 | 1, mid + 1, r, a, b);
    else SQRT(rt << 1, l, mid, a, b), SQRT(rt << 1 | 1, mid + 1, r, a, b);
    update(rt);
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        int n, m; scanf("%d%d", &n, &m);
        build(1, 1, n);
        for(int i = 0; i < m; i++) {
            int op, l, r; scanf("%d%d%d", &op, &l, &r);
            if(op == 1) { ll c; scanf("%lld", &c); pls(1, 1, n, l, r, c);  }
            else if(op == 2) SQRT(1, 1, n, l, r);
            else printf("%lld\n", cal(1, 1, n, l, r));
        }
    }
    return 0;
}
