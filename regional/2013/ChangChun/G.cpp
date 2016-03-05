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
#define u32 usigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) y = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b), make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, L, R) for(int i = L; i <= (R); i++)
#define MEM(x) memset(a, 0, sizeof a);
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*====================================*/
#define N 500
int c[N][N];
int lx[N], ly[N];
int n, Q;
struct Node
{
    struct node
    {
        int a, b;
        int Min, Max;
    }f[N];
    int a, b;

    void update(int x)
    {
        f[x].Min = min(f[x << 1].Min, f[x << 1 | 1].Min);
        f[x].Max = max(f[x << 1].Max, f[x << 1 | 1].Max);
    }

    void build(int x, int a, int b)
    {
        f[x].a = a; f[x].b = b;
        if(a < b)
        {
            int mid = (a + b) / 2;
            build(x << 1, a, mid);
            build(x << 1 | 1, mid + 1, b);
            update(x);
        } else { f[x].Min = f[x].Max = 0; ly[a] = x; }
    }

    int queryMin(int x, int a, int b)
    {
        if(a <= f[x].a && f[x].b <= b) return f[x].Min;
        else
        {
            int mid = (f[x].a + f[x].b) / 2;
            if(b <= mid) return queryMin(x << 1, a, b);
            else if(a > mid) return queryMin(x << 1 | 1, a, b);
            else return min(queryMin(x << 1, a, b), queryMin(x << 1 | 1, a, b));
        }
    }

    int queryMax(int x, int a, int b)
    {
        if(a <= f[x].a && f[x].b <= b) return f[x].Max;
        else
        {
            int mid = (f[x].a + f[x].b) / 2;
            if(b <= mid) return queryMax(x << 1, a, b);
            else if(a > mid) return queryMax(x << 1 | 1, a, b);
            else return max(queryMax(x << 1, a, b), queryMax(x << 1 | 1, a, b));
        }
    }
}f[N];

void build(int x, int a, int b, int p, int q)
{
    f[x].a = a; f[x].b = b;
    f[x].build(1, p, q);
    if(a < b)
    {
        int mid = (a + b) / 2;
        build(x << 1, a, mid, p, q);
        build(x << 1 | 1, mid + 1, b, p, q);
    }
    else lx[a] = x;
}

void update(int x, int y, int c)
{
    x = lx[x]; y = ly[y];
    for(int X = x; X != 0; X >>= 1)
        for(int Y = y; Y != 0; Y >>= 1)
        {
            if(f[X].f[Y].a == f[X].f[Y].b)
            {
                if(f[X].a == f[X].b)
                {
                    f[X].f[Y].Min = f[X].f[Y].Max = c;
                }
                else
                {
                    f[X].f[Y].Min = min(f[X << 1].f[Y].Min, f[X << 1 | 1].f[Y].Min);
                    f[X].f[Y].Max = max(f[X << 1].f[Y].Max, f[X << 1 | 1].f[Y].Max);
                }
            }
            else { f[X].update(Y); }
        }
}

int queryMin(int x, int a, int b, int p, int q)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].queryMin(1, p, q);
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(b <= mid) return queryMin(x << 1, a, b, p, q);
        else if(a > mid) return queryMin(x << 1 | 1, a, b, p, q);
        else return min(queryMin(x << 1, a, b, p, q), queryMin(x << 1 | 1, a, b, p, q));
    }
}

int queryMax(int x, int a, int b, int p, int q)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].queryMax(1, p, q);
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(b <= mid) return queryMax(x << 1, a, b, p, q);
        else if(a > mid) return queryMax(x << 1 | 1, a, b, p, q);
        else return max(queryMax(x << 1, a, b, p, q), queryMax(x << 1 | 1, a, b, p, q));
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int _T; scanf("%d", &_T);
    FORR(ii, _T)
    {
        scanf("%d", &n);
        build(1, 1, n, 1, n);
        FORR(i, n) FORR(j, n) { int x; scanf("%d", &x); update(i, j, x); }
        printf("Case #%d:\n", ii);
        scanf("%d", &Q);
        while(Q--)
        {
            int x, y, L; scanf("%d%d%d", &x, &y, &L);
            int Min = queryMin(1, max(1, x - L / 2), min(n, x + L / 2), max(1, y - L / 2), min(n, y + L / 2));
            int Max = queryMax(1, max(1, x - L / 2), min(n, x + L / 2), max(1, y - L / 2), min(n, y + L / 2));
            int v = (Min + Max) / 2;
            printf("%d\n", v);
            update(x, y, v);
        }
    }
    return 0;
}
