#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;

#define Maxn 55
#define Maxm 1011
const double INF = 1e100;
const int MOD = 1000000;
struct node {
    int u, v;
    double c;
    double w;
    int next;
}e[Maxm * 10];
int n, m;
int tot;
int last[Maxn << 2];
double row[Maxn], col[Maxn];
int X[Maxm], Y[Maxm];
int dist[Maxn << 2];
int visit[Maxn << 2], pre[Maxn << 2];
queue<int> Q;

void adde(int u, int v, double c, double w) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

bool spfa(int s, int t, int n) {
    int i, j, k;
    int u, v;
    for(i = 0; i <= n; i++) {
        dist[i] = MOD;
        visit[i] = 0;
        pre[i] = -1;
    }
    while(!Q.empty()) Q.pop();
    Q.push(s);
    dist[s] = 0;
    visit[s] = true;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(e[j].c > 0 && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pre[v] = j;
                if(!visit[v]) {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
        visit[u] = false;
    }
    if(dist[t] < MOD) return true;
    else return false;
}

double changeflow(int t) {
    double det = MOD;
    int u = t;
    while(~pre[u]) {
        u = pre[u];
        det = min(det, e[u].c);
        u = e[u].u;
    }
    u = t;
    while(~pre[u]) {
        u = pre[u];
        e[u].c -= det;
        e[u ^ 1].c += det;
        u = e[u].u;
    }
    return det;
}

double MincostMaxflow(int s, int t, int n) {
    double maxflow;
    double mincost;
    maxflow = 0;
    mincost = 0;
    while(spfa(s, t, n)) {
        double det = changeflow(t);
        mincost += det * dist[t];
        maxflow += det;
    }
    return maxflow;
}

int main() {
    int i, j, k, l, u, v, w;
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d%d", &n, &m, &l);
        for(i = 1; i <= n; i++) scanf("%lf", &row[i]);
        for(i = 1; i <= m; i++) scanf("%lf", &col[i]);
        for(i = 1; i <= l; i++) scanf("%d%d", &X[i], &Y[i]);
        int S = 0, T = n + m + 2, N = T + 1;
        for(i = 0; i <= N; i++) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; i++) {
            adde(S, i, log10(row[i]), log10(row[i]));
        }
        for(i = 1; i <= m; i++) {
            adde(n + i, T, log10(col[i]), log10(col[i]));
        }
        for(i = 1; i <= l; i++) {
            adde(X[i], n + Y[i], Maxn, 0);
        }
        double ans = 0;
        ans = MincostMaxflow(S, T, N);
        //for(j = last[S]; j != -1; j = e[j].next) {
            //if(e[j].c == 0) {
                //ans += e[j].w;
                //cout << pow(10, e[j].w) << " " << e[j].u << " " << e[j].v << endl;
            //}
        //}
        //for(j = last[T]; j != -1; j = e[j].next) {
            //if(e[j ^ 1].c == 0) {
                //ans += e[j ^ 1].c;
                //cout << pow(10, e[j ^ 1].w) << " " << e[j ^ 1].u << " " << e[j ^ 1].v << endl;
            //}
        //}
        ans = pow(10, ans);
        printf("%.4f\n", ans);
    }
    return 0;
}
