#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 311
#define Maxm 311111
/*
 *   SCC 使用图struct
 */      
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
}e, e1;
int dfn[Maxn], low[Maxn], belong[Maxn], instack[Maxn], ncnt, nindex;
stack<int> sta;
int rid[Maxn], sta1[Maxn], top1; //rid 新旧图映射，sta1拓扑排序，输出路径
void Tarjan(int u) {
//    cout << "Tarjan " << u << endl;
    int j, v;
    dfn[u] = low[u] = nindex++;
    sta.push(u);
    instack[u] = 1;
    for(j = e.last[u]; ~j; j = e.adj[j].next) {
        v = e.adj[j].v;
        if(-1 == dfn[v]) {
            Tarjan(v);
            if(low[u] > low[v]) low[u] = low[v];
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
        }while(u != v);
        rid[ncnt] = u;
        sta1[top1++] = ncnt;
        ncnt++;
    }
}

int color[Maxn];
void colorBlue(int u) {
    int j, v;
    color[u] = 2;
    for(j = e1.last[u]; j != -1; j = e1.adj[j].next) {
        v = e1.adj[j].v;
        if(!color[v]) colorBlue(v);
    }
}
void buildGraph() {
    int i, j, u, v, x, y;
    e1.init(ncnt);
    for(j = 0; j < e.tot; j++) {
        x = belong[u = e.adj[j].u];
        y = belong[v = e.adj[j].v];
        if(x != y) {
            e1.adde(y, x);//反向建图
        }
    }
}
int twoSat(int n) {
    int i, u, v, flag = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(instack, 0, sizeof(instack));
    memset(belong, -1, sizeof(belong));
    ncnt = 0; //缩点, 新点[0,ncnt)
    nindex = 1;
    top1 = 0;
    for(i = 0; i < 2*n; i++) {
        if(-1 == dfn[i]) {
            while(!sta.empty()) sta.pop();
//            cout << "xx " << endl;
            Tarjan(i);
        }
    }
    for(i = 0; i < 2 * n; i += 2) {
        if(belong[i] == belong[i + 1]) return false;
    }
//    //建新图
//    buildGraph();
//    memset(color, 0, sizeof(color));
//    for(i = 0; i < top1; i++) {
//        u = sta1[i];
//        if(!color[u]) {
//            color[u] = 1;
//            v = belong[rid[u] ^ 1];
//            colorBlue(v);
//        }
//    }
    return 1;
}
int dist[Maxn][Maxn], X[Maxn], Y[Maxn];
int n;
bool check(double r) {
//    cout << "check " << r << endl;
    r *= 2 * r;
    int i, j;
    e.init(2 * n);
    for(i = 0; i < 2 * n; i++) {
        for(j = i + 1; j < 2 * n; j++) {
            if((j ^ 1) == i) continue;
            if(dist[i][j] <= 2 * r) {
                e.adde(i, j ^ 1);
                e.adde(j, i ^ 1);
            }
        }
    }
    return twoSat(n);
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < 2 * n; i++) scanf("%d%d", &X[i], &Y[i]);
        for(i = 0; i < 2 * n; i++) {
            for(j = 0; j < 2 * n; j++) {
                dist[i][j] = SQ(X[i] - X[j]) + SQ(Y[i] - Y[j]);
            }
        }
        double l = 0, r = 1e10, mid;
        for(i = 0; i < 50; i++) {
            mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.2f\n", (l + r) /2);
    }
    return 0;
}

