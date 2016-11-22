#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 3050;
const int maxm = 6000;
int ind[maxn];
int nt[maxm], t[maxm];
int g[maxn][maxn];
bool vis[maxn];
vector<pair<int, int> >from[maxn], to[maxn];
int cnt;
int n, m;

void add(int a, int b) {
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(ind, -1, sizeof ind);
    for(int i = 0; i < m; i++) {
         int a, b;
         scanf("%d%d", &a, &b);
         add(a, b);
    }
    memset(g, -1, sizeof g);
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(bool) * (n + 3));
        queue<int>q;
        q.push(i);
        vis[i] = true;
        g[i][i] = 0;
        while(!q.empty()) {
             int x = q.front();
             q.pop();
             for(int k = ind[x]; k != -1; k = nt[k])
                 if(!vis[t[k]]) {
                    g[i][t[k]] = g[i][x] + 1;
                    q.push(t[k]);
                    vis[t[k]] = true;
                 }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(i != j) {
                if(g[i][j] != -1) {
                    to[i].push_back(make_pair(-g[i][j], j));
                    sort(to[i].begin(), to[i].end());
                    if(to[i].size() > 3) to[i].resize(3);
                }
            }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(i != j) {
                if(g[j][i] != -1) {
                    from[i].push_back(make_pair(-g[j][i], j));
                    sort(from[i].begin(), from[i].end());
                    if(from[i].size() > 3) from[i].resize(3);
                }
            }
    }
    int a, b, c, d, tot = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && g[i][j] != -1) {
                for(int p = 0; p < to[j].size(); p++)
                    for(int q = 0; q < from[i].size(); q++) {
                        int u = to[j][p].second;
                        int v = from[i][q].second;
                        if(u != v && u != i && u != j && v != i && v != j) {
                            if(g[v][i] + g[i][j] + g[j][u] > tot)  {
                                a = v;
                                b = i;
                                c = j;
                                d = u;
                                tot = g[v][i] + g[i][j] + g[j][u];
                            }
                        }
                    }
            }
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}

