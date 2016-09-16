#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
const int N = 400*3;
const int M = N*N;
const double inf = 1e20;
int n, m;
double L, U;
int ind[N];
double dis[N];
int to[M], nt[M];
double w[M];
int vis[N];
int in[N];
int cnt;

void add(int a, int b, double c) {
    //printf("add %d %d %lf\n", a, b, c);
    to[cnt] = b;
    w[cnt] = c;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}


int stk[N*3];
int main() {
    while(~scanf("%d%d%lf%lf", &n, &m, &L, &U)) {
        cnt = 0;
        std::fill(ind, ind + n + n + 1, -1);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                int a = i, b = j + n;
                double x;
                scanf("%lf", &x);
                double l = 1.0 * L / x;
                double r = 1.0 * U / x;
                add(b, a, log(r));
                add(a, b, -log(l));
            }
        std::fill(dis, dis + n + m + 10, 0);
        std::fill(vis, vis + n + m + 10, 0);
        std::fill(in, in + n + m + 10, 0);

        std::deque<int>q;
        for(int i = 1; i <= n + m; i++) q.push_back(i);
        for(int i = 1; i <= n + m; i++) vis[i] = true;
        bool flag = false;
        double tot = 0;
        while(q.size() && !flag) {
            double avg = tot / 1.0 / q.size() - 1;
            while(q.size() != 1 && dis[q.front()] < avg) {
                int v = q.front(); q.pop_front(); q.push_back(v);
            }
            int u = q.front(); q.pop_front();
            vis[u] = false;
            for(int k = ind[u]; k != -1; k = nt[k]) {
                int v = to[k];
                if(dis[v] < dis[u] + w[k]) continue;
                if(vis[v]) tot -= dis[v];
                dis[v] = dis[u] + w[k];
                tot += dis[v];
                if(vis[v]) continue;
                vis[v] = true;
                in[v]++;
                if(in[v] > sqrt(n + m)) { flag = true; break; }
                if(q.size() && dis[v] > dis[q.front()]) q.push_front(v);
                else q.push_back(v);
                q.push_back(v);
            }
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
