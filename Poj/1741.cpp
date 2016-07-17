#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 10010;
int ind[maxn];
int to[maxn * 2], nt[maxn * 2], c[maxn * 2];
int q[maxn], pre[maxn], sz[maxn];
int ba[maxn];
int f[maxn], num;
bool vis[maxn];
int cnt;
int ans = 0;

int n, k;

void cmax(int &a, int b) {
    a = max(a, b);
}

void add(int a, int b, int w) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    c[cnt] = w;
    ind[a] = cnt++;
}

int bfs(int x, int fa = -1)  {
    int l = 0, r = -1;
    q[++r] = x;
    pre[x] = fa;
    while(l <= r) {
        int x = q[l++];
        sz[x] = 1;
        ba[x] = 0;
        for(int k = ind[x]; k != -1; k = nt[k])  {
            int v = to[k];
            if(!vis[v] && v != pre[x]) {
                pre[v] = x;
                q[++r] = v;
            }
        }
    }
    for(int i = r; i > -1; i--) {
        int v = q[i];
        if(pre[v] != -1) sz[pre[v]] += sz[v];
        cmax(ba[pre[v]],  sz[v]);
    }
    return r;
}

void dfs(int rt, int fa, int dis) {
    f[num++] = dis;
    for(int k = ind[rt]; k != -1; k = nt[k])  {
        int v = to[k];
        if(!vis[v] && v != fa) {
            dfs(v, rt, dis + c[k]);
        }
    }
}

void divide(int rt) {
    int r = bfs(rt);
    rt = -1;
    for(int i = r; i > -1; i--)  {
        int v = q[i];
        cmax(ba[v], r - sz[v] + 1);
        if(rt == -1 || ba[v] < ba[rt]) rt = v;
    }
    bfs(rt);
    num = 0;
    dfs(rt, -1, 0);
    sort(f, f + num);

    int a = 0, b = num - 1;
    while(a < b) {
        while(f[a] + f[b] > k && a < b) b--;
        ans += b - a;
        a++;
    }

    num = 0;
    int K = k;
    for(int k = ind[rt]; k != -1; k = nt[k]) {
        int v = to[k];
        if(!vis[v]) {
            num = 0;
            dfs(v, rt, c[k]);
            sort(f, f + num);
            a = 0; b = num - 1;
            while(a < b) {
                while(f[a] + f[b] > K && a < b) b--;
                ans -= b - a;
                a++;
            }
        }
    }
    vis[rt] = true;
    for(int k = ind[rt]; k != -1; k = nt[k])
    if(!vis[to[k]]) divide(to[k]);
}

int main() {
    while(~scanf("%d%d", &n, &k) && n && k) {
        for(int i = 0; i <= n; i++) ind[i] = -1;
        for(int i = 0; i < n; i++) vis[i] = false;
        for(int i = 0; i < n; i++) ba[i] = 0;
        ans = 0;
        cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z); x--; y--;
            add(x, y, z); add(y, x, z);
        }
        divide(0);
        printf("%d\n", ans);
    }
    return 0;
}

