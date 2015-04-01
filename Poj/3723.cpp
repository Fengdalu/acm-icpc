#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[30000];
struct obj
{
    int a, b, c;
}a[60000];

int cmp(obj a, obj b)
{
    return a.c > b.c;
}

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

int main()
{
    ios::sync_with_stdio(false);
    int T; scanf("%d", &T);
    while(T--)
    {
        int n, m, r;
        scanf("%d%d%d", &n, &m, &r);
        for(int i = 0; i < r; i++) scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
        sort(a, a + r, cmp);
        for(int i = 0; i <= n + m; i++) f[i] = i;
        long long tot = 0;
        for(int i = 0; i < r; i++)
        {
            if(find(a[i].a) != find(a[i].b + n))
            {
                tot += (long long)a[i].c;
                f[find(a[i].a)] = find(a[i].b + n);
            }
        }
        printf("%I64d\n", ((long long)n + m) * 10000L - tot);
    }
    return 0;
}
