#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

const int Maxn = 1000010;
int Hash[Maxn], cnt;
int lowbit(int x) { return x & (-x); }
struct bit {
    LL c[Maxn];
    LL query(int x) {
        LL tot = 0;
        while(x > 0) {
            tot += c[x];
            x -= lowbit(x);
        }
        return tot;
    }

    void add(int x, int v) {
        while(x < Maxn) {
            c[x] += v;
            x += lowbit(x);
        }
    }

    void init() {
        memset(c, 0, sizeof c);
    }
}b1, b2;
int n, m;
int op[Maxn], v[Maxn];
LL ans[Maxn];
LL cur;
int Q[Maxn];



int main() {
    scanf("%d%d", &n, &m);
    cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &Q[i]);
        Hash[cnt++] = Q[i];
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &op[i]);
        if(op[i] == 3) continue;
        scanf("%d", &v[i]);
        Hash[cnt++] = v[i];
    }
    sort(Hash, Hash + cnt);
    cnt = unique(Hash, Hash + cnt) - Hash;
    b1.init();
    b2.init();
    cur = 0;
    for(int i = 0; i < n; i++) {
        int pos = lower_bound(Hash, Hash + cnt, Q[i]) - Hash + 1;
        LL cc, sum;
        cc = b1.query(pos);
        sum = b2.query(pos);
        cur += cc * Q[i] - sum;

        cc = b1.query(cnt) - b1.query(pos);
        sum = b2.query(cnt) - b2.query(pos);
        cur += sum - cc * Q[i];
        b1.add(pos, 1);
        b2.add(pos, Q[i]);
    }
    for(int i = 0; i < m; i++) {
        if(op[i] == 3) printf("%I64d\n", cur);
        else if(op[i] == 1) {
            int pos = lower_bound(Hash, Hash + cnt, v[i]) - Hash + 1;
            LL cc, sum;
            cc = b1.query(pos);
            sum = b2.query(pos);
            cur += cc * v[i] - sum;

            cc = b1.query(cnt) - b1.query(pos);
            sum = b2.query(cnt) - b2.query(pos);
            cur += sum - cc * v[i];
            b1.add(pos, 1);
            b2.add(pos, v[i]);
        }
        else if(op[i] == 2) {
            int pos = lower_bound(Hash, Hash + cnt, v[i]) - Hash + 1;
            if(b1.query(pos) - b1.query(pos - 1) == 0) { puts("-1"); continue; }
            LL cc, sum;
            cc = b1.query(pos);
            sum = b2.query(pos);
            cur -= cc * v[i] - sum;

            cc = b1.query(cnt) - b1.query(pos);
            sum = b2.query(cnt) - b2.query(pos);
            cur -= sum - cc * v[i];
            b1.add(pos, -1);
            b2.add(pos, -v[i]);
        }
    }
    return 0;
}
