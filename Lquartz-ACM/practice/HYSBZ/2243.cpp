#include <cstdio>
#include <ctime>
#include <algorithm>
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
const int Maxn = 101111;
const int Maxm = 201111;
struct node {
    int u, v, c;
    int next;
} e[Maxm];
int tot, last[Maxn];
int root;
int n, m, q;
int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], mp[Maxn], lv[Maxn], emp[Maxn], llv[Maxn];
int ncnt;
int que[Maxn], head, tail;
PII sta[Maxn];
int color[Maxn];

int lc[Maxn << 2], rc[Maxn << 2], sum[Maxn << 2], mark[Maxn << 2];

void adde(int u, int v) {
    //printf("adde %d %d\n", u, v);
    e[tot]. u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}
void bfsinit(int root = 1) {//siz, dep, parent, parent, llv, emp
    int i, j, k, u, v, w, dmax;
    head = tail = 0;
    que[tail++] = root;
    parent[root] = -1;
    dep[root] = 0;
    llv[root] = color[root];
    while(head < tail) {
        u = que[head++];
        siz[u] = 1;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            parent[v] = u;
            dep[v] = dep[u] + 1;
            llv[v] = color[v];
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

void debug() {
    for(int u = 1; u <= n; ++u) {
        printf("debug %d siz %d dep %d top %d son %d mp %d \n", u, siz[u], dep[u], top[u], son[u], mp[u]);
    }
}

void split(int root = 1) {
    int i, j, k, u, v, w, t;
    head = 0;
    ncnt = 0;
    sta[head++] = MP(root, root);
    while(head) {
        --head;
        u = sta[head].AA; t = sta[head].BB;
        //printf("sta %d %d\n", u, t);
        top[u] = t;
        mp[u] = ++ncnt;
        lv[ncnt] = llv[u];
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(v == parent[u]) continue;
            if(v != son[u]) sta[head++] = MP(v, v);
        }
        if(son[u] != -1) sta[head++] = MP(son[u], t);
    }
}
void pushup(int r, int lt, int rt) {
    lc[r] = lc[LSON]; rc[r] = rc[RSON];
    sum[r] = sum[LSON] + sum[RSON];
    if(rc[LSON] == lc[RSON]) sum[r]--;
}
void pushdown(int r, int lt, int rt) {
    if(lt == rt) return;
    if(mark[r] != -1) {
        lc[LSON] = rc[LSON] = lc[RSON] = rc[RSON] = mark[r];
        mark[LSON] = mark[RSON] = mark[r];
        mark[r] = -1;
        sum[LSON] = sum[RSON] = 1;
    }
}
void build(int r, int lt, int rt) {
    mark[r] = -1;
    if(lt == rt) {
        lc[r] = rc[r] = lv[lt];
        sum[r] = 1;
        return;
    }
    int mid = (lt + rt) >> 1;
    build(LSON, lt, mid);
    build(RSON, mid + 1, rt);
    pushup(r, lt, rt);
}

void refresh(int r, int lt, int rt, int ll, int rr, int c) {
    //printf("refresh %d [%d, %d] [%d, %d] %d\n", r, lt, rt, ll, rr, c);
    if(ll <= lt && rt <= rr) {
        mark[r] = lc[r] = rc[r] = c;
        sum[r] = 1;
        return ;
    }
    pushdown(r, lt, rt);
    int mid = (lt + rt) >> 1;
    if(rr <= mid) refresh(LSON, lt, mid, ll, rr, c);
    else if(ll > mid) refresh(RSON, mid + 1, rt, ll, rr, c);
    else {
        refresh(LSON, lt, mid, ll, mid, c);
        refresh(RSON, mid + 1, rt, mid + 1, rr, c);
    }
    pushup(r, lt, rt);
}

int query(int r, int lt, int rt, int ll, int rr) {
    //printf("query %d [%d, %d] [%d, %d]\n", r, lt, rt, ll, rr);
    if(ll <= lt && rt <= rr) return sum[r];
    pushdown(r, lt, rt);
    int mid = (lt + rt) >> 1;
    int ret = 0;
    if(rr <= mid) ret = query(LSON, lt, mid, ll, rr);
    else if(ll > mid) ret = query(RSON, mid + 1, rt, ll, rr);
    else {
        ret = query(LSON, lt, mid, ll, mid) + query(RSON, mid + 1, rt, mid + 1, rr);
        if(rc[LSON] == lc[RSON]) ret--;
    }
    pushup(r, lt, rt);
    return ret;
}

void Change(int u, int v, int c) {
    while(1) {
        if(top[u] == top[v]) {
            if(mp[u] > mp[v]) swap(u, v);
            refresh(1, 1, ncnt, mp[u], mp[v], c);
            break;
        }
        if(dep[top[u]] > dep[top[v]]) swap(u, v);
        refresh(1, 1, ncnt, mp[top[v]], mp[v], c);
        v = parent[top[v]];
    }
}

int queryc(int r, int lt, int rt, int x) {
    pushdown(r, lt, rt);
    int ret;
    if(lt == rt && x == lt) {
        return lc[r];
    }
    int mid = (lt + rt) >> 1;
    if(x <= mid) ret = queryc(LSON, lt, mid, x);
    else ret = queryc(RSON, mid + 1, rt, x);
    return ret;
}

int Query(int u, int v) {
    int ret = 0;
    int ct, cp;
    while(1) {
        if(top[u] == top[v]) {
            if(mp[u] > mp[v]) swap(u, v);
            ret += query(1, 1, ncnt, mp[u], mp[v]);
            break;
        }
        if(dep[top[u]] > dep[top[v]]) swap(u, v);
        ret += query(1, 1, ncnt, mp[top[v]], mp[v]);
        ct = queryc(1, 1, ncnt, mp[top[v]]);
        cp = queryc(1, 1, ncnt, mp[parent[top[v]]]);
        if(ct == cp) ret--;
        //printf("u %d v %d ret %d\n", u, v, ret);
        v = parent[top[v]];
    }
    return ret;
}
char opt[100];
int main() {
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    int i, j, k, u, v, w;
    while(scanf("%d%d", &n, &q) != EOF) {
        m = n - 1;
        for(i = 1; i <= n; ++i) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; ++i) scanf("%d", &color[i]);
        for(i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            adde(u, v);
            adde(v, u);
        }
        root = 1;
        //root = rand() % n + 1;
        bfsinit(root);
        split(root);
        //debug();
        build(1, 1, ncnt);
        while(q--) {
            scanf("%s", opt);
            if(opt[0] == 'C') {
                scanf("%d%d%d", &u, &v, &w);
                Change(u, v, w);
            }
            else if(opt[0] == 'Q') {
                scanf("%d%d", &u, &v);
                printf("%d\n", Query(u, v));
            }
        }
    }

    return 0;
}
