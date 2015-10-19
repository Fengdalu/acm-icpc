#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
#include <cmath>
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
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/
#define N 3000010

int n, Q;
char s[3000010];

struct node
{
    int L, R;
    int a, b;
    int Max;
    int Min;
    int Lazy;
}f[2 * N];
int c[N];
int cnt;
int rt;
set<int>S;

void update(int x)
{
    f[x].Max = max(f[f[x].L].Max, f[f[x].R].Max);
    f[x].Min = min(f[f[x].L].Min, f[f[x].R].Min);
}

void deal(int x, int c)
{
    f[x].Max += c;
    f[x].Min += c;
    f[x].Lazy += c;
}

void down(int x)
{
    if(f[x].Lazy == 0) return;
    deal(f[x].L, f[x].Lazy);
    deal(f[x].R, f[x].Lazy);
    f[x].Lazy = 0;
}


int build(int a, int b)
{
    int x = cnt++;
    f[x].a = a; f[x].b = b; f[x].Lazy = 0; f[x].Min = f[x].Max = 0;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[x].L = build(a, mid);
        f[x].R = build(mid + 1, b);
        update(x);
    }
    else f[x].Max = f[x].Min = c[a];
    return x;
}

void insert(int x, int a, int b, int c)
{
    if(a <= f[x].a && f[x].b <= b) deal(x, c);
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(b <= mid) insert(f[x].L, a, b, c);
        else if(a > mid) insert(f[x].R, a, b, c);
        else { insert(f[x].L, a, b, c); insert(f[x].R, a, b, c); }
        update(x);
    }
}

int query(int x, int p)
{
    if(f[x].a == f[x].b) return f[x].Min;
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) return query(f[x].L, p);
        return query(f[x].R, p);
    }
}

int query(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].Min;
    else
    {
        down(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(b <= mid) return query(f[x].L, a, b);
        else if(a > mid) return query(f[x].R, a, b);
        return min(query(f[x].L, a, b), query(f[x].R, a, b));
    }
}

int cal(int p, int c)
{
    int L = 1, R = p;
    while(L < R)
    {
        int mid = (L + R) / 2;
        if(query(rt, mid, p) >= 2) R = mid;
        else L = mid + 1;
    }
    return L;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(~scanf("%d%d", &n, &Q))
    {
        s[0] = 'a';
        scanf("%s", s + 1);
        MEM(c);
        S.CLR;
        c[0] = 0;
        FORR(i, n) { c[i] = c[i - 1]; if(s[i] == '(') c[i]++; else c[i]--; }

        FORR(i, n) if(s[i] == ')') S.insert(i);

        cnt = 0;
        rt = build(1, n);
        FOR(i, Q)
        {
            int x; scanf("%d", &x); int T;
            if(s[x] == '(')
            {
                if(S.SZ && *S.OP <= x)
                {
                    printf("%d\n", *S.OP);
                    T = *S.OP;
                }
                else
                {
                    printf("%d\n", x);
                    T = x;
                }
                s[x] = ')';
                s[T] = '(';
                if(x == T) continue;
                if(S.find(T) != S.ED) S.erase(S.find(T));
                S.insert(x);
                insert(rt, x, n, -2);
                insert(rt, T, n, 2);
            }
            else
            {
                int p;
                if(x - 1 > 0 && query(rt, x - 1) >= 2) p = cal(x - 1, query(rt, x));
                else p = x;
                printf("%d\n", p);
                T = p;
                s[x] = '(';
                s[T] = ')';
                if(x == T) continue;
                if(S.find(x) != S.ED)S.erase(S.find(x));
                S.insert(T);
                insert(rt, x, n, 2);
                insert(rt, T, n, -2);
            }
            //cout <<"S ";  FORR(i, n) cout << query(rt, i, i) << " "; cout << endl;
        }
    }
    return 0;
}
