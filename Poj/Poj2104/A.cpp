#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100010
#define NN (30 * N)
namespace ST
{
    int T[N];
    struct node
    {
        int l, r, a, b;
        int c;
        node() {}
    }f[NN];
    int cnt;
    int lb, ub;

    int add(int a, int b, int l, int r, int c)
    {
        f[cnt].a = a; f[cnt].b = b; f[cnt].l = l; f[cnt].r = r; f[cnt].c = c;
        return cnt++;
    }

    int build(int a, int b)
    {
        int rt = add(a, b, -1, -1, 0);
        if(a < b)
        {
            int mid = (a + b) >> 1;
            f[rt].l = build(a, mid);
            f[rt].r = build(mid + 1, b);
        }
        return rt;
    }

    void init(int a, int b) { cnt = 0; T[b + 1] = build(a, b); lb = a; ub = b; }

    int update(int x, int p)
    {
        int rt = add(lb, ub, -1, -1, f[x].c + 1), tmp = rt;
        int l = lb, r = ub;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(p <= mid)
            {
                f[rt].l = add(l, mid, -1, -1, 0);
                f[rt].r = f[x].r;
                rt = f[rt].l; x = f[x].l;
                r = mid;
            }
            else
            {
                f[rt].r = add(mid + 1, r, -1, -1, 0);
                f[rt].l = f[x].l;
                rt = f[rt].r; x = f[x].r;
                l = mid + 1;
            }
            f[rt].c = f[x].c + 1;
        }
        return tmp;
    }

    int qry(int lx, int rx, int k)
    {
        int l = lb, r = ub;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(f[f[lx].l].c - f[f[rx].l].c >= k)
            {
                rx = f[rx].l; lx = f[lx].l;
                r = mid;
            }
            else
            {
                k -= (f[f[lx].l].c - f[f[rx].l].c);
                rx = f[rx].r; lx = f[lx].r;
                l = mid + 1;
            }
        }
        return l;
    }

    int q(int l, int r, int k)
    {
        return qry(T[l], T[r + 1], k);
    }
}

int n, m;
int h[N], a[N];

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    memcpy(h, a, sizeof a);
    sort(h, h + n);
    int cnt = unique(h, h + n) - h;
    for(int i = 0; i < n; i++) a[i] = lower_bound(h, h + n, a[i]) - h;

    ST::init(0, cnt - 1);
    for(int i = n - 1; i > -1; i--) ST::T[i] = ST::update(ST::T[i + 1], a[i]);
    while(m--)
    {
        int i, j, k; scanf("%d%d%d", &i, &j, &k);
        printf("%d\n", h[ST::q(i - 1, j - 1, k)]);
    }
    return 0;
}