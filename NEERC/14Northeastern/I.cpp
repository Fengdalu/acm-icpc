#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define N 200010

int a[N];
int c[N];
int f[N], g[N];
int n;


inline int lowbit(int x) { return x & (-x); }

void insert(int p, int c)
{
    while(p <= n)
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
    freopen("improvements.in", "r", stdin);
    freopen("improvements.out", "w", stdout);

    scanf("%d", &n);

    memset(a, 0, sizeof a);
    FOR1(i, n) scanf("%d", &c[i]);
    FOR1(i, n) { f[i] = 1 + qry(c[i]); insert(c[i], f[i]); }

    memset(a, 0, sizeof a);
    FOR1(i, n) { c[i] = n - c[i] + 1; }
    FOR1(i, n) { g[i] = 1 + qry(c[i]); insert(c[i], g[i]); }

    int ans = 0;
    FOR1(i, n) ans = max(ans, f[i] + g[i] - 1);
    printf("%d\n", ans);
    fclose(stdout);
    return 0;
}