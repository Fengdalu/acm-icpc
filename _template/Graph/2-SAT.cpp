#include <iostream>
#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstring>

const int N = 500;
const int M = 2e6;
/*
 * dfn: 标号数组
 * low: 回向边数组
 */
int ind[N];
int to[M], nt[M];
int dfn[N], low[N];
int color[N];
bool vis[N];
int cnt, num, idn;
int ncnt;
std::stack<int>s;

void add(int i, int j) {
    cnt++;
    to[cnt] = j;
    nt[cnt] = ind[i];
    ind[i] = cnt;
}

void tarjan(int x) {
    if(dfn[x] != 0) return;
    low[x] = dfn[x] = ++num;
    vis[x] = true;
    s.push(x);
    for(int k = ind[x]; k != -1; k = nt[k]) {
        tarjan(to[k]);
        if(vis[to[k]]) low[x] = std::min(low[x], low[to[k]]);
    }
    if(dfn[x] == low[x]) {
        ncnt++;
        while(true) {
            int p = s.top();
            s.pop();
            color[p] = ncnt;
            vis[p] = false;
            if(p == x) break;
        }
    }
}

const int Maxn = 500;
const int Maxm = 50000;
int n, m;
int a[Maxm], b[Maxm], c[Maxm];

bool check() {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < 2 * n; i++) ind[i] = -1;
    int tot = n;
    num = idn = 0;
    cnt = 0;
    ncnt = 0;
    /*
     * 这里建图
     * 每个节点分为两个，选和不选
     * $(p->q)$, 表示选$p$一定要选$q$
     * 检查每个节点选和不选是否在同一个集合
     */
    for(int i = 0; i < 2 * n; i++) tarjan(i);
    for(int i = 0; i < n; i++) {
        if(color[i] == color[tot + i]) return false;
    }
    return true;
}
