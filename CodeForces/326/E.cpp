#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= (n); i++)
#define REP(i, L, R) for(int i = (L); i <= (R); i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/
#define MID(x, y) (((x) + (y)) >> 1)
#define N 100010
#define M (2 * N)

int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int a[N], b[N];
LL c[N];
int ind[N];
int t[M], nt[M];
int cnt1, cnt2, cnt3;
int n, m;
int ROOT = 1;

struct obj
{
    int a[15];
    int cnt;
    obj(){ cnt = 0; }
    void add(int x) { a[cnt++] = x; }
    int size() { return cnt; }
    void Sort() { sort(a, a + cnt); }
};


struct node
{
    int l, r;
    int a, b;
    obj s;
}f[M];
int rt;


void dfs1(int x, int d)
{
    dep[x] = d;
    son[x] = 0;
    sz[x] = 1;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x;
        dfs1(t[k], d + 1);
        sz[x] += sz[t[k]];
        if(sz[t[k]] > sz[son[x]]) son[x] = t[k];
    }
}

void dfs2(int x, int tt)
{
    w[x] = ++cnt2;
    top[x] = tt;
    if(son[x]) dfs2(son[x], tt);
    for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x] && t[k] != son[x])
        dfs2(t[k], t[k]);
}

LL add(int a, int b)
{
    t[cnt1] = b;
    nt[cnt1] = ind[a];
    ind[a] = cnt1++;
}

void pop(obj &p)
{
    while(p.size() > 10)
    {
        p.cnt--;
    }
}

int buf[1000];

obj merge(obj &x, obj &y)
{
    int cnt = 0;
    FOR(i, x.SZ) buf[cnt++] = x.a[i];
    FOR(i, y.SZ) buf[cnt++] = y.a[i];
    sort(buf, buf + cnt);
    cnt = unique(buf, buf + cnt) - buf;
    obj ans;
    cnt = min(cnt, 10);
    ans.cnt = cnt;
    FOR(i, cnt) ans.a[i] = buf[i];
    return ans;
}

void update(int x)
{
    f[x].s = merge(f[f[x].l].s, f[f[x].r].s);
}

int bt(int a, int b)
{
    int x = cnt3++;
    f[x].a = a; f[x].b = b; f[x].s.cnt = 0;
    if(a < b)
    {
        int mid = MID(a, b);
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
    }
    return x;
}

// Query On ST, Do not Call Directly
obj query(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].s;
    int mid = MID(f[x].a, f[x].b);
    obj ans; ans.cnt = 0;
    if(a <= mid) { obj L = query(f[x].l, a, b);  ans = merge(L, ans); }
    if(b > mid) { obj R = query(f[x].r, a, b);  ans = merge(R, ans); }
    pop(ans);
    return ans;
}

//Modify Point
void update(int x, int p, int cc)
{
    if(f[x].a == f[x].b) { f[x].s.add(cc); f[x].s.Sort(); pop(f[x].s); return; }
    int mid = MID(f[x].a, f[x].b);
    if(p <= mid) update(f[x].l, p, cc);
    else update(f[x].r, p, cc);
    update(x);
}

obj query(int x, int y)
{
    obj ans;
    int fx = top[x], fy = top[y];
    LL sum = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        obj s = query(rt, w[fx], w[x]);
        ans = merge(ans, s);
        pop(ans);
        x = fa[top[x]];
        fx = top[x];
    }
    pop(ans);
    if(dep[x] > dep[y]) swap(x, y);
    //if(x == y) return ans;
    obj s = query(rt, w[x], w[y]);
    ans = merge(ans, s);
    pop(ans);
    return ans;
}

int main()
{
    //freopen("E.in", "r", stdin);
    cnt1 = cnt2 = cnt3 = 0;
    memset(ind, -1, sizeof ind);
    int Q;
    scanf("%d%d%d", &n, &m, &Q);
    FOR(i, n - 1)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    dfs1(ROOT, 0); dfs2(ROOT, 1);
    rt = bt(1, cnt2);
    FORR(i, m) { int x; scanf("%d", &x); update(rt, w[x], i); }
    FOR(i, Q)
    {
        int x, y, a; scanf("%d%d%d", &x, &y, &a);
        obj ans = query(x, y);
        int p = min(a, (int)ans.SZ);
        printf("%d ", p);
        FOR(i, p) printf("%d ", ans.a[i]);
        printf("\n");
    }
    return 0;
}
