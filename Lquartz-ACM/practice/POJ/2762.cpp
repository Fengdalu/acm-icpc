//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""
#define Maxn 1021
#define Maxm 6011

struct node {
    int u, v, next;
}e[Maxm << 1], e1[Maxm << 1];
int tot, last[Maxn], tot1, last1[Maxn];
int n, m;
int ncnt, nindex;
int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn];
int indeg[Maxn], outdeg[Maxn];
int fa[Maxn];
stack<int> sta;

int getfa(int x) {
    if(fa[x] == x) {
        return x;
    }
    else return fa[x] = getfa(fa[x]);
}

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}
void adde1(int u, int v) {
    e1[tot1].u = u; e1[tot1].v = v; e1[tot1].next = last1[u]; last1[u] = tot1++;
}

void dfs(int u) {
    int v;
    int j;
    sta.push(u);
    instack[u] = 1;
    dfn[u] = low[u] = nindex++;
    for(j = last[u]; j != -1; j = e[j].next) {
        v = e[j].v;
        if(dfn[v] == -1) {
            dfs(v);
            cmin(low[u], low[v]);
        }
        else if(instack[v]) {
            cmin(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        do {
            v = sta.top();
            sta.pop();
            belong[v] = ncnt;
            instack[v] = 0;
        }while(u != v);
        ncnt++;
    }
}

int check() {
    int i, j, k, u, v, w;
    int cnt = 0;
    w = getfa(1);
    for(i = 2; i <= n; i++) {
        if(w != getfa(i)) return 0;
    }
    for(i = 1; i <= n; i++) {
        dfn[i] = low[i] = -1;
        belong[i] = -1;
        instack[i] = 0;
    }
    ncnt = nindex = 0;
    while(!sta.empty()) sta.pop();
    for(i = 1; i <= n; i++) {
        if(dfn[i] == -1) {
            cnt++;
            dfs(i);
        }
    }
    tot1 = 0;
    for(i = 0; i <= ncnt + 1; i++) last1[i] = -1, indeg[i] = 0, outdeg[i] = 0;
    for(i = 0; i < tot; i++) {
        u = e[i].u; v = e[i].v;
        if(belong[u] != belong[v]) {
            adde1(belong[u], belong[v]);
            indeg[belong[v]]++;
            outdeg[belong[u]]++;
        }
    }
    for(i = 0, w = 0; i < ncnt; i++) {
        if(indeg[i] == 0) w++;
    }
    if(w > 1) return 0;
    for(i = 0, w = 0; i < ncnt; i++) {
        if(outdeg[i] == 0) w++;
    }
    if(w > 1) return 0;
    return 1;
}

int main() {
    int i, j, k, u, v, w;
    int te;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d", &n, &m);
        for(i = 0; i <= n; i++) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; i++) fa[i] = i;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adde(u, v);
            if(getfa(u) != getfa(v)) {
                fa[getfa(u)] = getfa(v);
            }
        }
        if(check()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
