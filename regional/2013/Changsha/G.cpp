#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

const int maxn = 102;
const int maxm = 3000;
const int Inf = 1e9;
int n, m, s, e, t;
int cnt;
int c[maxn];
int w[maxn];
int f[maxn][3 * maxn];
int dis[maxn][maxn];
bool vis[maxn];

int main() {
    //freopen("G.in", "r", stdin);
    int Case;
    scanf("%d", &Case);
    for(int T = 1; T <= Case; T++) {
        scanf("%d%d%d%d%d", &n, &m, &t, &s, &e);
        int h = 0;
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        for(int i = 0; i < n; i++) scanf("%d", &w[i]);

        memset(dis, 0x3f, sizeof dis);
        for(int i = 0; i < m; i++) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            dis[x][y] = dis[y][x] = std::min(dis[x][y], c);
        }
        for(int i = 0; i < n; i++) dis[i][i] = 0;
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);

        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < dis[s][i] + c[i]; j++) {
                if(i != s) f[i][j] = -Inf;
            }
        std::queue< std::pair<int, int> >q;
        for(int i = 0; i < n; i++)
        if(dis[s][i] + c[i] <= t) {
            f[i][(dis[s][i] + c[i])] = w[i];
            q.push(std::make_pair(i, dis[s][i] + c[i]));
        }
        while(q.size()) {
            std::pair<int , int>p = q.front();
            q.pop();
            int x = p.first;
            int j = p.second;
            for(int k = 0; k < n; k++) {
                int l = j + dis[x][k] + c[k];
                if(l <= t && w[k] > w[x] && f[x][j] + w[k] > f[k][l]) {
                    f[k][l] = f[x][j] + w[k];
                    q.push(std::make_pair(k, l));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= t - dis[i][e]; j++)
                ans = std::max(f[i][j], ans);
        printf("Case #%d:\n%d\n", T, ans);
    }
    return 0;
}