#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

#define Maxn 350000
#define Maxm 2500000
#define MOD 1000000007

struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int n;
int g[Maxn], dist[Maxn], visit[Maxn];
queue<int> Q;

void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}

void spfa(int s) {
    int i, j, u, v, tp;
    for(i = 0; i < 2 * n + 10; i++) {
        dist[i] = -MOD;
        visit[i] = false;
    }
    dist[s] = 0;
    visit[s] = true;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            tp = dist[u] + e[j].l;
            if(dist[v] < tp) {
                dist[v] = tp;
                if(!visit[v]) {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
        visit[u] = false;
    }
}

int main() {
    int i, j, u, v, w;
    while(scanf("%d", &n) != EOF) {
        g[0] = g[n + 1] = 0;
        for(i = 0; i < 2 * n + 10; i++) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; i++) scanf("%d", &g[i]);
        for(i = 1; i <= n; i++) {
            u = i << 1;
            v = u | 1;
            adde(u, u + 2, 0);
            adde(u, u + 3, g[i]);
            adde(v, v + 2, 0);
            adde(v, v + 1, -g[i]);
        }
        adde(0, 2, 0);
        adde(0, 3, 0);
        spfa(0);
        cout << max(dist[(n + 1) << 1], dist[(n + 1) << 1 | 1]) << endl;
    }
    return 0;
}
