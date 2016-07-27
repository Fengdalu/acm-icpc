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
int mul[maxn], sum[maxn], w[maxn];
int cut[maxn];
int to[maxm], nt[maxm], etot;
int fa[maxn];
int n, m;

void add(int a, int b) {
    to[etot] = b;
    nt[etot] = head[a];
    head[a] = etot++;
}

inline void modadd(int &a, int b) {
    a = 1ll * (a + b) % mod;
}

inline void modmul(int &a, int &b) {
    a = 1ll * a * b % mod;
}

inline int inv(int v) {
    int ans = 1;
    int k = mod;
    while(k) {
        if(1 & k) modmul(ans, v);
        modmul(v, v);
        k >>= 1;
    }
    return ans;
}

void tarjan(int u, int fa, int lim) {
    dfn[u] = low[u] = lim;
    mul[u] = 1ll;
    vis[u] = true;
    for(int k = head[u]; k != -1; k = nt[k]) {
        int v = to[k];
        if(vis[v]) {
            if(v != fa) low[u] = min(low[u], dfn[v]);
            continue;
        }
        tarjan(v, u, lim + 1);
        if(low[v] >= dfn[u]) {
            cut[u] = true;
            modadd(sum[u], mul[v]);
        }
        low[u] = min(low[u], low[v]);
        modmul(mul[u], mul[v]);
    }
    modmul(mul[u], w[u]);
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        scanf("%d%d", &n, &m);
        etot = 0;
        for(int i = 0; i < n; i++) scanf("%d", &w[i]);
        for(int i = 0; i < n; i++) head[i] = -1;
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        fill(sum, sum + n, 0);
        fill
    }
    return 0;
}
