#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100010
#define NN (30 * N)

namespace ST
{
    int T[N], cnt, ll, rr;
    struct node
    {
        int l, r;
        int a, b;
        int c;
    }f[NN];

    int add(int a, int b, int c)
    {
        f[cnt].a = a; f[cnt].b = b; f[cnt].c = c; f[cnt].l = f[cnt].r = -1;
        return cnt++;
    }

    int build(int a, int b)
    {
        int rt = add(a, b, 0);
        if(a < b)
        {
            int mid = (a + b) >> 1;
            f[rt].l = build(a, mid);
            f[rt].r = build(mid + 1, b);
        }
        return rt;
    }

    void init(int a, int b)
    {
        cnt = 0;
        ll = a; rr = b;
        T[0] = build(ll, rr);
    }

    int update(int x, int p)
    {
        int rt = add(ll, rr, f[x].c + 1), tmp = rt;
        int l = ll, r = rr;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(p <= mid)
            {
                f[rt].l = add(l, mid, 0); f[rt].r = f[x].r;
                rt = f[rt].l; x = f[x].l;
                r = mid;
            }
            else
            {
                f[rt].r = add(mid + 1, r, 0); f[rt].l = f[x].l;
                rt = f[rt].r; x = f[x].r;
                l = mid + 1;
            }
            f[rt].c = f[x].c + 1;
        }
        return tmp;
    }

    int query(int lx, int rx, int k)
    {
        int l = ll, r = rr;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(f[f[rx].l].c - f[f[lx].l].c >= k)
            {
                rx = f[rx].l; lx = f[lx].l;
                r = mid;
            }
            else
            {
                k -= (f[f[rx].l].c - f[f[lx].l].c);
                rx = f[rx].r; lx = f[lx].r;
                l = mid + 1;
            }
        }
        return l;
    }
}

int n, m;
int a[N];
int h[N];

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) h[i] = a[i + 1];
    sort(h, h + n);
    int cnt = unique(h, h + n) - h;
    for(int i = 1; i <= n; i++) a[i] = lower_bound(h, h + cnt, a[i]) - h;
    ST::init(0, cnt - 1);
    for(int i = 1; i <= n; i++) { ST::T[i] = ST::update(ST::T[i - 1], a[i]);  }
//    for(int i = 1; i <= n; i++) cout << h[ST::query(ST::T[i - 1], ST::T[i], 1)] << " "; cout << endl;
    while(m--)
    {
        int i, j, k; scanf("%d%d%d", &i, &j, &k);
        printf("%d\n", h[ST::query(ST::T[i - 1], ST::T[j], k)]);
    }
    return 0;
}