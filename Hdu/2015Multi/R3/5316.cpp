#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define N 100020
#define INF 1e15
struct node
{
    int l, r;
    int a, b;
    LL m;
    LL ll, rr;
    LL sum;
    bool flg;
}f[4 * N];
int a[N];
int n, m;
int cnt;

bool ip(LL x)
{
    return abs(x) & 1;
}

bool IP(LL x, LL y)
{
    return ip(x) ^ ip(y);
}

node update(int ll, int rr)
{
    node F;
    F.l = ll; F.r = rr;
    node L = f[ll], R = f[rr];
    F.a = L.a; F.b = R.b;
    int mid = (F.a + F.b) / 2;

    F.m = max(L.m, R.m);
    F.flg = false;
    F.sum = -INF;

    F.ll = L.ll;
    F.rr = R.rr;

    if(mid + 1 <= n && IP(a[mid], a[mid + 1]))    {
        if(L.sum != -INF && R.sum != INF) F.sum = L.sum + R.sum;
        if(L.rr + R.ll > F.m)
        {
            F.m = L.rr + R.ll;
            if(L.flg && R.flg) F.flg = true;
        }
        if(R.flg) F.rr = max(F.rr, L.rr + R.ll);
        if(L.flg) F.ll = max(F.ll, L.rr + R.ll);
    }
    F.ll = max(F.ll, F.sum);
    F.rr = max(F.rr, F.sum);
    F.m = max(F.m, F.sum);
    return F;
}

node update(node L, node R)
{
    node F;

    F.a = L.a; F.b = R.b;
    int mid = (F.a + F.b) / 2;

    F.m = max(L.m, R.m);
    F.flg = false;
    F.sum = -INF;

    F.ll = L.ll;
    F.rr = R.rr;

    if(mid + 1 <= n && IP(a[mid], a[mid + 1]))    {
        if(L.sum != -INF && R.sum != INF) F.sum = L.sum + R.sum;
        if(L.rr + R.ll > F.m)
        {
            F.m = L.rr + R.ll;
            if(L.flg && R.flg) F.flg = true;
        }
        if(R.flg) F.rr = max(F.rr, L.rr + R.ll);
        if(L.flg) F.ll = max(F.ll, L.rr + R.ll);
    }
    F.ll = max(F.ll, F.sum);
    F.rr = max(F.rr, F.sum);
    F.m = max(F.m, F.sum);
    return F;
}

void modify(int x, int p, int c)
{
    //cout << f[x].a << " " << f[x].b << endl;
    if(f[x].a == f[x].b) {
        f[x].m = c;
        f[x].sum = c;
        a[p] = c;
        f[x].rr = f[x].ll = c;
        f[x].flg = true;
    }
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) modify(f[x].l, p, c);
        else modify(f[x].r, p, c);
        f[x] = update(f[x].l, f[x].r);
    }
}

void dfs(int x)
{
    cout << f[x].a << " " << f[x].b << " " << f[x].m << " " << f[x].ll << " " << f[x].rr << " " << f[x].sum << endl;
    if(f[x].a != f[x].b)
    {
        dfs(f[x].l);
        dfs(f[x].r);
    }

}

node query(int x, int a, int b)
{
    //cout << f[x].a << " " << f[x].b << endl;
    if(a <= f[x].a && f[x].b <= b) return f[x];
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(a <= mid && b > mid) return update(query(f[x].l, a, b), query(f[x].r, a, b));
        if(a <= mid) return query(f[x].l, a, b);
        if(b > mid) return query(f[x].r, a, b);
    }
}

int bt(int aa, int bb)
{
    int tmp = cnt++;
    f[tmp].a = aa; f[tmp].b = bb;
    f[tmp].ll = f[tmp].rr = -INF;
    if(aa == bb)
    {
        f[tmp].m = a[aa];
        f[tmp].sum = a[aa];
        f[tmp].rr = f[tmp].ll = a[aa];
        f[tmp].flg = true;
    }
    else
    {
        int mid = (aa + bb) / 2;
        f[tmp].l = bt(aa, mid);
        f[tmp].r = bt(mid + 1, bb);
        f[tmp] = update(f[tmp].l, f[tmp].r);
    }
    return tmp;
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        cnt = 0;
        int rt = bt(1, n);
        // dfs(rt);
        for(int i = 0; i < m; i++)
        {
            int op, x, y;
            scanf("%d%d%d", &op, &x, &y);
            node ANS = query(rt, x, y);
            if(!op) printf("%I64d\n", max(ANS.m, ANS.sum));
            else modify(rt, x, y);
        }
    }
    return 0;
}
