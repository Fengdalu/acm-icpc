#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int Maxm = 6000000;
const int Maxn = 2005;

struct GRAPH {
    struct node {
        int u, v, next;
    }adj[Maxm];
    int tot, last[Maxn];
    void init(int n) {
        for(int i = 0; i <= n; i++) last[i] = -1;
        tot = 0;
    }
    void adde(int u, int v) {
        adj[tot].u = u; adj[tot].v = v;
        adj[tot].next = last[u]; last[u] = tot++;
    }
}e;
int n, m;
int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn], nindex, ncnt;
stack<int> sta;
void Tarjan(int u, int from) {
    int j, v;
    dfn[u] = low[u] = nindex++;
    instack[u] = 1;
    sta.push(u);
    for(j = e.last[u]; ~j; j = e.adj[j].next) {
        if(j == from) continue;
        v = e.adj[j].v;
        if(-1 == dfn[v]) {
            Tarjan(u, j ^ 1);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v] && dfn[v] < low[u]) {
            low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]) {
        do {
            v = sta.top();
            sta.pop();
            instack[v] = 0;
            belong[v] = ncnt;
        } while(v != u);
        ncnt++;
    }
}

void solve() {
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(instack, 0, sizeof(instack));
    memset(belong, -1, sizeof(belong));
    ncnt = 1;
    nindex = 1;
    int flag = 0;
    for(int i = 1; i <= n; i++)
        if(-1 == dfn[i]) {
            Tarjan(i, -1);
            flag++;
        }
    for(int i = 1; i <= n; i++)
        cout << i << " " << belong[i] <<endl;
}

int Map[Maxn][Maxn];

int main() {
    int _T; scanf("%d", &_T);
    for(int CASE = 1; CASE <= _T; CASE++) {
        scanf("%d", &n);
        e.init(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf("%d", &Map[i][j]);
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 2; j <= min(4, n); j++) {
                e.adde(i, Map[i][j]);
                e.adde(Map[i][j], i);
            }
        solve();
    }
    return 0;
}
