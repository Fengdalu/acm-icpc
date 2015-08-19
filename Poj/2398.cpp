#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define PII pair<LL, LL>
#define V PII
#define X first
#define Y second
#define AA first
#define BB second
#define PL pair< PII, PII >
#define LL long long
#define eps 1e-8

PII lu, rd;
int ans[2000];
PL l[2000];
int f[2000];

int n, m;

PII operator - (const PII &a, const PII &b)
{
    return PII(a.X - b.X, a.Y - b.Y);
}

int operator < (const PL &a, const PL &b)
{
    return (a.AA.X < b.AA.X);
}

LL operator * (const PII &a, const PII &b)
{
    return b.Y * a.X - b.X * a.Y;
}

bool LEFT(const PII &s, const PL &l)
{
    return (l.AA - l.BB) * (s - l.BB) <= 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &m);
        scanf("%I64d%I64d", &lu.X, &lu.Y);
        scanf("%I64d%I64d", &rd.X, &rd.Y);

        l[0].AA = lu;
        l[0].BB.X = lu.X;
        l[0].BB.Y = rd.Y;
        for(int i = 1; i <= n; i++)
        {
            scanf("%I64d%I64d", &l[i].AA.X, &l[i].BB.X);
            l[i].AA.Y = lu.Y; l[i].BB.Y = rd.Y;
        }
        n++;
        l[n].AA = PII(rd.X, lu.Y);
        l[n].BB = rd;
        n++;
        sort(l, l + n);

        PII s;
        memset(f, 0, sizeof f);
        for(int i = 0; i < m; i++)
        {
            scanf("%I64d%I64d", &s.X, &s.Y);
            int ll = 0, rr = n - 1;
            while(ll < rr)
            {
                int mid = (ll + rr) / 2 + 1;
                if(LEFT(s, l[mid])) ll = mid;
                else rr = mid - 1;
            }
            f[ll]++;
        }

        int J = 0;
        memset(ans, 0, sizeof ans);
        for(int i = 0; i < n; i++) ans[f[i]]++;

        printf("Box\n");
        for(int i = 1; i <= 1000; i++)
        if(ans[i])
        {
            printf("%d: %d\n", i, ans[i]);
        }
    }
    return 0;
}
