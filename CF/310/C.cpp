#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long
#define OP begin()
#define ED end()
#define N 200010
#define M 400010

int IND[2 * N];
int n, m;
int x[N], y[N], c[N];
char buf[10];

struct node
{
    int l, r;
    int a, b;
    int m;
}f1[2 * M], f2[2 * M];
int r1, r2;
int cnt1, cnt2;

int mt(int a, int b, int& cnt, node f[M])
{
    int t = ++cnt;
    int mid = (a + b) / 2;
    f[t].a = a;
    f[t].b = b;
    f[t].m = 0;
    if(a < b)
    {
        f[t].l = mt(a, mid, cnt, f);
        f[t].r = mt(mid + 1, b, cnt, f);
    }
    return t;
}

void insert(node f[M],int x, int a, int b, int m)
{
    if(a <= f[x].a && f[x].b <= b) f[x].m = max(f[x].m, m);
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(a <= mid) insert(f, f[x].l, a, b, m);
        if(b > mid) insert(f, f[x].r, a, b, m);
        //f[x].m = max(f[f[x].l].m, f[f[x].r].m);
    }
}

int cal(node f[M], int x, int a, int b)
{
    //cout << f[x].a << " " << f[x].b << endl;
    if(a <= f[x].a && f[x].b <= b) return f[x].m;
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        int ans = 0;
        if(a <= mid) ans = max(ans, cal(f, f[x].l, a, b));
        if(b > mid) ans = max(ans, cal(f, f[x].r, a, b));
        return max(f[x].m, ans);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%s", &x[i], &y[i], buf);
        if(!strcmp(buf, "U")) c[i] = 1; else c[i] = 2;
        IND[i] = x[i];
        IND[i + m] = y[i];
    }
    IND[2 * m] = 0;
    sort(IND, IND + 2 * m + 1);
    int nn = unique(IND, IND + 2 * m + 1) - IND;
    for(int i = 0; i < m; i++)
    {
        x[i] = lower_bound(IND, IND + nn, x[i]) - IND;
        y[i] = lower_bound(IND, IND + nn, y[i]) - IND;
    }
    cnt1 = cnt2 = 0;
    r1 = mt(0, M, cnt1, f1); r2 = mt(0, M, cnt2, f2);

    int bg;
    for(int i = 0; i < m; i++)
    {
        if(c[i] == 1)
        {
            bg = cal(f1, r1, x[i], x[i]);
            printf("%d\n", IND[y[i]] - IND[bg]);
            insert(f2, r2, bg + 1, y[i], x[i]);
            insert(f1, r1, x[i], x[i], y[i]);
        }
        else
        {
            bg = cal(f2, r2, y[i], y[i]);
            printf("%d\n", IND[x[i]] - IND[bg]);
            insert(f1, r1, bg + 1, x[i], y[i]);
            insert(f2, r2, y[i], y[i], x[i]);
        }
    }
    return 0;
}
