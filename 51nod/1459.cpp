#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int Maxn = 502;
const int Maxm = Maxn * Maxn;
const int INF = 1e9 + 7;

int dis[Maxn], cost[Maxn];
int c[Maxm], t[Maxm], nt[Maxm];
int ind[Maxn], v[Maxn];
bool vis[Maxn];
int st, ed;
int n, m;
int cnt;

void add(int a, int b, int C) {
    t[cnt] = b;
    nt[cnt] = ind[a];
    c[cnt] = C;
    ind[a] = cnt++;
}

deque<int>Q;


void spfa(int st, int ed) {
    memset(dis, 0, sizeof dis);
    for(int i = 0; i <= n; i++) dis[i] = INF;
    dis[st] = 0;
    memset(cost, 0, sizeof cost);
    memset(vis, 0, sizeof vis);
    cost[st] = v[st];
    Q.push_back(st);
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop_front();
        vis[x] = false;
        for(int k = ind[x]; k != -1; k = nt[k]) {
            if(dis[t[k]] > dis[x] + c[k]) {
                dis[t[k]] = dis[x] + c[k];
                cost[t[k]] = cost[x] + v[t[k]];
                if(!vis[t[k]]) {
                    vis[t[k]] = true;
                    Q.push_back(t[k]);
                }
            }
            else if(dis[t[k]] == dis[x] + c[k] && cost[t[k]] < cost[x] + v[t[k]]){
                dis[t[k]] = dis[x] + c[k];
                cost[t[k]] = cost[x] + v[t[k]];
                if(!vis[t[k]]) {
                    vis[t[k]] = true;
                    Q.push_back(t[k]);
                }
            }
        }
    }
    printf("%d %d\n", dis[ed], cost[ed]);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    memset(ind, -1, sizeof ind);
    cnt = 0;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    spfa(st, ed);
    return 0;
}
