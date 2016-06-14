#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmax(x, y) x = max(x, y)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
const ll inf = (ll)1e20;

typedef pair<int, int> pii;
const int maxn = 300010;
ll q[maxn];
int op[maxn], ed[maxn];
pii e[maxn];
pii g[maxn * 4];
int nt[maxn * 2], ind[maxn * 2];
int qry[maxn];
ll ans[maxn];
int n, m, cnt;
pii buf[maxn];
int tot;

void insert(int x, int l, int r, int a, int b, pii t) {
    if(a <= l && r <= b) {
        g[cnt] = t;
        nt[cnt] = ind[x];
        ind[x] = cnt++;
    }
    else {
        int mid = (l + r) / 2;
        if(a <= mid) insert(x * 2, l, mid, a, b, t);
        if(b > mid) insert(x * 2 + 1, mid + 1, r, a, b, t);
    }
}


int cmp(pii a, pii b) {
    if(a.first == b.first) return a.second > b.second;
    return (ll)a.second * b.first - (ll)a.first * b.second > 0;
}

ll f(pii v, ll q) { return v.first * q + v.second; }

void cal(int pos) {
    ll v = q[pos];
    int l = 0, r = tot - 1;
    while(l < r - 2) {
        int mid = (l + r) / 2;
        int midmid = (l + mid) / 2;
        ll a = f(buf[midmid], v), b = f(buf[mid], v);
        if(a < b) l = midmid;
        else r = mid;
    }
    for(int i = l; i <= r; i++)
        cmax(ans[pos], f(buf[i], v));
}


void dfs(int x, int l, int r) {
    if(l < r) {
        int mid = (l + r) / 2;
        dfs(x * 2, l, mid);
        dfs(x * 2 + 1, mid + 1, r);
    }
    tot = 0;
    for(int k = ind[x]; k != -1; k = nt[k]) {
        buf[tot++] = g[k];
    }
    sort(buf, buf + tot, cmp);
    if(tot == 0) return;
    for(int i = l; i <= r; i++) {
        cal(i);
    }
}

int main() {
    scanf("%d", &n);
    memset(op, -1, sizeof op);
    for(int i = 1; i <= n; i++) {
        int k, x, y; scanf("%d", &k);
        if(k == 1) {
            scanf("%d%d", &x, &y);
            e[i] = mp(x, y);
            op[i] = i;
            ed[i] = n;
        }
        else if(k == 2) {
            scanf("%d", &x);
            ed[x] = i;
        }
        else if(k == 3) {
            scanf("%d", &x);
            q[i] = x;
            qry[m++] = i;
        }
    }
    cnt = 0;
    memset(ind, -1, sizeof ind);
    for(int i = 1; i <= n; i++)
    if(op[i] != -1) {
        insert(1, 1, n, op[i], ed[i], e[i]);
    }
    for(int i = 1; i <= n; i++) ans[i] = -inf;
    dfs(1, 1, n);
    for(int i = 0; i < m; i++)
    if(ans[qry[i]] != -inf) {
        printf("%lld\n", ans[qry[i]]);
    }
    else printf("EMPTY SET\n");
    return 0;
}
