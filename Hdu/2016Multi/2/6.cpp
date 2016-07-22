#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int N = 100010;
const int M = 400010;
typedef long long ll;
const ll mod = 1e9 + 7;
int ind[N];
int t[M], nt[M], to[M];
int dfn[N], low[N];
int w[N];
bool vis[N];
bool f[N];
int n, m;
int cnt, num, idn;
ll fact[N];
int fa[N];

void add(int i, int j)
{
    cnt++;
    t[cnt] = j;
    nt[cnt] = ind[i];
    ind[i] = cnt;
}

ll qpow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = (ans * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

void tarjan(int x) {
    if(dfn[x]) return;
    low[x] = dfn[x] = ++num;
    vis[x] = true;
    for(int k = ind[x]; k != -1; k = nt[k]) {
        if(!vis[to[k]]) {
            tarjan(to[k]);
            low[x] = min(low[x], low[to[k]]);
            if(low[to[k]] >= dfn[x]) f[x] = true;
        }
    }
}

int find(int x) { if(fa[x] == x) return x; return fa[x] = find(fa[x]); }

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        ll sum = 0, mul = 1;
        for(int i = 0; i < n; i++) scanf("%d", &w[i]);
        for(int i = 0; i < n; i++) sum = (sum + w[i]) % mod;
        for(int i = 0; i < n; i++) mul = (mul * w[i]) % mod;
        for(int i = 0; i < n; i++) ind[i] = -1;
        for(int i = 0; i < n; i++) fa[i] = i;
        cnt = 0;
        for(int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y); x--; y--;
            add(x, y); add(y, x);
            if(find(x) != find(y)) fa[find(x)] = find(y);
        }
        memset(f, 0, sizeof f);
        int rt = find(0);
        bool flag = false;
        for(int i = 0; i < n; i++) if(find(i) != rt) { flag = true; break; }
        if(flag)
        for(int i = 0; i < n; i++) if(flag) f[i] = true;
        idn = num = 0;
        memset(vis, 0, sizeof vis);
        memset(dfn, 0, sizeof dfn);
        for(int i = 0; i < n; i++) tarjan(i);
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            if(f[i]) ans = (ans + (ll)(i + 1) * mul % mod * qpow(w[i], mod - 2)) % mod;
            else ans = (ans + (ll)(i + 1) * (sum - w[i]) % mod) % mod;
        }
        for(int i = 0; i < n; i++) if(f[i]) cout << i + 1 << endl;
        ans = (ans % mod + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}
