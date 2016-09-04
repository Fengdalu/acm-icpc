#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define PII pair<LL, LL>
#define AA first
#define BB second
#define SIZE 100010

LL n;
LL m;

struct node
{
    int l, r;
    int a, b;
    LL m;
}f[300010];
PII a[100010];
LL c[100010], l[100010], r[100010];
int cnt;

int bt(int a, int b)
{
    int x = cnt++;
    f[x].a = a; f[x].b = b; f[x].m = 1;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
    }
    return x;
}

void pd(int x)
{
    if(f[x].m == 1) return;
    f[f[x].l].m = (f[f[x].l].m * f[x].m) % m;
    f[f[x].r].m = (f[f[x].r].m * f[x].m) % m;
    f[x].m = 1;
}

void ins(int x, int a, int b, LL c)
{
    if(a <= f[x].a && f[x].b <= b) { f[x].m = (f[x].m * c) % m; return; }
    int mid = (f[x].a + f[x].b) / 2;
    pd(x);
    if(a <= mid) ins(f[x].l, a, b, c);
    if(b > mid) ins(f[x].r, a, b, c);
}

LL qry(int x, int p)
{
    if(f[x].a == f[x].b) return f[x].m;
    LL ans = f[x].m;
    int mid = (f[x].a + f[x].b) / 2;
    if(p <= mid) ans = (ans * qry(f[x].l, p) % m);
    else ans = (ans * qry(f[x].r, p) % m);
    return ans;
}



int main()
{
    //freopen("input.txt", "r", stdin);
    int _T;
    scanf("%d", &_T);
    for(int ii = 1; ii <= _T; ii++)
    {
        scanf("%I64d%I64d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            int x, y;  scanf("%d%d", &x, &y);
            if(x == 1) { l[i] = i; c[i] = y; r[i] = n; }
            else { l[i] = -1; r[y - 1] = i - 1; }
        }
        cnt = 0;
        int rt = bt(0, n);
        for(int i = 0; i < n; i++)
        if(l[i] != -1)
        {
            ins(rt, l[i], r[i], c[i]);
        }
        printf("Case #%d:\n", ii);
        for(int i = 0; i < n; i++)
            printf("%I64d\n", qry(rt, i));
    }
    return 0;
}