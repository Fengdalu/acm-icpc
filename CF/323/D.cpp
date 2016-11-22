#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define N 305
#define M 200010
#define DHHHHHH 1000000

int a[N];
int c[M];
int f[M], g[M];
int cc[N], tt[N];
int n, T;


inline int lowbit(int x)  { return x & (-x); }
void insert(int p, int c)
{
    while(p <= N)
    {
        a[p] = max(a[p], c);
        p += lowbit(p);
    }
}

int qry(int p)
{
    int ans = 0;
    while(p > 0)
    {
        ans = max(ans, a[p]);
        p -= lowbit(p);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &T);
    FORR(i, n) scanf("%d", &c[i]);
    if(T < 1000)
    {
        int cnt = n;
        int CAS = T - 1;
        while(CAS--)
        {
            FORR(i, n)
            c[++cnt] = c[i];
        }
        n = cnt;
        memset(a, 0, sizeof a);
        int ans = 1;
        FORR(i, n)
        {
            f[i] = 1 + qry(c[i]);
            ans = max(ans, f[i]);
            insert(c[i], f[i]);
        }
        printf("%d\n", ans);
    }
    else
    {
        FORR(i, n) cc[c[i]]++;
        FORR(i, n) FORR(j, n) if(c[i] == c[j]) { tt[i - 1] = j; break; }
        int cnt = n;
        int nn = n;
        int CAS = 101;
        while(CAS--)
        {
            FORR(i, n)
            c[++cnt] = c[i];
        }
        n = cnt;
        memset(a, 0, sizeof a);
        FORR(i, n)
        {
            f[i] = 1 + qry(c[i]);
            insert(c[i], f[i]);
        }
        int QQ= 1231231231;
        FORR(i, n)
        {
            c[i] = 300 - c[i] + 1;
        }
        memset(a, 0, sizeof a);
        for(int i = n; i >= 1; i--)
        {
            g[i] = 1 + qry(c[i]);
            insert(c[i], g[i]);
        }

        LL ans = 1;
        T -= 102;
        T -= 102;
        FORR(i, n)
        {
            c[i] = 300 - c[i] + 1;
        }
        FORR(i, n)
        {
            ans = max(ans, f[i] + g[tt[(i - 1) % nn]] + (LL)T * cc[c[i]]);
        }
        printf("%I64d\n", ans);
    }
    int PPPP = 123123;
    return 0;
}
