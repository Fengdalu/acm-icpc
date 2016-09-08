#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
#define MP make_pair

const int N = 300010;
const int MX = 3e3+5;
typedef long long ll;
struct BIT {
    int _[MX+20][MX+20];
    void init() {
        memset(_, 0, sizeof _);
    }
    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int y) {
        while(x < MX+10) {
            int _k = y;
            while(_k < MX+10) {
                _[x][_k]++;
                _k += lowbit(_k);
            }
            x += lowbit(x);
        }
    }

    int cal(int x, int y) {
        int ans = 0;
        while(x) {
            int _k = y;
            while(_k) {
                ans += _[x][_k];
                _k -= lowbit(_k);
            }
            x -= lowbit(x);
        }
        return ans;
    }
} T;
struct state {
    int a, c, d, e;
    state(int _a, int _c, int _d, int _e) : a(_a), c(_c), d(_d), e(_e) {}
    state(){}
    int operator <  (const state &s) const {
        if(d == s.d) return MP(a, c) > MP(s.a, s.c);
        return d > s.d;
    }
    int operator == (const state &s) const {
        return MP(a, MP(c, d)) == MP(s.a, MP(s.c, s.d));
    }
} f[N];

int me[N];
int c[N];
inline void run(int MXT) {
    static int _t = 0;
    memset(me, -1, sizeof me);
    memset(c, 0, sizeof c);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        if(a > me[b]) {
            me[b] = a;
            c[b] = 0;
        }
        if(a == me[b]) c[b]++;
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int c, d, e;
        scanf("%d%d%d", &c, &d, &e);
        if(me[e] == -1) continue;
        f[cnt++] = state(c, d, me[e], e);
    }
    T.init();
    sort(f, f + cnt);
    ll ans = 0;
    int pre = 0;
    int tot = 0;
    for(int i = 0; i < cnt; i++) {
        int Y = f[i].a, X = f[i].c;
        if(i != 0 && f[i] == f[i - 1]) {
            if(pre) ans += 1ll * c[f[i].e];
        }
        else {
            int cover = T.cal(MX, MX) - T.cal(MX, Y) - T.cal(X, MX) + T.cal(X, Y);
            //ll cover = T.cal(MX - X, MX - Y);
            if(cover == 0) { ans += 1ll * c[f[i].e]; pre = 1; }
            else pre = 0;
        }
        //T.add(MX - X, MX - Y);
        T.add(X + 1, Y + 1);
    }
    printf("Case #%d: %lld\n", ++_t, ans);
}

int main() {
    int _t; scanf("%d", &_t);
    while(_t--) run(_t);
    return 0;
}

