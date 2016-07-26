#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int maxm = 200010;
const int maxn = 5010;
struct edge {
    int u, v, nt, c;
    bool vis;
}g[maxm];
int ind[maxn], dfn[maxn], low[maxn];
int cut[maxn];
bool vis[maxn];
int cnt, num, btt;
int fa[maxn];
int ne[maxn];
vector<int>p[maxn];
stack<int>st;


void add(int a, int b) {
    auto &t = g[cnt++];
    t.u = a;
    t.v = b;
    t.c = -1;
    t.nt = ind[a];
    t.vis = false;
    ind[a] = cnt - 1;
}

void tarjan(int rt) {
    dfn[rt] = low[rt] = ++num;
    vis[rt] = true;
    for(int k = ind[rt]; k != -1; k = g[k].nt) {
        auto &e = g[k];
        if(e.vis) continue;
        g[k].vis = g[k ^ 1].vis = true;
        st.push(k);
        if(vis[e.v]) {
            low[rt] = min(low[rt], low[e.v]);
            continue;
        }
        tarjan(e.v);
        if(low[e.v] >= dfn[rt]) {
            btt++;
            ne[btt] = 0;
            while(true) {
                int e = st.top(); st.pop();
                p[g[e].u].push_back(btt);
                p[g[e].v].push_back(btt);
                g[e].c = btt;
                ne[btt]++;
                if(k == e) break;
            }
        }
        low[rt] = min(low[rt], low[e.v]);
    }
}

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m, q;
    int cas = 1;
    while(~scanf("%d%d%d", &n, &m, &q) &&n&&m&&q) {
        num = btt = cnt = 0;
        for(int i = 0; i < n; i++) ind[i] = -1;
        for(int i = 0; i < n; i++) vis[i] = 0;
        for(int i = 0; i < n; i++) fa[i] = i;
        for(int i = 0; i < m; i++) {
            int x, y; scanf("%d%d", &x, &y);
            fa[find(x)] = find(y);
            add(x, y);
            add(y, x);
        }
        for(int i = 0; i < n; i++) p[i].clear();
        for(int i = 0; i < n; i++) tarjan(i);
        for(int i = 0; i < n; i++) {
            sort(p[i].begin(), p[i].end());
            p[i].resize(unique(p[i].begin(), p[i].end()) - p[i].begin());
        }
        printf("Case %d:\n", cas++);
        for(int i = 0; i < q; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int flag = -1;
            for(auto &a: p[x])
            if(flag == -1)
                for(auto &b: p[y])
                    if(a == b) flag = a;
            if(~flag) {
                if(ne[flag] > 1) puts("two or more");
                else puts("one");
            }
            else if(find(x) == find(y)) puts("one");
            else puts("zero");
        }
    }
    return 0;
}
