#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

const int maxn = 205;
const int maxm = maxn * maxn * 4;
const int maxk = 14;
const int inf = 1e9;
int id[maxn][maxn];
int x[maxn], y[maxn];
int d[maxk][maxk];
int in[maxk];
int s[maxn][maxn];
int ind[maxn * maxn];
int to[maxm], c[maxm], nt[maxm];
int dp[14][1 << 14];
int n, m, K;
int cnt;
int ncnt;
int f[maxn * maxn];
int vis[maxn][maxn];
bool vis1[maxn * maxn];
const int V[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int get(int i, int j) {
    if(id[i][j] == -1) return id[i][j] = ncnt++;
    return id[i][j];
}

void add(int x, int y, int v) {
    to[cnt] = y;
    c[cnt] = v;
    nt[cnt] = ind[x];
    ind[x] = cnt++;
}

void add2(int x, int y, int v) {
    add(x, y, v);
    add(y, x, v);
}

void dijk(int src) {
    memset(vis1, 0, sizeof vis1);
    std::set< std::pair<int, int> >q;
    for(int i = 0; i < ncnt; i++) f[i] = inf;
    f[src] = 0;
    vis1[src] = true;
    for(int i = 0; i < ncnt; i++) q.insert(std::make_pair(f[i], i));
    while(q.size()) {
        std::pair<int, int>o = *q.begin();
        int x = o.second;
        q.erase(q.begin());
        vis1[x] = true;
        for(int k = ind[x]; k != -1; k = nt[k])
            if(f[x] + c[k] < f[to[k]]) {
                std::set< std::pair<int, int> >::iterator it = q.find(std::make_pair(f[to[k]], to[k]));
                q.erase(it);
                f[to[k]] = f[x] + c[k];
                q.insert(std::make_pair(f[to[k]], to[k]));
            }
    }
}

int main() {
    //freopen("D.in", "r", stdin);
    int Case;
    scanf("%d", &Case);
    for(int T = 1; T <= Case; T++) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) scanf("%d", &s[i][j]);
        
        memset(ind, -1, sizeof ind);
        memset(id, -1, sizeof id);
        cnt = 0;
        ncnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                get(i, j);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(s[i][j] != -1)
                    for(int p = 0; p < 4; p++) {
                        int tx = i + V[p][0];
                        int ty = j + V[p][1];
                        if(tx > 0 && ty > 0 && tx < n + 1 && ty < m + 1 && s[tx][ty] != -1) {
                            add(get(i, j), get(tx, ty), s[tx][ty]);
                        }
                    }
        
        scanf("%d", &K);
        for(int i = 0; i < K; i++) scanf("%d%d", &x[i], &y[i]);
        for(int i = 0; i < K; i++) x[i]++;
        for(int i = 0; i < K; i++) y[i]++;
        
        for(int i = 0; i < K; i++) {
            dijk(get(x[i], y[i]));
            in[i] = inf;
            for(int j = 1; j <= n; j++) {
                in[i] = std::min(in[i], f[get(j, 1)]);
                in[i] = std::min(in[i], f[get(j, m)]);
            }
            for(int j = 1; j <= m; j++) {
                in[i] = std::min(in[i], f[get(1, j)]);
                in[i] = std::min(in[i], f[get(n, j)]);
            }
            for(int j = 0; j < K; j++) {
                d[i][j] = f[get(x[j], y[j])];
            }
        }
        int inv =dp[0][0];
        memset(dp, 0x3f, sizeof dp);
        for(int i = 0; i < K; i++) dp[i][1 << i] = in[i] + s[x[i]][y[i]];
        for(int mask = 0; mask < (1 << K); mask++)
            for(int i = 0; i < K; i++)
                if(1 << i & mask && dp[i][mask] != inv) {
                    for(int j = 0; j < K; j++)
                        dp[j][1 << j | mask] = std::min(dp[j][1 << j | mask], dp[i][mask] + d[i][j]);
                }
        
        int ans = inf;
        for(int i = 0; i < K; i++)
            ans = std::min(ans, dp[i][(1 << K) - 1] + in[i]);
        printf("%d\n", ans);
    }
    return 0;
}
