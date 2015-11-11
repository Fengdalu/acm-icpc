#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
#define LL long long

namespace WT
{
    const double MOD = 1e18;
    const int Maxn = 3000;
    const int Maxm = 1000000;
    struct edge
    {
        int u, v;
        int c;
        double w;
        int next;
    }e[Maxm];
    int last[Maxn];
    int tot;
    double flow, cost, value;
    double dist[Maxn];
    int visit[Maxn], src, des;
    deque<int> Q;
    int n, m;

    void adde(int u, int v, int c, double w) {
        e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
        e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
    }

    int Aug(int u, int m) {
        if(u == des) {
            cost += value * m;
            flow += m;
            return m;
        }
        visit[u] = true;
        int l = m;
        int j, v, c;
        double w;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v; c = e[j].c; w = e[j].w;
            if(c && !w && !visit[v]) {
                int del = Aug(v, l < c ? l : c);
                e[j].c -= del; e[j ^ 1].c += del; l -= del;
                if(!l) return m;
            }
        }
        return m - l;
    }

    bool Modlabel(int src, int des, int n) {
        int i, j, u, v, c;
        double w, del;
        for(int i = 0; i < n + 10; i++) dist[i] = MOD;
        dist[src] = 0.0;
        while(!Q.empty()) Q.pop_back();
        Q.push_back(src);
        while(!Q.empty()) {
            u = Q.front(); Q.pop_front();
            for(j = last[u]; j != -1; j = e[j].next) {
                v = e[j].v; c = e[j].c; w = e[j].w;
                if(c && (del = dist[u] + w) < dist[v]) {
                    dist[v] = del;
                    if(Q.empty() || del <= dist[Q.front()]) {
                        Q.push_front(v);
                    }
                    else {
                        Q.push_back(v);
                    }
                }
            }
        }
        for(i = 0; i < n; i++) {
            for(j = last[i]; j != -1; j = e[j].next) {
                e[j].w -= dist[e[j].v] - dist[i];
            }
        }
        value += dist[des];
        return dist[des] < MOD;
    }

    void zkw(int src, int des, int n) {
       value = cost = flow = 0;
       while(Modlabel(src, des, n)){
           do {
                memset(visit, 0, sizeof(visit[0]) * (n + 3));
           }while(Aug(src, MOD));
       }
    }
};

const int N = 510;
int x[N], y[N], z[N];
int h[N];
int w[N];
int n, s, t, q;

inline double sqr(double x) { return x * x; }

double dis(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt( sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2) );
}

int main()
{
    //freopen("A.in", "r", stdin);
    scanf("%d%d%d%d", &n, &s, &t, &q);
    for(int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
    for(int i = 1; i <= s; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= t; i++) scanf("%d", &h[i]);

    WT::n = n + 2;
    memset(WT::last, -1, sizeof WT::last);
    WT::tot = 0;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(z[i] > z[j])
    if( dis(x[i], y[i], z[i], x[j], y[j], z[j]) <= (double)q ) WT::adde(i, j, WT::MOD, dis(x[i], y[i], z[i], x[j], y[j], z[j]) );

    for(int i = 1; i <= s; i++) WT::adde(0, w[i], 1, 0);
    for(int i = 1; i <= t; i++) WT::adde(h[i], n + 1, 1, 0);
    WT::src = 0;
    WT::des = n + 1;


    WT::zkw(WT::src, WT::des, n + 2);
    if(WT::flow == t)
    printf("%.16f\n", WT::cost);
    else puts("IMPOSSIBLE");
    /*
    int flow = WT::flow;
    double cost = WT::cost;

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(z[i] > z[j])
    if( dis(x[i], y[i], z[i], x[j], y[j], z[j]) <= (double)q ) WT::adde(i, j, WT::MOD, 0);
    WT::zkw(WT::src, WT::des, n + 2);

    if(WT::flow + flow == t)
    printf("%.16f\n", WT::cost + cost);
    else puts("IMPOSSIBLE");
    */
    return 0;
}
