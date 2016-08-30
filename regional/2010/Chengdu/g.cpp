#include <iostream>
#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 500;
const int M = 2e6;
int ind[N];
int to[M], nt[M];
int dfn[N], low[N];
int color[N];
bool vis[N];
int cnt, num, idn;
int ncnt;
stack<int>s;

void add(int i, int j) {
    cnt++;
    to[cnt] = j;
    nt[cnt] = ind[i];
    ind[i] = cnt;
}

void tarjan(int x) {
    if(dfn[x] != 0) return;
    low[x] = dfn[x] = ++num;
    vis[x] = true;
    s.push(x);
    for(int k = ind[x]; k != -1; k = nt[k]) {
        tarjan(to[k]);
        if(vis[to[k]]) low[x] = min(low[x], low[to[k]]);
    }
    if(dfn[x] == low[x]) {
        ncnt++;
        while(true) {
            int p = s.top();
            s.pop();
            color[p] = ncnt;
            vis[p] = false;
            if(p == x) break;
        }
    }
}

const int Maxn = 500;
const int Maxm = 50000;
int n, m;
int a[Maxm], b[Maxm], c[Maxm];

bool check(int dep) {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < 2 * n; i++) ind[i] = -1;
    int tot = n;
    num = idn = 0;
    cnt = 0;
    ncnt = 0;
    for(int i = 0; i < dep; i++) {
        int p = a[i];
        int q = b[i];
        if(c[i] == 2) {
            add(p + n, q);
            add(q + n, p);
        }
        else if(c[i] == 1) {
            add(p, q);
            add(q, p);
            add(q + n, p + n);
            add(p + n, q + n);
        }
        else {
            add(p, q + n);
            add(q, p + n);
        }
    }
    for(int i = 0; i < 2 * n; i++) tarjan(i);
    for(int i = 0; i < n; i++) {
        if(color[i] == color[tot + i]) return false;
    }
    return true;
}

inline void run() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    int l = 0, r = m;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) run();
    return 0;
}
