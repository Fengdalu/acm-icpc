#include <bits/stdc++.h>
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

#define Maxn 200011

struct SEG {
    int sum, c, l, r; 
} tree[Maxn << 2];

int n, m;
int L[Maxn], R[Maxn], pos[Maxn];
struct node {
    int u, v, next;
}e[Maxn];
int tot, last[Maxn];
int N;
int used[Maxn];

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].next = last[v]; last[v] = tot++;
}

void dfs1(int u) {
    int j, v;
    L[u] = N++;
    for(j = last[u]; j != -1; j = e[j].next) {
        v = e[j].v;
        if(L[v] != -1) continue;
        dfs1(v);
    }
    R[u] = N;
}
void build(int root, int l, int r) {
    //printf("build root %d %d %d\n", root, l, r);
    tree[root].sum = tree[root].c = 0;
    tree[root].l = l; tree[root].r = r;
    if(l == r) {
        pos[l] = root;
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
}

vector<int> g[Maxn];
int ans[Maxn];

void refresh(int root, int l, int r, int c) {
    //printf("refresh %d %d %d %d %d %d\n", root, l, r, c, tree[root].l, tree[root].r);
    if(l <= tree[root].l && tree[root].r <= r) {
        tree[root].c += c;
        if(tree[root].c) tree[root].sum = tree[root].r - tree[root].l + 1;
        else if(tree[root].l == tree[root].r) tree[root].sum = 0;
        else tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
        return;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(l <= mid) {
        refresh(root << 1, l, r, c);
    }
    if(r > mid) {
        refresh(root << 1 | 1, l, r, c);
    }
    if(!tree[root].c) tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}

int query(int root, int l, int r) {
    if(l <= tree[root].l && tree[root].r <= r) {
        return tree[root].sum;
    }
    int mid = (tree[root].l + tree[root].r) >> 1;
    int ret = 0;
    if(l <= mid) {
        ret += query(root << 1, l, r);
    }
    if(r > mid) {
        ret += query(root << 1 | 1, l, r);
    }
    return ret;
}

void DEBUG(int root, int l, int r) {
    //printf("DEBUG %d %d %d sum %d c %d\n", root, l, r, tree[root].sum, tree[root].c);
    if(l == r) return;
    int mid = (l + r) >> 1;
    DEBUG(root << 1, l, mid);
    DEBUG(root << 1 | 1, mid + 1, r);
}

void dfs(int u, int from) {
    int i, j, k, v, w;
    //printf("\nStart%d\n", u);
    if(g[u].SZ > 0) {
        refresh(1, L[u], R[u] - 1, 1);
        used[u]++;
    }
    for(i = 0; i < g[u].SZ; i++) {
        v = g[u][i];
        used[v]++;
        refresh(1, L[v], R[v] - 1, 1);
    }
    //DEBUG(1, 1, n);
    ans[u] = query(1, 1, n);
    if(ans[u])
    ans[u]--;
    for(j = last[u]; j != -1; j = e[j].next) {
        if(j == from) continue;
        v = e[j].v;
        dfs(v, j ^ 1);
    }
    //DEBUG(1, 1, n);
    for(i = 0; i < g[u].SZ; i++) {
        used[v]--;
        v = g[u][i];
        refresh(1, L[v], R[v] - 1, -1);
    }
    if(g[u].SZ > 0) {
        used[u]--;
        refresh(1, L[u], R[u] - 1, -1);
    }
    //printf("\nEnd %d\n", u);
}

int main() {
    int i, j, k, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        tot = 0;
        for(i = 0; i <= n; i++) last[i] = -1;
        for(i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            adde(u, v);
        }
        for(i = 0; i <= 2 * n + 2; i++) {
            L[i] = R[i] = -1;
            pos[i] = -1;
        }
        N = 1;
        dfs1(1);
        for(i = 1; i <= n; i++) {
            //printf("%d L %d R %d\n", i, L[i], R[i]);
        }
        build(1, 1, n);
        for(i = 0; i <= n + 1; i++) g[i].clear();
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        memset(used, 0, sizeof(used));
        dfs(1, -1);
        for(i = 1; i <= n; i++) {
            printf("%d", ans[i]);
            if(i < n) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}
