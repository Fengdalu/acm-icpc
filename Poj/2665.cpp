#include <cstdio>
#include <algorithm>
#define MAXN 10000

long long a[MAXN], b[MAXN];

long long min(long long a, long long b)
{
    if (a < b) return a;
    return b;
}

long long max(long long a, long long b)
{
    if (a > b) return a;
    return b;
}

int main()
{
    long long l, m;
    while(scanf("%I64d%I64d", &l, &m) == 2)
    {
        if (m == 0 && l == 0) break;
        
        for (long long i = 0; i < m; i++)
            scanf("%I64d%I64d", &a[i], &b[i]);
        
        for (long long i = 0; i < m; i++)
            for (long long j = 0; j < m; j++)
            {
                if (i != j)
                {
                    if (b[i] >= a[j] && b[j] >= a[i])
                    {
                        a[i] = min(a[i], a[j]);
                        b[i] = max(b[i], b[j]);
                        b[j] = -2;
                        a[j] = -1;
                    }
                }
            }
        
        long long ans = 0;
        for (long long i = 0; i < m; i++)
        {
            if (a[i] <= b[i])
            {
                ans += b[i] - a[i] + 1;
            }
        }
        
        ans = l + 1 - ans;
        printf("%I64d\n", ans);
    }
    
    return 0;
}