#include <bits/stdc++.h>
#define cmax(x, y) x = std::max(x, y)
#define cmin(x, y) x = std::min(x, y)
const int N = 20000 + 5;
const int M = 300000 + 5;
const int MM = 300100;

typedef long long ll;
const int INF = 1e9+7;
const int POW = 20;
int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int dfn[N], low[N], head[N], etot, btot, n, m, nq, belong[N];
int p[N][POW];
int head1[N];
bool is_cut[N],visited[N];
std::stack<int> stack;
int ec[MM], ed[MM], ew[MM];
int in[N+10];
struct Edge {
    int v,next,belong;
    bool visited,is_cut;
} g[M<<1], g1[M<<1];

std::vector<int> edges[N+M];

void add_edge(int u,int v) {
    g[etot].belong = -1; g[etot].visited = g[etot].is_cut = false;
    g[etot].v = v; g[etot].next = head[u]; head[u] = etot ++;
}

void add1(int u, int v, Edge g[], int head[], int &etot) {
    g[etot].v = v; g1[etot].next = head[u]; head[u] = etot ++;
}

void tarjan(int u,int root,int tim) {
    dfn[u] = low[u] = tim;
    visited[u] = true;
    int child_count = 0;
    for (int i = head[u]; i != -1; i = g[i].next) {
        Edge &e = g[i];
        if (e.visited) continue;
        stack.push(i);
        g[i].visited = g[i^1].visited = true;
        if (visited[e.v]) {
            low[u] = std::min(low[u],dfn[e.v]);
            continue;
        }
        tarjan(e.v,root,tim+1);
        g[i].is_cut = g[i^1].is_cut = (low[e.v]>dfn[u] || g[i].is_cut);
        if (u!=root) is_cut[u] |= (low[e.v]>=dfn[u]);
        if (low[e.v]>=dfn[u] || u==root) {
            while (true) {
                int id = stack.top(); stack.pop();
                g[id].belong = g[id^1].belong = btot;
                if (id==i) break;
            }
            btot ++;
        }
        low[u] = std::min(low[e.v],low[u]);
        child_count ++;
    }
    if (u==root && child_count>1) is_cut[u] = true;
}

void bcc() {
    for (int i = 0; i < n; ++ i) {
        dfn[i] = 0;
        is_cut[i] = false;
        visited[i] = false;
    }
    btot = 0;
    for (int i = 0; i < n; ++ i) {
        if (!visited[i]) {
            tarjan(i,i,1);
        }
    }
}

void build() {
    std::fill(edges,edges+n+m,std::vector<int>());
    for (int u = 0; u < n; ++ u) {
        if (is_cut[u] || head[u]==-1) {
            int id = btot ++;
            belong[u] = id;
            for (int i = head[u]; i != -1; i = g[i].next) {
                Edge &e = g[i];
                int v = e.belong;
                edges[id].push_back(v);
                edges[v].push_back(id);
            }
        }
    }
    for (int u = 0; u < btot; ++ u) {
        std::sort(edges[u].begin(),edges[u].end());
        edges[u].erase(std::unique(edges[u].begin(),edges[u].end()), edges[u].end());
    }
    for (int i = 0; i < m; ++ i) {
        int u = g[i<<1].v;
        int v = g[i<<1|1].v;
        if (!is_cut[u]) belong[u] = g[i<<1].belong;
        if (!is_cut[v]) belong[v] = g[i<<1].belong;
    }
    std::fill(head1, head1+btot, -1);
    std::fill(in, in+btot, 0);
    int etot1 = 0;
    for(int i = 0; i < m; i++) {
        int u = belong[g[i<<1].v];
        int v = belong[g[i<<1|1].v];
        if(u == v) continue;
        //std::cout << "epc " << g[i<<1].v << " " << g[i<<1|1].v << std::endl;
        //std::cout << "upc " << v << " " << u << std::endl;
        add1(u, v, g1, head1, etot1);
        add1(v, u, g1, head1, etot1);
        //std::cout << "NEDGE "<< u << " " << v << std::endl;
        in[u]++, in[v]++;
    }
}

struct node
{
    int l, r;
    int w;
}f[N<<2];
int rt;

void dfs1(int x, int d)
{
    dep[x] = d;
    son[x] = 0;
    sz[x] = 1;
    //for(int i = 1; i < POW; i++) p[x][i] = p[p[x][i - 1]][i - 1];
    for(int k = head1[x]; k != -1; k = g1[k].next) {
        int t = g1[k].v;
        if(t != fa[x])
        {
            fa[t] = x;
            p[t][0] = x;
            dfs1(t, d + 1);
            sz[x] += sz[t];
            if(sz[t] > sz[son[x]]) son[x] = t;
        }

    }
}

int cnt2, cnt3;
void dfs2(int x, int tt)
{
    w[x] = ++cnt2;
    top[x] = tt;
    if(son[x]) dfs2(son[x], tt);
    for(int k = head1[x]; k != -1; k = g1[k].next) {
        int t =  g1[k].v;
        if(t != fa[x] && t != son[x])
            dfs2(t, t);
    }
}

int bt(int a, int b) {
    int x = cnt3++;
    if(a < b) {
        int mid = (a + b) / 2;
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
        f[x].w = INF;
    }
    else {
        f[x].w = INF;
    }
    return x;
}

void update(int x) {
    f[x].w = std::min(f[f[x].l].w, f[f[x].r].w);
}

int query(int rt, int l, int r, int a, int b) {
    if(a <= l && r <= b) return f[rt].w;
    int mid = (l + r) / 2;
    if(b <= mid) return query(f[rt].l, l, mid, a, b);
    else if(a > mid) return query(f[rt].r, mid + 1, r, a, b);
    else return std::min(query(f[rt].l, l, mid, a, b), query(f[rt].r, mid + 1, r, a, b));
}

void deal(int rt, int l, int r, int a, int b, int v) {
    if(a <= l && r <= b) {
        cmin(f[rt].w, v);
        return;
    }
    int mid = (l + r) / 2;
    if(b <= mid) deal(f[rt].l, l, mid, a, b, v);
    else if(a > mid) deal(f[rt].r, mid + 1, r, a, b, v);
    else { deal(f[rt].l, l, mid, a, b, v); deal(f[rt].r, mid + 1, r, a, b, v); }
    update(rt);
}

// `树上查询`
int query(int x, int y)
{
    int sum = INF;
    return std::min(sum, query(rt, 1, cnt2, w[x], w[y]));
    int fx = top[x], fy = top[y];
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            std::swap(x, y);
            std::swap(fx, fy);
        }
        cmin(sum, query(rt, 1, cnt2, w[fx], w[x]));
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) std::swap(x, y);
    return std::min(sum, query(rt, 1, cnt2, w[x], w[y]));
}

void deal(int x, int y, int v) {
    int fx = top[x], fy = top[y];
    int sum = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            std::swap(x, y);
            std::swap(fx, fy);
        }
        deal(rt, 1, cnt2, w[fx], w[x], v);
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) std::swap(x, y);
    deal(rt, 1, cnt2, w[x], w[y], v);
}


inline void solve() {
    if(scanf("%d%d",&n,&m) != 2) exit(0);
    std::fill(head,head+n,-1); etot = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++ i) {
        int a,b,C,D;
        scanf("%d%d%d%d",&a,&b,&C,&D); a --; b --;
        if(D == 0) {
            ec[cnt] = a;
            ed[cnt] = b;
            ew[cnt] = C;
            cnt++;
            continue;
        }
        add_edge(a,b);
        add_edge(b,a);
    }
    bcc();
    build();
    for(int i = 0; i < n; i++) std::cout << belong[i] << " "; std::cout << std::endl;
    for(int i = 0; i < n; i++) std::cout << is_cut[i] << " "; std::cout << std::endl;
    cnt2 = cnt3 = 0;
    int rt1 = -1;
    for(int i = 0; rt1 == -1 && i < btot; i++)
        if(in[i] == 1) rt1 = i;
    for(int i = 0; i < POW; i++) p[rt1][i] = rt1;
    dfs1(rt1, 0);
    std::cout << "BST" << std::endl;
    dfs2(rt1, 0);
    rt = bt(1, cnt2);
    for(int i = 0; i < cnt; i++) {
        int u = belong[ec[i]];
        int v = belong[ed[i]];
        if(dep[u] > dep[v]) std::swap(u, v);
        if(u == v) continue;
        if(dep[u] + 1 == dep[v]) continue;
        //std::cout << "PRE " << u << " " << v << std::endl;
        int offset = dep[v] - dep[u] - 1;
        int tmp = v;
        for(int i = 0; i < POW; i++)
            if(offset & (1 << i)) tmp = p[tmp][i];
        u = tmp;
        v = fa[v];
        //std::cout << "UPD "<< u << " " << v << " " << ew[i] << std::endl;
        deal(u, v, ew[i]);
    }
    for(int i = 0; i < n; i++) {
        if(is_cut[i]) {
            //std::cout << "BL" << belong[i] << std::endl;
            int w = query(belong[i], belong[i]);
            if(w == INF) printf("inf\n");
            else printf("%d\n", w);
        }
        else puts("0");
    }
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) solve();
    return 0;
}
