#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k; scanf("%d%d", &n, &k);
    long long ans = 0;
    int m;
    long long tot = n;

    int g = 2;
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &m);
        ans = ans + (long long)(m - 1);
        int pre = -2; int t;
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &t);
            if(pre == t - 1 && t == g) { g++; ans--; tot--; }
            pre = t;
        }
    }
    printf("%I64d\n", ans + tot - 1LL);
    return 0;
}
