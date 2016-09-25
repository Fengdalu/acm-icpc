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
const int INF = 0x3f7f7f7f;
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
#define Maxn 21111
#define Maxm 41111

struct node {
    int u, v, c;
    int next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
}

int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], mp[Maxn], lv[Maxn], llv[Maxn], emap[Maxn];
int ncnt;
int que[Maxn], head, tail;
PII sta[Maxn];
int cur[Maxn];

int mx[Maxn << 2], mn[Maxn << 2], c[Maxn << 2];

void bfsinit(int root = 1) { //siz[], dep[], son[], llv[], emap[], parent[]
    int i, j, k, u, v, w;
    int dmax;
    head = tail = 0;
    dep[root] = 0;
    parent[root] = -1;
    que[tail++] = root;
    llv[root] = 0;
    while(head < tail) {
	u = que[head++];
	siz[u] = 1;
	for(j = last[u]; j != -1; j = e[j].next) {
	    v = e[j].v;
	    if(v == parent[u]) continue;
	    parent[v] = u;
	    dep[v] = dep[u] + 1;
	    llv[v] = e[j].c;
	    emap[j / 2] = v;
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

void split(int root = 1) {
    int i, j, k, u, v, w;
    int t;
    ncnt = 0;
    head = 0;
    sta[head++] = MP(root, root);
    while(head) {
	head--;
	u = sta[head].AA; t = sta[head].BB;
	top[u] = t;
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
	    sta[head++] = MP(son[u], t);
	}
    }
}

void debug() {
    int u;
    for(u = 1; u <= n; ++u) {
	printf("debug %d siz %d son %d dep %d top %d parent %d llv %d mp %d\n", u, siz[u], son[u], dep[u], top[u], parent[u], llv[u], mp[u]);
    }
}

void build(int r, int lt, int rt) {
    //printf("build %d [%d, %d]\n", r, lt, rt);
    c[r] = 1;
    if(lt == rt) {
	mx[r] = mn[r] = lv[lt];
	return;
    }
    int mid = (lt + rt) >> 1;
    build(LSON, lt, mid);
    build(RSON, mid + 1, rt);
    mx[r] = max(mx[LSON], mx[RSON]);
    mn[r] = min(mn[LSON], mn[RSON]);
}
void pushdown(int r, int lt, int rt) {
    if(lt == rt) {
	return;
    }
    if(c[r] == 1) return;
    mx[LSON] *= -1;
    mn[LSON] *= -1;
    swap(mx[LSON], mn[LSON]);
    mx[RSON] *= -1;
    mn[RSON] *= -1;
    swap(mx[RSON], mn[RSON]);
    c[LSON] *= -1; 
    c[RSON] *= -1;
    c[r] = 1;
}

int query(int r, int lt, int rt, int ll, int rr) {
    //printf("query %d [%d, %d] [%d, %d]\n", r, lt, rt, ll, rr);
    pushdown(r, lt, rt);
    if(ll <= lt && rt <= rr) {
	return mx[r];
    }
    int mid = (lt + rt) >> 1;
    if(rr <= mid) return query(LSON, lt, mid, ll, rr);
    else if(ll > mid) return query(RSON, mid + 1, rt, ll, rr);
    else {
	return max(query(LSON, lt, mid, ll, mid),
		    query(RSON, mid + 1, rt, mid + 1, rr));
    }
    mx[r] = max(mx[LSON], mx[RSON]);
    mn[r] = min(mn[LSON], mn[RSON]);
}

int Query(int u, int v) {
    int ret = -INF;
    while(1) {
	//printf("Query %d %d %d\n", u, v, ret);
	if(top[u] == top[v]) {
	    if(mp[u] > mp[v]) swap(u, v);
	    if(mp[u] < mp[v]) cmax(ret, query(1, 1, ncnt, mp[u] + 1, mp[v]));
	    break;
	}
	if(dep[top[u]] > dep[top[v]]) swap(u, v);
	cmax(ret, query(1, 1, ncnt, mp[top[v]], mp[v]));
	v = parent[top[v]];
    }
    return ret;
}


void refresh(int r, int lt, int rt, int ll, int rr, int value, int t) {
    //printf("refresh %d [%d, %d] [%d, %d] %d %d\n", r, lt, rt, ll, rr, value, t);
    if(ll <= lt && rt <= rr) {
	if(t == 0) {
	    mx[r] = mn[r] = value;
	    c[r] = 1;
	}
	else if(t == 1){
	    c[r] *= -1;
	    swap(mx[r], mn[r]);
	    mx[r] *= -1;
	    mn[r] *= -1;
	}
	return;
    }
    pushdown(r, lt, rt);
    int mid = (lt + rt) >> 1;
    if(rr <= mid) refresh(LSON, lt, mid, ll, rr, value, t);
    else if(ll > mid) refresh(RSON, mid + 1, rt, ll, rr, value, t);
    else {
	refresh(LSON, lt, mid, ll, mid, value, t);
	refresh(RSON, mid + 1, rt, mid + 1, rr, value, t);
    }
    mx[r] = max(mx[LSON], mx[RSON]);
    mn[r] = min(mn[LSON], mn[RSON]);
}

void Refresh(int u, int v) {
    while(1) {
	if(top[u] == top[v]) {
	    if(mp[u] > mp[v]) swap(u, v);
	    if(mp[u] < mp[v]) refresh(1, 1, ncnt, mp[u] + 1, mp[v], 0, 1);
	    break;
	}
	if(dep[top[u]] > dep[top[v]]) swap(u, v);
	refresh(1, 1, ncnt, mp[top[v]], mp[v], 0, 1);
	v = parent[top[v]];
    }
}

int main() {
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    int i, j, k, u, v, w;
    int te;
    char opt[100];
    scanf("%d", &te); 
    srand(time(NULL));
    for(int ca = 1; ca <= te; ++ca) {
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) last[i] = -1;
	tot = 0;
	for(i = 1; i < n; ++i) {
	    scanf("%d%d%d", &u, &v, &w);
	    adde(u, v, w);
	}
	//int root = rand() % n + 1;
	int root = 1;
	bfsinit(root);
	split(root);
	//debug();
	build(1, 1, ncnt);
	while(1) {
	    scanf("%s", opt);
	    if(opt[0] == 'D') break;
	    if(opt[0] == 'C') {
		scanf("%d%d", &k, &w);
		--k;
		refresh(1, 1, ncnt, mp[emap[k]], mp[emap[k]], w, 0);
	    }
	    else if(opt[0] == 'N') {
		scanf("%d%d", &u, &v);
		Refresh(u, v);
	    }
	    else if(opt[0] == 'Q') {
		scanf("%d%d", &u, &v);
		printf("%d\n", Query(u, v));
	    }
	}

    }
    return 0;
}
