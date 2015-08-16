#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define N 100010
#define AA first
#define BB second
#define LL long long
#define N 400000


int A[N];
struct ST
{
    int rt;
    struct node
    {
        int l, r;
        int a, b;
        LL m, s;
    }f[N];
    int cnt;
    void init(int a, int b)
    {
        cnt = 0;
        rt = mt(a, b);
    }

    node update(const node &a, const node &b, int l, int r)
    {
        node p;
        p.a = a.a;
        p.b = b.b;
        p.l = l;
        p.r = r;

        p.s = a.s + b.s;
        p.m = max(a.m, b.m);
        return p;
    }

    LL sum(int x, int a, int b)
    {
        if(a <= f[x].a && f[x].b <= b) return f[x].s;
        int mid = (f[x].a + f[x].b) / 2;
        LL tot = 0;
        if(a <= mid) tot += sum(f[x].l, a, b);
        if(b > mid) tot += sum(f[x].r, a, b);
        return tot;
    }

    void modify(int x, int p, int k)
    {
        if(f[x].a == f[x].b) { f[x].s = f[x].m = k; return; }
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) modify(f[x].l, p, k);
        if(p > mid) modify(f[x].r, p, k);
        f[x] = update(f[f[x].l], f[f[x].r], f[x].l, f[x].r);
    }

    void mod(int x, int a, int b, int M)
    {
        if(f[x].a == f[x].b) { f[x].s %= M; f[x].m %= M; return; }
        if(f[x].m < M) return;
        int mid = (f[x].a + f[x].b) / 2;
        if(a <= mid) mod(f[x].l, a, b, M);
        if(b > mid) mod(f[x].r, a, b, M);
        f[x] = update(f[f[x].l], f[f[x].r], f[x].l, f[x].r);
    }

    int mt(int a, int b)
    {
        int tmp = cnt++;
        f[tmp].a = a; f[tmp].b = b;
        f[tmp].l = f[tmp].r = -1;
        if(a == b)
        {
            f[tmp].s = f[tmp].m = A[a];
        }
        else
        {
            int mid = (a + b) >> 1;
            f[tmp].l = mt(a, mid);
            f[tmp].r = mt(mid + 1, b);
            f[tmp] = update(f[f[tmp].l], f[f[tmp].r], f[tmp].l, f[tmp].r);
        }
        return tmp;
    }
}s;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i];
    s.init(1, n);
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            cout << s.sum(s.rt, x, y) << endl;
        }
        if(t == 2)
        {
            int x, y, z; cin >> x >> y >> z;
            s.mod(s.rt, x, y, z);
        }
        if(t == 3)
        {
            int p, k; cin >> p >> k;
            s.modify(s.rt, p, k);
        }
    }
    return 0;
}
