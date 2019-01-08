/*
 * Poj 3481
 */
#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>

const int N = 1000000+1000, MOD = 1e9+7;
const int nil = 0;
struct node {
    int ch[2], key, sz;
    PII data;
} f[N];
int cnt, rt;

void up(int cur) {
    f[cur].sz = f[f[cur].ch[0]].sz + f[f[cur].ch[1]].sz + 1;
}

int newNode(PII data) {
    cnt++;
    f[cnt].ch[0] = f[cnt].ch[1] = 0;
    f[cnt].data = data;
    f[cnt].sz = 1;
    f[cnt].key = rand();
    return cnt;
}

PII split(int p, int n) {
    if(n == 0) return MP(nil, p);
    int sz = f[f[p].ch[0]].sz;
    if(n == sz) {
        int x = f[p].ch[0];
        f[p].ch[0] = nil;
        up(p);
        return MP(x, p);
    }
    else if(n == sz + 1) {
        int x = f[p].ch[1];
        f[p].ch[1] = nil;
        up(p);
        return MP(p, x);
    }
    else if(n < sz) {
        PII res = split(f[p].ch[0], n);
        f[p].ch[0] = res.BB;
        up(p);
        return MP(res.AA, p);
    }
    else {
        PII res = split(f[p].ch[1], n - sz - 1);
        f[p].ch[1] = res.AA;
        up(p);
        return MP(p, res.BB);
    }
}

int merge(int p, int q) {
    if(p == nil) return q;
    if(q == nil) return p;
    if(f[p].key > f[q].key) {
        f[q].ch[0] = merge(p, f[q].ch[0]);
        up(q);
        return q;
    }
    else {
        f[p].ch[1] = merge(f[p].ch[1], q);
        up(p);
        return p;
    }
}

int getrank(int p, int w) {
    int ans = 0;
    while(p != nil) {
        if(w == f[p].data.BB) return ans + f[f[p].ch[0]].sz;
        if(w < f[p].data.BB) p = f[p].ch[0];
        else {
            ans += f[f[p].ch[0]].sz + 1;
            p = f[p].ch[1];
        }
    }
    return ans;
}
