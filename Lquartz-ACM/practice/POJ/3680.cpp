#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 1110
#define Maxm 3100
#define CLRINF 1000000007
#define PB push_back
#define SZ size()
vector<int> g;
struct node {
    int u, v, c, w, next;
}e[Maxm];
int tot, last[Maxn];
int n, m, k;

void adde(int u, int v, int c, int w) {
//    cout << "adde " << u << " " <<v <<" " << c << " " << w << endl;
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

#define MOD 0x3f3f3f3f
int flow, cost, value;
int dist[Maxn], visit[Maxn], src, des;
deque<int> Q;
int Aug(int u, int m) {
    if(u == des) {
        cost += value * m;
        flow += m;
        return m;
    }
    visit[u] = true;
    int l = m;
    int j, v, c, w;
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
    int i, j, u, v, c, w, del;
    memset(dist, 0x3f, sizeof(dist[0])*(n + 3));
    dist[src] = 0;
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

int L[300], R[300], W[300];
int main() {
    int i, j, u, v, w, te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d", &n, &k);
        int dmax = 0;
        g.clear();
        for(i = 0; i < n; i++) {
            scanf("%d%d%d", &L[i], &R[i], &W[i]);
            dmax = max(dmax, R[i]);
            g.PB(L[i]); g.PB(R[i]);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for(i = 0; i < n; i++) {
            for(j = 0; j < g.SZ; j++) {
                if(L[i] == g[j]) {
                    L[i] = j + 1;
                    break;
                }
            }
            for(j = 0; j < g.SZ; j++) {
                if(R[i] == g[j]) {
                    R[i] = j + 1;
                    break;
                }
            }
        }
        dmax = g.SZ + 1;
//        cout << "dmax " << dmax << endl;
        tot = 0;
        int N = dmax * 2 + 3 + n;
        int S = 0, T = N - 1;
        for(i = 0; i <= N; i++) {
            last[i] = -1;
        }
        for(i = 1; i <= 2 * dmax; i++) {
            if(i > 1)adde(i - 1, i, k, 0);
        }
        adde(S, 1, k, 0);
        adde(2 * dmax, T, k, 0);
        for(i = 0; i < n; i++) {
            u = 2 * dmax + i + 1;
            adde(2 * L[i] + 1, u, 1, -W[i]);
            adde(u, 2 * R[i], 1, 0);
        }
        src = S; des = T;
        zkw(S, T, N);
        cout << -cost << endl;
    }
    return 0;
}
