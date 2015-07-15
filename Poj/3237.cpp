#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 10010
#define M 20010
#define FOR(i, n) for(int i = 0; i < n; i++)
#define INF 0x3f3f3f
int ind[N], w[N], son[N], top[N], sz[N], dep[N], fa[N];
int op[N], ed[N], pt[N];
int t[M], nt[M];
int n, m;
int cnt1, cnt2, cnt3;
int rt;
inline int getint() { static int x; scanf("%d", &x); return x;  }

struct node{
    int a, b;
    int l, r;
    bool flg;
    int m, n;
}f[M];

void deal(int x)
{
    f[x].flg = !f[x].flg;
    swap(f[x].m, f[x].n);
    f[x].m = -f[x].m; f[x].n = -f[x].n;
}

void down(int x)
{
    if(f[x].flg){
        if(f[x].a != f[x].b) { deal(f[x].l); deal(f[x].r); }
        f[x].flg = false;
    }
}

void up(int x)
{
    f[x].m = max(f[f[x].l].m, f[f[x].r].m);
    f[x].n = min(f[f[x].l].n, f[f[x].r].n);
}

void add(int fr, int to)
{
    t[cnt1] = to;
    nt[cnt1] = ind[fr];
    ind[fr] = cnt1;
    ++cnt1;
}

void dfs(int x)
{
    sz[x] = 1; son[x] = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x; dep[t[k]] = dep[x] + 1;
        dfs(t[k]); sz[x] += sz[t[k]];
        if(sz[son[x]] < sz[t[k]]) son[x] = t[k];
    }
}

void bt(int x, int p)
{
    w[x] = ++cnt2;
    top[x] = p;
    if(son[x]) bt(son[x], p);
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x] && t[k] != son[x]) bt(t[k], t[k]);
}

int mt(int a, int b)
{
    int tmp = ++cnt3;
    f[tmp].a = a; f[tmp].b = b; f[tmp].m = -INF; f[tmp].flg = false; f[tmp].n = INF;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[tmp].l = mt(a, mid);
        f[tmp].r = mt(mid + 1, b);
    }
    return tmp;
}

int getmax(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].m;
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        int m = -INF;
        if(a <= mid) m = max(m, getmax(f[x].l, a, b));
        if(b > mid) m = max(m, getmax(f[x].r, a, b));
        up(x);
        return m;
    }
}

int getmax(int v1, int v2)
{
    int f1 = top[v1], f2 = top[v2];
    int m = -INF;
    while(f1 != f2)
    {

        if(dep[f1] < dep[f2]) { swap(f1, f2); swap(v1, v2); }
        //cout << f1 << " " << v1 << " ";
        m = max(m, getmax(rt, w[f1], w[v1]));
        v1 = fa[f1]; f1 = top[v1];
        // cout << m << endl;
    }
    if(v1 == v2) return m;
    if(dep[v1] > dep[v2]) swap(v1, v2);
    return max(m, getmax(rt, w[son[v1]], w[v2]));
}



void ng(int x, int a, int b)
{
    //cout << "NG: " << f[x].a << " " << f[x].b << endl;
    if(a <= f[x].a && f[x].b <= b) deal(x);
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(a <= mid) ng(f[x].l, a, b);
        if(b > mid) ng(f[x].r, a, b);
        up(x);
    }
}

void ng(int v1, int v2)
{
    int f1 = top[v1], f2 = top[v2];
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2]) { swap(f1, f2); swap(v1, v2); }
        ng(rt, w[f1], w[v1]);
        v1 = fa[f1]; f1 = top[v1];
    }
    if(v1 == v2) return;
    if(dep[v1] > dep[v2]) swap(v1, v2);
    return ng(rt, w[son[v1]], w[v2]);
}

char buf[100];
void ins(int x, int p, int c)
{
    if(f[x].a == f[x].b) { f[x].flg = false; f[x].n = f[x].m = c; }
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) ins(f[x].l, p, c);
        else ins(f[x].r, p, c);
        up(x);
    }
    // cout << "INS: " << f[x].a << " " << f[x].b << " " << f[x].n << endl;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int T = getint();
    for(int ii = 0; ii < T; ii++)
    {
        memset(son, 0, sizeof son); memset(sz, 0, sizeof sz); memset(fa, 0, sizeof fa); memset(top, 0, sizeof top);
        cnt1 = cnt2 = cnt3 = 0;

        n = getint();
        for(int i = 1; i <= n; i++) ind[i] = -1;
        for(int i = 0; i < n - 1; i++) { op[i] = getint(); ed[i] = getint(); pt[i] = getint(); add(op[i], ed[i]); add(ed[i], op[i]); }
        dfs(1); bt(1, 1); rt = mt(0, n);
        FOR(i, n - 1) { if(fa[op[i]] == ed[i]) ins(rt, w[op[i]], pt[i]); else ins(rt, w[ed[i]], pt[i]); }
        //for(int i = 1; i <= n; i++) cout << getmax(rt, i, i) << endl;

        /*
        cout << "FA: "; for(int i = 1; i <= n; i++) cout << fa[i] << " "; cout << endl;
        cout << "W: "; for(int i = 1; i <= n; i++) cout << w[i] << " "; cout << endl;
        cout << "TOP: "; for(int i = 1; i <= n; i++) cout << top[i] << " "; cout << endl;
        */
        while(true)
        {
            scanf("%s", &buf);
            if(!strcmp(buf, "DONE")) break;
            if(!strcmp(buf, "QUERY")) { int fr = getint(), to = getint(); printf("%d\n", getmax(fr, to)); }
            if(!strcmp(buf, "NEGATE")) { int fr = getint(), to = getint(); ng(fr, to); }
            if(!strcmp(buf, "CHANGE"))
            {
                int i = getint(), cc = getint(); i--;
                // cout << "CHANGE : " << i << " " << cc << endl;
                if(fa[op[i]] == ed[i]) ins(rt, w[op[i]], cc); else ins(rt, w[ed[i]], cc);
            }
        }
    }

    return 0;
}
