#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int maxn = 110;
const int maxt = 510;
const int maxm = 2 * maxn;
int dp[maxn][maxt];
int a[maxn];
int ind[maxn];
int to[maxm], nt[maxm], c[maxm];
int f[maxt];
int vis[maxn];
int v[maxn];
int cnt;
int n, t;

void cmax(int &x, int y) {
    x = std::max(x, y);
}

void dfs(int x, int pre) {
    for(int k = ind[x]; k != -1; k = nt[k])
        if(to[k] != pre) dfs(to[k], x);

	for(int k = ind[x]; k != -1; k = nt[k]) 
	if(to[k] != pre) {
		for(int j = t; j >= 0; j--) 
			for(int p = 0; p <= t; p++)
			if(j - p - 2 * c[k] >= 0) {
				cmax(dp[x][j], dp[to[k]][j - 2 * c[k] - p] + dp[x][p]);
			}
			else break;
	}
	for(int i = 0; i <= t; i++) dp[x][i] += a[x];
}

int dfs1(int x, int pre) {
    if(x == n) {
        vis[x] = 1;
    }
    for(int k = ind[x]; k != -1; k = nt[k])
    if(to[k] != pre) {
        if(dfs1(to[k], x)) vis[x] = 1;
    }
    if(vis[x] == 1) {
        for(int k = ind[x]; k != -1; k = nt[k])
        if(to[k] != pre && vis[to[k]] != 1) {
            vis[to[k]] = 2;
            v[to[k]] = c[k];
        }
        return true;
    }
    else return false;
}

int dfs2(int x, int pre) {
    if(x == n) return 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(vis[to[k]] == 1 && to[k] != pre) {
        return c[k] + dfs2(to[k], x);
    }
}

void add(int a, int b, int v) {
    to[cnt] = b;
    c[cnt] = v;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int main() {
    //freopen("J.in", "r", stdin);
    while(~scanf("%d%d", &n, &t)) {
        memset(ind, -1, sizeof ind);
        memset(vis, 0, sizeof vis);
        memset(v, 0, sizeof v);
        memset(dp, 0, sizeof dp);
        cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        dfs(1, -1);
        dfs1(1, -1);
        int cost = dfs2(1, -1);
        if(cost > t) {
            puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
            continue;
        }
        t -= cost;
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; i++)
        if(vis[i] == 2) {
            for(int j = t; j >= 0; j--)
				for(int k = 0; k <= t; k++)
				if(j >= k + 2 * v[i])
					f[j] = std::max(f[j], f[j - k - 2 * v[i]] + dp[i][k]);
				else break;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        if(vis[i] == 1) ans += a[i];
        printf("%d\n", f[t] + ans);
    }
    return 0;
}
