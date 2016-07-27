#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int maxm = 400010;
typedef long long ll;
const ll mod = 1e9 + 7;

int head[maxn], dfn[maxn], low[maxn], vis[maxn];
int mul[maxn], sum[maxn], w[maxn], mmul[maxn], ssum[maxn];
int belong[maxn];
int cut[maxn];
int to[maxm], nt[maxm], cover[maxm], etot;
int fa[maxn];
int rt[maxn];
int n, m;

void add(int a, int b) {
    to[etot] = b;
    nt[etot] = head[a];
    cover[etot] = false;
    head[a] = etot++;
}

inline void modext(int &a, int b) { a = (1ll * (a - b) % mod + mod) % mod; }

inline void modadd(int &a, int b) {
    a = 1ll * (1ll * a + b) % mod;
}

inline void modmul(int &a, int b) {
    a = 1ll * a * b % mod;
}

inline int inv(int v) {
    int ans = 1;
    int k = mod - 2;
    while(k) {
        if(1 & k) modmul(ans, v);
        modmul(v, v);
        k >>= 1;
    }
    return ans;
}

void tarjan(int u, int fa, int rt, int lim) {
    dfn[u] = low[u] = lim;
    mul[u] = 1ll;
    belong[u] = 1ll;
    vis[u] = true;
    int nc = 0;
    int nr = 1;
    for(int k = head[u]; k != -1; k = nt[k]) if(!cover[k]) {
        int v = to[k];
        cover[k] = cover[k ^ 1] = true;
        if(vis[v]) {
            if(v != fa) low[u] = min(low[u], dfn[v]);
            continue;
        }
        nc++;
        tarjan(v, u, rt, lim + 1);
        modadd(nr, mul[v]);
        if(low[v] >= dfn[u]) {
            cut[u] = true;
            modadd(sum[u], mul[v]);
            modmul(belong[u], mul[v]);
        }
        low[u] = min(low[u], low[v]);
        modmul(mul[u], mul[v]);
    }
    modmul(mul[u], w[u]);
    if(u == rt && nc <= 1) {
        cut[u] = false;
    }
}

int find(int a) { if(fa[a] == a) return fa[a]; return fa[a] = find(fa[a]); }

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        scanf("%d%d", &n, &m);
        etot = 0;
        for(int i = 0; i < n; i++) scanf("%d", &w[i]);
        for(int i = 0; i < n; i++) fa[i] = i;
        fill(head, head + n, -1);
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b); a--; b--;
            add(a, b), add(b, a);
            if(find(a) != find(b)) fa[find(a)] = find(b);
        }
        fill(mmul, mmul + n, 1);
        fill(ssum, ssum + n, 0);
        fill(rt, rt + n, 0);
        int ss = 1;
        int sss = 0;
        for(int i = 0; i < n; i++) modmul(mmul[find(i)], w[i]);
        for(int i = 0; i < n; i++) if(find(i) == i) modadd(sss, mmul[find(i)]);
        for(int i = 0; i < n; i++) modadd(ssum[find(i)], w[i]);
        for(int i = 0; i < n; i++) modmul(ss, w[i]);
        fill(cut, cut + n, 0);
        fill(sum, sum + n, 0);
        fill(vis, vis + n, false);
        for(int i = 0; i < n; i++) if(!vis[i]) { rt[i] = 1; tarjan(i, -1, i, i); }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(cut[i]) {
                int l = mmul[find(i)];
                modmul(l, inv(belong[i]));
                modmul(l, inv(w[i]));
                if(rt[i]) l = 0;
                modadd(l, sum[i]);
                modadd(l, sss);
                modext(l, mmul[find(i)]);
                modmul(l, i + 1);
                modadd(ans, l);
            }
            else {
                int t = sss;
                int p = mmul[find(i)];
                modext(t, p);
                modmul(p, inv(w[i]));
                if(head[i] != -1) modadd(t, p);
                modmul(t, i + 1);
                modadd(ans, t);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
