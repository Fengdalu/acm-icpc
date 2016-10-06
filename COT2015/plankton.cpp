#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

const int M = 1e5;
const int N = 2e4;
int n, m;
int op, ed;
int last[N];
double dis[N];
int u[M], v[M], next[M];
double w[M];
bool vis[N];
int deg[N];
int color[N];
int access[N];
int vis1[N];
int tote;

void add(int _u, int _v, double _w) {
    u[tote] = _u;
    v[tote] = _v;
    w[tote] = _w;
    next[tote] = last[_u];
    last[_u] = tote++;
}

int main() {
    while(true) {
        scanf("%d%d%d%d", &m, &n, &op, &ed);
        if(n + m + op + ed == 0) break;
        tote = 0;
        std::fill(last, last + n + 1, -1);
        for(int i = 0; i < m; i++) {
            int u, v; double w; scanf("%d%d%lf", &u, &v, &w);
            add(u, v, w);
        }
        std::fill(deg, deg + n + 1, 0);
        std::fill(dis, dis + n + 1, 0);
        std::fill(vis, vis + n + 1, true);
        std::queue<int> q;
        for(int i = 1; i != n + 1; i++) q.push(i);
        std::fill(color, color + n + 1, 0);
        int ncol = 1;
        while(q.size()) {
            int u = q.front(); q.pop();
            if(color[u]) continue;
            vis[u] = false;
            if(deg[u] >= n) {
                std::queue<int> q1;
                color[u] = ncol;
                q1.push(u);
                while(q1.size()) {
                    int x = q1.front(); q1.pop();
                    for(int k = last[x]; k != -1; k = next[k]) {
                        int to = v[k];
                        if(color[to] == ncol) continue;
                        color[to] = ncol;
                        q1.push(to);
                    }
                }
                puts("");
                ncol++;
            }
            for(int k = last[u]; k != -1; k = next[k]) {
                int to = v[k];
                if(dis[u] + w[k] > dis[to]) {
                    dis[to] = dis[u] + w[k];
                    if(!vis[to]) {
                        deg[to]++;
                        q.push(to);
                    }
                }
            }
        }
        std::fill(access, access + n + 1, 0);
        access[op] = true;
        q.push(op);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(int k = last[u]; k != -1; k = next[k]) {
                int to = v[k];
                if(access[to]) continue;
                access[to] = true; q.push(to);
            }
        }
        bool flag = false;
        for(int i = 1; !flag && i <= n; i++) if(color[i] && access[i]) {
            q.push(i);
            std::fill(vis, vis + 1 + n, 0);
            vis[i] = true;
            while(q.size()) {
                int u = q.front(); q.pop();
                for(int k = last[u]; k != -1; k = next[k]) {
                    int to = v[k];
                    if(vis[to]) continue;
                    vis[to] = true;
                    q.push(to);
                }
                if(vis[ed]) flag = true;
            }
        }
        if(flag) puts("TRUE");
        else puts("FALSE");
    }
    return 0;
}
/*

3 3 1 3
1 2 0.001
2 3 -0.002
3 1 0.001

3 3 1 3
1 2 1.5
2 3 0.5
3 1 -1.999

6 5 1 5
1 2 -0.1
2 3 0.1
3 4 0.1
4 2 0.1
2 5 -0.1
1 5 0

3 4 1 2
1 2 1
2 3 1
3 2 1

8 7 1 4
1 2 1
1 5 1
2 3 1
3 4 1
4 7 1
7 4 -1
5 6 1
6 5 1


11 9 1 4
1 2 1
1 5 1
2 3 1
3 4 1
4 7 1
7 4 -1
5 6 1
6 5 1
4 8 1
8 9 1
9 8 1

0 0 0 0


*/
