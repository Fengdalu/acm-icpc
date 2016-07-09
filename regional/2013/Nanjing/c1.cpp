#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 1000003
#define N 100005
typedef long long ll;

struct E{
    int v, d, ne;
    E() {}
    E(int _v, int _ne):v(_v), ne(_ne){}
}e[N*2];

bool vis[N];
int size, head[N], ans[2], root, flag[mod], F[mod], sum[N], mi, cr, id[N];
ll val[N], ni[mod], path[N];

void init() {
    size = 0;
    memset(vis, false, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    memset(head, -1, sizeof(head));
    memset(flag, 0, sizeof(flag));
}

void add(int u, int v) {
    e[size] = E(v, head[u]);
    head[u] = size++;
}

void dfs(int u, ll k) {
    int i, v;
    sum[u] = 1;
    vis[u] = true, id[cr] = u;
    path[cr++] = k*val[u]%mod;
    ll tm = path[cr-1];
    for (i = head[u];~i;i = e[i].ne) {
        v = e[i].v;
        if (vis[v]) continue;
        dfs(v, tm);
        sum[u] += sum[v];
    }
    vis[u] = false;
}

ll k;
int n, ca;
void getans(int a, int b) {
    if (a > b) swap(a,b);
    if (ans[0] == -1 || ans[0] > a) ans[0] = a, ans[1] = b;
    else if (ans[0] == a && ans[1] > b) ans[1] = b;
}

void getroot(int u) {
    int i, v, mx = 0;
    sum[u] = 1;
    vis[u] = true;
    for (i = head[u];~i;i = e[i].ne) {
        v = e[i].v;
        if (vis[v]) continue;
        getroot(v);
        sum[u] += sum[v];
        mx = max(mx, sum[v]);
    }
    mx = max(mx, sum[0]-sum[u]);
    if (mx < mi) mi = mx, root = u;
    vis[u] = false;
}
void cal(int u, int cnt) {
    if (cnt == 1) return;
    int i, v, j;
    mi = n;
    sum[0] = cnt;
    getroot(u);
    vis[root] = true;
    for (i = head[root];~i;i = e[i].ne) {
        v = e[i].v;
        if (vis[v]) continue;
        cr = 0;
        dfs(v, 1);
        for (j = 0;j < cr;j++) {
            if (path[j]*val[root]%mod == k) getans(root, id[j]);
            ll tm = k*ni[path[j]*val[root]%mod]%mod;
            if (flag[tm] != ca) continue;
            getans(F[tm], id[j]);
        }
        for (j = 0;j < cr;j++) {
            int tm = path[j];
            if (flag[tm] != ca || F[tm] > id[j]) F[tm] = id[j], flag[tm] = ca;
        }
    }
    ca++;
    for (i = head[root];~i;i = e[i].ne) {
        if (vis[e[i].v]) continue;
        cal(e[i].v, sum[e[i].v]);
    }
}

ll egcd(ll a,ll b, ll &x, ll &y) {//得到的是a*x+b*y=gcd(a,b)
    ll temp,tempx;
    if (b == 0) {
        x = 1;y = 0;
        return a;
    }
    temp = egcd(b,a % b, x, y);
    tempx = x;
    x = y;
    y = tempx - a / b * y;
    return temp;
}

int main() {
    int u, v, i, j;
    ll y;
    for (i = 0;i < mod;i++) {
        egcd(i*1ll, mod*1ll, ni[i], y);
        ni[i] %= mod, ni[i] = (ni[i]+mod)%mod;
    }
    while (~scanf("%d%lld", &n, &k)) {
        init();
        ca = 1;
        for (i = 1;i <= n;i++) scanf("%lld", &val[i]);
        for (i = 1;i < n;i++) {
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        cal(1, n);
        if (ans[0] == -1) puts("No solution");
        else printf("%d %d\n", ans[0], ans[1]);
    }
}
