#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

const int N = 100010;
std::vector<int> g[N];

typedef std::pair<int, int> PII;
typedef long long ll;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
int cntx;
int X[N];
namespace ST {
    /*
     * e: 线段树节点数组
     *    l, r: 左右节点指针
     *    sum: 区间和
     * rt: 主席树根节点
     * tot: 总节点个数
     */
    struct E {
        int l, r;
        int sum;
    }e[10000000];
    int rt[100010];
    int tot;

    /*
     * 建树，初始化调用，建立一颗空树
     */
    void build(int &rt, int l, int r) {
        rt = tot++;
        e[rt].sum = 0;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(e[rt].l, l, mid);
        build(e[rt].r, mid + 1, r);
    }

    /*
     * 插入新节点，向$w$位置插入节点，主席书中父亲结点为$fa$
     */
    void update(int &rt, int l, int r, int w, int fa) {
        rt = tot++;
        e[rt].l = e[fa].l;
        e[rt].r = e[fa].r;
        e[rt].sum = e[fa].sum + 1;
        if(l == r) return ;
        int mid = (l + r) >> 1;
        if(w <= mid) update(e[rt].l, l, mid, w, e[fa].l);
        else update(e[rt].r, mid + 1, r, w, e[fa].r);
    }

    /*
     * 查询，查询原图中$(a, b)$点对的信息，其中$c = lca(a, b)$
     * 计算时候加入$c$信息
     */
    int query(int a, int b, int l, int r, ll k) {
        int mid = (l + r) >> 1;
        if(l == r) return e[b].sum - e[a].sum;
        int left = e[e[b].l].sum - e[e[a].l].sum;
        if(k <= mid) return query(e[a].l, e[b].l, l, mid, k);
        else return left + query(e[a].r, e[b].r, mid + 1, r, k);
    }
}
using namespace ST;
using std::cout;
using std::endl;

int left[N], right[N];
int id[N];
int a[N];
int timeline = 0;
int inter[N];
int in[N];

void dfs(int x, int fa) {
    left[x] = timeline;
    for(int k = 0; k != g[x].size(); k++) {
        int v = g[x][k];
        dfs(v, x);
    }
    right[x] = timeline - 1;
    inter[timeline] = a[x];
    id[x] = timeline++;
}

inline void solve() {
    int n;
    ll K;
    scanf("%d%lld", &n, &K);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) X[i - 1] = a[i];
    std::sort(X, X + n);
    cntx = std::unique(X, X + n) - X;
    for(int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(X, X + cntx, a[i]) - X;
    }
    std::fill(in, in + n + 1, 0);
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x].push_back(y);
        in[y]++;
    }
    timeline = 1;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) dfs(i, i);
        //cout << endl;
    }
    /*
    cout << "timeline: ";
    cout << timeline << endl;
    for(int i = 1; i <= timeline; i++) cout << inter[i] << " "; cout << endl;
    cout << "LR" << endl;
    for(int i = 1; i <= n; i++)
        std::cout << left[i] << " " << right[i] << std::endl;

    cout << "=====" << endl;
    */
    tot = 0;
    build(rt[0], 0, cntx - 1);
    for(int i = 1; i <= timeline; i++) {
        update(rt[i], 0, cntx - 1, inter[i], rt[i - 1]);
    }
    ll ans = 0;
    /*
    for(int i = 0; i < cntx; i++) cout << X[i] <<" "; cout << endl;
    cout << "=====" << endl;
    */
    for(int i = 1; i <= n; i++) {
        if(left[i] > right[i]) continue;
        ll e = std::upper_bound(X, X + cntx, K / X[a[i]]) - X;
        e--;
        if(e == -1) continue;
        //cout << X[a[i]] << " " << X[e] << endl;
        ans += 1ll * query(rt[left[i] - 1], rt[right[i]], 0, cntx - 1, e);
    }
    cout << ans <<endl;
}

int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}

