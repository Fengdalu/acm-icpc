#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define LL long long
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()

struct obj {
    int a, b;
    int c;
};
const int Maxn = 201000;
vector<obj>H, P, T;
vector<obj>Q;
vector<int>X;
int c[Maxn];
int n;

int lowbit(int x) {return x & (-x);}
void add(int x, int v) {
    while(x < Maxn) {
        c[x] += v;
        x += lowbit(x);
    }
}

int cal(int x) {
    int tot = 0;
    while(x) {
        tot += c[x];
        x -= lowbit(x);
    }
    return tot;
}

int cmp1(obj x, obj y) {
    if(x.c == y.c) return x.a < y.a;
    return x.c < y.c;
}

int cmp2(obj x, obj y) {
    return x.a < y.a;
}

int pos(int x) {
    return lower_bound(X.OP, X.ED, x) - X.OP + 1;
}

int main() {
    cin >> n;
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        X.PB(a); X.PB(x);
        obj t;
        if(b == y) {
            t.a = min(a, x);
            t.b = max(a, x);
            t.c = b;
            H.PB(t);
        }
        else {
            t.a = min(b, y);
            t.b = max(b, y);
            t.c = a;
            P.PB(t);
        }
    }
    sort(X.OP, X.ED);
    X.resize(unique(X.OP, X.ED) - X.OP);
    sort(H.OP, H.ED, cmp1);
    sort(P.OP, P.ED, cmp1);

    int R = -1;
    for(int i = 0; i < H.SZ; i++) {
        if(i != 0 && H[i].c == H[i - 1].c && H[i].b <= R) continue;
        if(i != 0 && H[i].c == H[i - 1].c) {
            H[i].a = max(H[i].a, R + 1);
            R = max(H[i].b, R);
        }
        else R = H[i].b;
        T.PB(H[i]);
    }
    swap(T, H);
    T.clear();

    R = -1;
    for(int i = 0; i < P.SZ; i++) {
        if(i != 0 && P[i].c == P[i - 1].c && P[i].b <= R) continue;
        if(i != 0 && P[i].c == P[i - 1].c) {
            P[i].a = max(P[i].a, R + 1);
            R = max(P[i].b, R);
        }
        else R = P[i].b;
        T.PB(P[i]);
    }
    swap(P, T);
    for(int i = 0; i < P.SZ; i++) {
        obj t;
        t.a = P[i].a;
        t.b = P[i].c;
        t.c = 1;
        Q.PB(t);

        t.a = P[i].b + 1;
        t.b = P[i].c;
        t.c = -1;
        Q.PB(t);
    }

    sort(Q.OP, Q.ED, cmp2);
    int J = 0;
    R = -1;
    for(int i = 0; i < H.SZ; i++) {
        while(J < Q.SZ && Q[J].a <= H[i].c) {
            add(pos(Q[J].b), Q[J].c);
            J++;
        }
        ans -= cal(pos(H[i].b)) - cal(pos(H[i].a) - 1);
    }
    for(int i = 0; i < P.SZ; i++) ans += P[i].b - P[i].a + 1;
    for(int i = 0; i < H.SZ; i++) ans += H[i].b - H[i].a + 1;
    cout << ans << endl;
    return 0;
}

