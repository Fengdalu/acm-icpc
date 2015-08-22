#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f
#define N 50010
#define LL long long

int f[N];
LL w[N];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

int qry(int p)
{
    int ans = 0;
    while(p)
    {
        ans += f[p];
        p -= lowbit(p);
    }
    return ans;
}


void add(int a, int p)
{
    while(a <= n)
    {
        f[a] += p;
        a += lowbit(a);
    }
}

LL gcd(LL a, LL b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; i++) { scanf("%I64d", &w[i]); }
        for(int i = 0; i < m; i++)
        {
            int l, r; scanf("%d%d", &l, &r);
            add(r + 1, -1);
            add(l, 1);
        }
        LL tot = 0;
        for(int i = 1; i <= n; i++)
        {
            LL c = qry(i);
            tot += w[i] * c * (c - 1) * (c - 2) / 6;
        }
        LL sum = (LL)m * (m - 1) * (m - 2) / 6;
        LL div = gcd(sum, tot);
        div = max(div, 1LL);
        if(tot == 0 || tot % sum == 0) printf("%I64d\n", tot / div);
        else printf("%I64d/%I64d\n", tot / div, sum / div);
    }

    return 0;
}
