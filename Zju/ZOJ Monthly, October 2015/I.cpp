#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define PB(x) push_back(x)
#define CLR clear()
#define N 10000010
#define SZ size()

int prime[N];
vector<int>F;
int v[N];

void init()
{
    memset(prime, 0, sizeof prime);
    prime[1] = true;
    F.CLR;
    for(int i = 2; i < N; i++)
    {
        if(!prime[i]) F.PB(i);
        for(int j = 0; F[j] * i < N; j++)
        {
            prime[F[j] * i] = true;
            if(i % F[j] == 0) break;
        }
    }
}

struct node
{
    int s;
    int c;
}f[100010 * 4];
int cnt;

node merge(node p, node q)
{
    node r;
    r.s = p.s + q.s;
    r.c = (p.c == q.c) ? (p.c) : (-1);
    return r;
}

void bt(int x, int a, int b)
{
    if(a < b)
    {
        int mid = (a + b) / 2;
        bt(x << 1, a, mid);
        bt(x << 1 | 1, mid + 1, b);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }
    else
    {
        f[x].c = v[a];
        if(!prime[v[a]]) { f[x].s = 1; }
        else { f[x].s = 0; }
    }
}

void deal(int x, int l, int r, int c)
{
    if(!prime[c]) f[x].s = (r - l + 1);
    else f[x].s = 0;
    f[x].c = c;
}

void down(int x, int l, int r)
{
    if(f[x].c == -1) return;
    int mid = (l + r) / 2;
    deal(x << 1, l, mid, f[x].c);
    deal(x << 1 | 1, mid + 1, r, f[x].c);
}


void insert(int x, int l, int r, int a, int b, int c)
{
    if(a <= l && r <= b) deal(x, l, r, c);
    else
    {
        down(x, l, r);
        int mid = (l + r) / 2;
        if(b <= mid) insert(x << 1, l, mid, a, b, c);
        else if(a > mid) insert(x << 1 | 1, mid + 1, r, a, b, c);
        else { insert(x << 1, l, mid, a, b, c); insert(x << 1 | 1, mid + 1, r, a, b, c); }
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }
}

void add(int x, int l, int r, int p, int c)
{
    if(l == r) { f[x].c += c; if(!prime[f[x].c]) f[x].s = 1; else f[x].s = 0; }
    else
    {
        down(x, l, r);
        int mid = (l + r) / 2;
        if(p <= mid) add(x << 1, l, mid, p, c);
        else add(x << 1 | 1, mid + 1, r, p, c);
        f[x] = merge(f[x << 1], f[x << 1 | 1]);
    }
}

int query(int x, int l, int r, int a, int b)
{
    if(a <= l && r <= b) return f[x].s;
    else
    {
        down(x, l, r);
        int mid = (l + r) / 2;
        if(b <= mid) return query(x << 1, l, mid, a, b);
        else if(a > mid) return query(x << 1 | 1, mid + 1, r, a, b);
        else return query(x << 1, l, mid, a, b) + query(x << 1 | 1, mid + 1, r, a, b);
    }
}

char op[6];
int main()
{
    init();
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        int n, Q;
        scanf("%d%d", &n, &Q);
        for(int i = 1; i <= n; i++) scanf("%d",& v[i]);
        bt(1, 1, n);
        for(int i = 0; i < Q; i++)
        {
            int x, y;
            scanf("%s%d%d", op, &x, &y);
            if(op[0] == 'A') add(1, 1, n, y, x);
            else if(op[0] == 'Q') printf("%d\n", query(1, 1, n, x, y));
            else {int r; scanf("%d", &r); insert(1, 1, n, y, r, x); }
        }
    }
    return 0;
}
