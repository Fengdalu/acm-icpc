#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
#define maxn 1000003
#define mod 1000006
ll inv[maxn];
int ind[maxn];
int to[maxn * 2], nt[maxn * 2];
ll v[maxn];
int cnt, cnt1, cnt2;
int n, K;
int root;
int dp[maxn];
int sum[maxn];
int ht[maxn];
ll h[maxn];
ll path[maxn];
ll pathx[maxn];
int aa, bb;
int vis[maxn];

void init() {
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < mod; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}

void add(int a, int b) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int get(int x, int fa, int ncur) {
    int u = -1;
    for(int k = ind[x]; k != -1; k = nt[k])
        if(to[k] != fa && !vis[to[k]]) {
           int v = get(to[k], x, ncur);
           if(u == -1) u = v;
           else if(dp[v] < dp[u]) u = v;
           sum[x] += sum[to[k]];
           dp[x] = max(sum[to[k]], dp[x]);
        }
    sum[x]++;
    if(u == -1) u = x;
    dp[x] = max(dp[x], ncur - sum[x]);
    if(dp[x] < dp[u]) u = x;
    return u;
}

void dfs(int x, int fa, ll p) {
    ll cur = p * v[x] % mod;
    path[cnt1] = cur;
    pathx[cnt1] = x;
    cnt1++;
    for(int k = ind[x]; k != -1; k = nt[k])
        if(to[k] != fa && !vis[to[k]]) {
            dfs(to[k], x, p * v[x] % mod);
        }
}

void check(int x, int y) {
    if(x > y) swap(x, y);
    if(aa == -1) { aa = x; bb = y; }
    else if(x < aa){
        aa = x; bb = y;
    }
    else if(x == aa && y < bb) {
        aa = x; bb = y;
    }
}

void cal(int x, int fa, int ncur) {
    if(ncur == 1) return;
    cnt2++;
    int root = get(x, fa, ncur);
    cnt1 = 0;
    ll vv = v[root];
    for(int k = ind[root]; k != -1; k = nt[k]) {
        int lr = cnt1;
        dfs(to[k], root, 1);
        for(int i = lr; i < cnt1; i++) {
            if(path[i] * vv % mod == K)
                check(pathx[i], root);
            ll ii = inv[path[i] * vv % mod] * K % mod;;
            if(h[ii] != -1 && ht[ii] == cnt2)
                check(h[ii], pathx[i]);
        }
        for(int i = lr; i < cnt1; i++) {
            int ii = path[i];
            h[ii] = pathx[i];
            ht[ii] = cnt2;
        }
    }
    vis[root] = true;
    for(int k = ind[root]; k != -1; k = nt[k])
    if(!vis[to[k]]) {
        cal(to[k], root, sum[to[k]]);
    }
}

int main() {
    init();
    while(~scanf("%d%d", &n, &K)) {
        for(int i = 0; i < n; i++) dp[i] = 0;
        for(int i = 0; i < n; i++) sum[i] = 0;
        for(int i = 0; i < n; i++) ind[i] = -1;
        for(int i = 0; i < mod; i++) h[i] = -1;
        for(int i = 0; i < mod; i++) ht[i] = -1;
        for(int i = 0; i < n; i++) vis[i] = 0;
        cnt = 0;
        cnt2 = 0;
        aa = -1; bb = -1;
        for(int i = 0; i < n; i++) scanf("%lld", &v[i]);
        for(int i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--; y--;
            add(x, y); add(y, x);
        }
        cal(0, -1, n);
        if(K == 1000003) puts("No solution");
        else if(aa != -1) printf("%d %d\n", aa + 1, bb + 1);
        else printf("No solution\n");
    }
    return 0;
}
