#pragma comment(linker,"/STACK:100000000,100000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define LSON (r << 1)
#define RSON (r << 1 | 1)

#define Maxn 51111
#define Maxm 101111

struct node {
    int u, v, c;
    int next;
}e[Maxm];
int last[Maxn], tot;
int n, m, q;
int Value[Maxn];

int mx[Maxn << 2];

struct Chain {
    int size[Maxn], dep[Maxn], fa[Maxn], son[Maxn], top[Maxn], mp[Maxn], no[Maxn], llv[Maxn], lv[Maxn];
    int value[Maxn << 2], c[Maxn << 2];
    int que[Maxn], head, tail;
    int n;
    int root;
    node * e;
    int * last;
    int tot;
    int ncnt;

    void init(node ee[], int ll[], int tt, int nn, int r = 1) {
        e = ee; last = ll; tot = tt; n = nn; root = r;
        ncnt = 0;
        bfsinit(root);
        split(root, root);

        //debug(root);
        //for(int i = 0; i < tot; i += 2) {
            //printf("no %d\n", no[i/ 2]);
        //}

        build(1, 1, ncnt);
    }

    void debug(int u) {
        printf("node[%d]: size %d dep %d fa %d son %d top %d mp %d lv %d\n", u, size[u], dep[u], fa[u], son[u], top[u], mp[u], lv[u]);
        for(int j = last[u];j != -1; j = e[j].next) {
            if(e[j].v == fa[u]) continue;
            debug(e[j].v);
        }
    }


    void bfsinit(int root) { // calc size[], dep[], fa[], lv[]
        int i, j, k, u, v;
        for(i = 0; i <= n; ++i) {
            size[i] = 1;
            dep[i] = 0;
            fa[i] = son[i] = -1;
            lv[i] = -1;
        }
        head = tail = 0;
        que[tail++] = root;
        llv[root] = Value[root];
        while(head < tail) {
            u = que[head++];
            for(j = last[u]; j != -1; j = e[j].next) {
                v = e[j].v;
                if(v == fa[u]) continue;
                dep[v] = dep[u] + 1;
                fa[v] = u;
                llv[v] = Value[v];
                que[tail++] = v;
            }
        }
        for(i = tail - 1; i >= 0; --i) {
            u = que[i];
            size[fa[u]] += size[u];
            for(j = last[u], k = -1; j != -1; j = e[j].next) {
                v = e[j].v;
                if(v == fa[u]) continue;
                if(k == -1 || size[v] > size[k]) {
                    k = v;
                }
            }
            son[u] = k;
        }
    }

    void split(int u, int t) {
        int i, j, k, v;
        top[u] = t;
        mp[u] = ++ncnt;
        lv[ncnt] = llv[u];

        if(son[u] == -1) {
            return;
        }
        split(son[u], t);
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == fa[u]) continue;
            if(v != son[u]) {
                split(v, v);
            }
            no[j / 2] = mp[v];
        }
    }
    void build(int r, int lt, int rt) {
        c[r] = value[r] = 0;
        if(lt == rt) {
            value[r] = lv[lt];
            return;
        }
        int mid = (lt + rt) >> 1;
        build(LSON, lt, mid);
        build(RSON, mid + 1, rt);
    }

    void pushdown(int r, int lt, int rt) {
        if(c[r] == 0) return;
        if(lt == rt) {
            value[r] += c[r];
            c[r] = 0;
            return;
        }
        c[LSON] += c[r]; 
        c[RSON] += c[r];
        c[r] = 0;
    }

    void refresh(int r, int lt, int rt, int ll, int rr, int v) {
        //printf("refresh %d [%d %d] [%d %d] %d\n", r, lt, rt, ll, rr, v);
        if(c[r]) {
            pushdown(r, lt, rt);
        }
        if(ll <= lt && rt <= rr) {
            c[r] += v;
            return;
        }
        int mid = (lt + rt) >> 1;
        if(rr <= mid) {
            refresh(LSON, lt, mid, ll, rr, v);
        }
        else if(ll > mid) {
            refresh(RSON, mid + 1, rt, ll, rr, v);
        }
        else {
            refresh(LSON, lt, mid, ll, mid, v);
            refresh(RSON, mid + 1, rt, mid + 1, rr, v);
        }
    }

    int query(int r, int lt, int rt, int x) {
        //printf("query %d [%d %d] %d \n", r, lt, rt, x);
        if(c[r]) {
            pushdown(r, lt, rt);
        }
        if(lt == rt && lt == x) {
            return value[r];
        }
        int mid = (lt + rt) >> 1;
        if(x <= mid) {
            return query(LSON, lt, mid, x);
        }
        else if(mid < x) {
            return query(RSON, mid + 1, rt, x);
        }
    }
    void Refresh(int u, int v, int w) {
        while(1) {
            if(top[u] == top[v]) {
                if(mp[u] > mp[v]) swap(u, v);
                refresh(1, 1, ncnt, mp[u], mp[v], w);
                break;
            }
            if(dep[top[u]] > dep[top[v]]) {
                swap(u, v);
            }
            refresh(1, 1, ncnt, mp[top[v]], mp[v], w);
            v = fa[top[v]];
        }
    }
} chain;

void adde(int u, int v, int c = 0) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
}

int main() {
    int i, j, k, u, v, w;
    int te;
    char opt[20];
    while(scanf("%d%d%d", &n, &m, &q) != EOF) {
        for(i = 1; i <= n; ++i) scanf("%d", &Value[i]);
        tot = 0;
        for(i = 1; i <= n; ++i) last[i] = -1;
        for(i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            adde(u, v);
        }    
        chain.init(e, last, tot, n, 2);
        while(q--) {
            scanf("%s", opt);
            if(opt[0] == 'I') {
                scanf("%d%d%d", &u, &v, &w);
                chain.Refresh(u, v, w);
            }
            if(opt[0] == 'D') {
                scanf("%d%d%d", &u, &v, &w);
                chain.Refresh(u, v, -w);
            }
            else if(opt[0] == 'Q') {
                scanf("%d", &u);
                //printf("Q %d %d\n", u, chain.mp[u]);
                printf("%d\n", chain.query(1, 1, chain.ncnt, chain.mp[u]));
            }
        }
    }
    return 0;
}
