#pragma comment(linker,"/STACK:100000000,100000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;
#define MP make_pair
#define AA first
#define BB second
typedef pair<int,int> PII;
#define LSON (r << 1)
#define RSON (r << 1 | 1)

#define Maxn 101111
#define Maxm 201111

struct node {
    int u, v, c;
    int next;
}e[Maxm];
int last[Maxn], tot;
int n, m, q, st;

void adde(int u, int v, int c = 0) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
}

int sum[Maxn << 2];

//siz, dep, son, top, parent, mp, emp(边是谁的父边), ncnt线段树映射计数器
int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], lv[Maxn], mp[Maxn], emp[Maxn], ncnt;
//que用于bfsinit, sta, cur用于手写栈, head代替top
int que[Maxn], head, tail;
PII sta[Maxn];
int cur[Maxn];
int llv[Maxn];

void bfsinit(int root = 1) { // siz[], dep[], son[], parent[], llv[], emp[]
    int i, j, k, u, v, w;
    int dmax;
    head = tail = 0;
    dep[root] = 0;
    parent[root] = -1;
    que[tail++] = root;
    while(head < tail) {
        u = que[head++];
        siz[u] = 1;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            parent[v] = u;
            dep[v] = dep[u] + 1;
            //记录结点v初始值OR其父边的值
            llv[v] = e[j].c;
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
            if(dmax == -1 || siz[dmax] < siz[v]) dmax = v;
        }
        son[u] = dmax;
    }
}

void split(int root = 1) { // 手写栈 top[], lv[], mp[]
    int i, j, k, u, v, w;
    int fa;
    for(i = 0; i <= n; ++i) cur[i] = last[i];
    head = 0;
    sta[head++] = MP(root, root);
    ncnt = 0;
    while(head) {
        head--;
        u = sta[head].AA; fa = sta[head].BB;        
        top[u] = fa;
        mp[u] = ++ncnt;
        lv[ncnt] = llv[u];
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            if(v != son[u]) {
                sta[head++] = MP(v, v);
            }
        }
        if(son[u] != -1) {
            sta[head++] = MP(son[u], fa);
        }
    }
}

void debug() {
    for(int i = 1; i <= n; ++i) {
        int u = i;
        printf("node[%d]: siz %d dep %d parent %d son %d top %d mp %d lv %d\n", u, siz[u], dep[u], parent[u], son[u], top[u], mp[u], lv[u]);
        
    }
}

void build(int r, int lt, int rt) {
    if(lt == rt) {
        sum[r] = lv[lt];
        return;
    }
    int mid = (lt + rt) >> 1;
    build(LSON, lt, mid);
    build(RSON, mid + 1, rt);
    sum[r] = sum[LSON] + sum[RSON];
}

int query(int r, int lt, int rt, int ll, int rr) {
    if(ll <= lt && rt <= rr) {
        return sum[r];
    }
    int mid = (lt + rt) >> 1;
    if(rr <= mid) {
        return query(LSON, lt, mid, ll, rr);
    }
    else if(ll > mid) {
        return query(RSON, mid + 1, rt, ll, rr);
    }
    else {
        return query(LSON, lt, mid, ll, mid) + query(RSON, mid + 1, rt, mid + 1, rr);
    }
}

void refresh(int r, int lt, int rt, int x, int value) {
    if(lt == rt && lt == x) {
        sum[r] = value;
        return;
    }
    int mid = (lt + rt) >> 1;
    if(x <= mid) {
        refresh(LSON, lt, mid, x, value);
    }
    else {
        refresh(RSON, mid + 1, rt, x, value);
    }
    sum[r] = sum[LSON] + sum[RSON];
}

int Query(int u, int v) {
    int ret = 0;
    while(1) {
        if(top[u] == top[v]) {
            if(dep[u] > dep[v]) swap(u, v);
            if(mp[u] < mp[v]) {
                ret += query(1, 1, ncnt, mp[u] + 1, mp[v]);
            }
            break;
        }
        else {
            if(dep[top[u]] > dep[top[v]]) swap(u, v);
            ret += query(1, 1, ncnt, mp[top[v]], mp[v]);
            v = parent[top[v]];
        }
    }
    return ret;
}


int main() {
    int i, j, k, u, v, w;
    int te;
    int opt;
    while(scanf("%d%d%d", &n, &q, &st) != EOF) {
        m = n - 1;
        tot = 0;
        for(i = 1; i <= n; ++i) last[i] = -1;
        for(i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }    
        bfsinit(1);
        split(1);
        //debug();
        build(1, 1, ncnt);
        while(q--) {
            scanf("%d", &opt);
            if(opt == 0) {
                scanf("%d", &u);
                printf("%d\n", Query(st, u));
                st = u;
            }
            else if(opt == 1) {
                scanf("%d%d", &k, &w);
                --k;
                refresh(1, 1, ncnt, mp[emp[k]], w);
            }
        }
    }
    return 0;
}
