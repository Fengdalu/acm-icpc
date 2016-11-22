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
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define N 100100

int a[N];
int n;

inline int lowbit(int x) { return x & (-x); }
void insert(int p, int c)
{
    while(p <= n)
    {
        a[p] += c;
        p += lowbit(p);
    }
}

int query(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

PII c[100001];
vector<int>H;

int main()
{
    freopen("john.in", "r", stdin);
    freopen("john.out", "w", stdout);

    scanf("%d", &n);
    FOR(i, n) scanf("%d%d", &c[i].AA, &c[i].BB);
    H.clear();
    FOR(i, n) H.PB(c[i].BB);
    sort(H.OP, H.ED);
    H.resize(unique(H.OP, H.ED) - H.OP);
    FOR(i, n) c[i].BB = lower_bound(H.OP, H.ED, c[i].BB) - H.OP + 1;

    memset(a, 0, sizeof a);
    sort(c, c + n);
    LL ans = (LL)(n) * (n - 1) / 2LL;

    for(int i = 0; i < n; i++)
    {
        ans -= (LL)query(c[i].BB);
        insert(c[i].BB, 1);
    }
    printf("%I64d\n", ans);
    return 0;
}