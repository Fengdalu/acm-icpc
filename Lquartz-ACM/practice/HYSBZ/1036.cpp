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
#define LSON (r<<1)
#define RSON (r<<1|1)
const int Maxn = 31111;
const int Maxm = Maxn << 1;
const int INF = 1000000000;
struct node {
    int u, v, next;
}e[Maxm];
int tot, last[Maxn];
int n, q;

int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], mp[Maxn], emp[Maxn], lv[Maxn], llv[Maxn];
int que[Maxn], head, tail;
PII sta[Maxn];
int ncnt;
int root;

int sum[Maxn << 2], mx[Maxn << 2];
int value[Maxn];

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}

void bfsinit(int root = 1) {
    int i, j, k, u, v, w, dmax;
    parent[root] = -1;
    dep[root] = 0;
    llv[root] = value[root];
    head = tail = 0;
    que[tail++] = root;
    while(head < tail) {
        u = que[head++];
        siz[u] = 1;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            parent[v] = u;
            dep[v] = dep[u] + 1;
            llv[v] = value[v];
            emp[j / 2] = v;

            que[tail++] = v;
        }
    }
    for(i = tail - 1; i >= 0; --i) {
        u = que[i];
        dmax = -1;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            siz[u] += siz[v];
            if(dmax == -1 || siz[v] > siz[dmax]) dmax = v;
        }
        son[u] = dmax;
    }
}

void split(int root = 1) {
    int i, j, u, v, t;
    head = 0;
    sta[head++] = MP(root, root);
    ncnt = 0;
    while(head) {
        --head;
        u = sta[head].AA; t = sta[head].BB;
        //printf("split %d %d %d\n", u, t, head);
        mp[u] = ++ncnt;
        lv[ncnt] = llv[u];
        top[u] = t;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            if(v != son[u]) {
                sta[head++] = MP(v, v);
            }
        }
        if(son[u] != -1) {
            sta[head++] = MP(son[u], t);
        }
    }
}

void build(int r, int lt, int rt) {
    //printf("build %d %d %d\n", r, ll, rr);
    if(lt == rt) {
        mx[r] = sum[r] = lv[lt];
        return;
    }
    int mid = (lt + rt) >> 1;
    build(LSON, lt, mid);
    build(RSON, mid + 1, rt);
    mx[r] = max(mx[LSON], mx[RSON]);
    sum[r] = sum[LSON] + sum[RSON];
}

void refresh(int r, int lt, int rt, int x, int value) {
    //printf("refresh %d [%d, %d] %d %d\n", r, lt[r], rt[r], x, value);
    if(lt == rt) {
        mx[r] = sum[r] = value;
        return;
    }
    int mid = (lt + rt) >> 1;
    if(x <= mid) refresh(LSON, lt, mid, x, value);
    else refresh(RSON, mid + 1, rt, x, value);
    mx[r] = max(mx[LSON], mx[RSON]);
    sum[r] = sum[LSON] + sum[RSON];
}

void query(int r, int lt, int rt, int ll, int rr, int & tmax, int & tsum) {
    //printf("query %d [%d, %d] [%d, %d] %d %d\n", r, lt[r], rt[r], ll, rr, tmax, tsum);
    if(ll <= lt && rt <= rr) {
        cmax(tmax, mx[r]);
        tsum += sum[r];
        return;
    }
    int mid = (lt + rt) >> 1;
    if(rr <= mid) query(LSON, lt, mid, ll, rr, tmax, tsum);
    else if(ll > mid) query(RSON, mid + 1, rt, ll, rr, tmax, tsum);
    else {
        query(LSON, lt, mid, ll, mid,  tmax, tsum);
        query(RSON, mid + 1, rt, mid + 1, rr, tmax, tsum);
    }
}

int Query(int u, int v, int tt) {
    int dmax, dsum, tmax, tsum;
    dmax = -INF;
    dsum = 0;
    while(1) {
        if(top[u] == top[v]) {
            if(mp[u] > mp[v]) swap(u, v);
            query(1, 1, ncnt, mp[u], mp[v], tmax = -INF, tsum = 0);
            cmax(dmax, tmax);
            dsum += tsum;
            break;
        }
        if(dep[top[u]] > dep[top[v]]) swap(u, v);
        query(1, 1, ncnt, mp[top[v]], mp[v], tmax = -INF, tsum = 0);
        cmax(dmax, tmax);
        dsum += tsum;
        v = parent[top[v]];
    }
    if(tt == 0) return dmax;
    else return dsum;
}

char opt[100];
int main() {
    int i,j,k,u,v,w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        tot = 0;
        for(i = 1; i <= n; ++i) last[i] = -1;
        for(i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            adde(u, v);
            adde(v, u);
        }
        for(i = 1; i <= n; ++i) scanf("%d", &value[i]);
        ncnt = 0;
        root = 1;
        bfsinit(root);
        split(root);
        build(1, 1, ncnt);
        scanf("%d", &q);
        while(q--) {
            scanf("%s", opt);
            if(opt[0] == 'C') {
                scanf("%d%d", &u, &w);
                refresh(1, 1, ncnt, mp[u], w);
            }
            else if(opt[1] == 'M') {
                scanf("%d%d", &u, &v);
                printf("%d\n", Query(u, v, 0));
            }
            else if(opt[1] == 'S') {
                scanf("%d%d", &u, &v);
                printf("%d\n", Query(u, v, 1));
            }
        }
    }
    return 0;
}
