#include <bits/stdc++.h>
using namespace std;

#define LSON (r << 1)
#define RSON (r << 1 | 1)

#define Maxn 11111
#define Maxm 21111

struct node {
    int u, v, c;
    int next;
}e[Maxm];
int last[Maxn], tot;
int n;

int lv[Maxn];
int mx[Maxn << 2];

struct Chain {
    int size[Maxn], dep[Maxn], fa[Maxn], son[Maxn], top[Maxn], mp[Maxn], no[Maxn], llv[Maxn];
    int que[Maxn], head, tail;
    int n;
    int root;
    node * e;
    int * last;
    int tot;
    int * lv;
    int ncnt;

    void init(node ee[], int ll[], int tt, int nn, int vv[], int r = 1) {
        e = ee; last = ll; tot = tt; n = nn; lv = vv; root = r;
        ncnt = 0;
        bfsinit(root);
        split(root, root);
        //debug(root);
        //for(int i = 0; i < tot; i += 2) {
            //printf("no %d\n", no[i/ 2]);
        //}
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
        while(head < tail) {
            u = que[head++];
            for(j = last[u]; j != -1; j = e[j].next) {
                v = e[j].v;
                if(v == fa[u]) continue;
                dep[v] = dep[u] + 1;
                fa[v] = u;
                llv[v] = e[j].c;
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
} chain;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
}

void build(int r, int lt, int rt) {
     if(lt == rt) {
        mx[r] = lv[lt];
        return;
     }
     int mid = (lt + rt) >> 1;
     build(LSON, lt, mid);
     build(RSON, mid + 1, rt);
     mx[r] = max(mx[LSON], mx[RSON]);
}

void refresh(int r, int lt, int rt, int x, int v) {
    if(lt == rt && lt == x) {
        mx[r] = v;
        return;
    }
    int mid = (lt + rt) >> 1;
    if(x <= mid) {
        refresh(LSON, lt, mid, x, v);
    }
    else {
        refresh(RSON, mid + 1, rt, x, v);
    }
    mx[r] = max(mx[LSON], mx[RSON]);
}

int query(int r, int lt, int rt, int ll, int rr) {
    //printf("query %d %d %d %d %d \n", r, lt, rt, ll, rr);
    if(ll <= lt && rt <= rr) {
        return mx[r];
    }
    int mid = (lt + rt) >> 1;
    if(rr <= mid) {
        return query(LSON, lt, mid, ll, rr);
    }
    else if(mid < ll) {
        return query(RSON, mid + 1, rt, ll, rr);
    }
    else {
        int tp = query(LSON, lt, mid, ll, mid);
        return max(tp, query(RSON, mid + 1, rt, mid + 1, rr));
    }
}

int Query(int u, int v) {
    int ret = -1;
    while(1) {
        //printf("ret = %d\n", ret);
        if(chain.top[u] == chain.top[v]) {
            if(chain.mp[u] > chain.mp[v]) swap(u, v);
            if(chain.mp[u] < chain.mp[v]) {
                ret = max(ret, query(1, 1, chain.ncnt, chain.mp[u] + 1, chain.mp[v]));
            }
            break;
        }
        else {
            if(chain.dep[chain.top[u]] > chain.dep[chain.top[v]]) swap(u, v);
            ret = max(ret, query(1, 1, chain.ncnt, chain.mp[chain.top[v]], chain.mp[v]));
            v = chain.top[v];
            v = chain.fa[v];
        }
    }

    return ret;
}

int main() {
    int i, j, k, u, v, w;
    int te;
    char opt[20];
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ++ca) {
        scanf("%d", &n);
        tot = 0;
        for(i = 1; i <= n; ++i) last[i] = -1;
        for(i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }    
        chain.init(e, last, tot, n, lv);
        build(1, 1, chain.ncnt);
        while(1) {
            scanf("%s", opt);
            if(opt[0] == 'D') break;
            if(opt[0] == 'C') {
                scanf("%d%d", &u, &w);
                u--;
                refresh(1, 1, chain.ncnt, chain.no[u], w);
            }
            else if(opt[0] == 'Q') {
                scanf("%d%d", &u, &v);
                printf("%d\n", Query(u, v));
            }
        }
    }
    return 0;
}
