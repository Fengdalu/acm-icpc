#include <iostream>
#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define N 100010
#define LL long long

LL a[N], f[N], g[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    a[0] = 0;
    a[n + 1] = 0;
    memset(f, 0, sizeof f); memset(g, 0, sizeof g); f[0] = g[n + 1] = 0;
    for(int i = 1; i <= n; i++) f[i] = min(f[i - 1] + 1, a[i]);
    for(int i = n; i >= 1; i--) g[i] = min(g[i + 1] + 1, a[i]);
    LL ans = 0;
    for(int i = 1; i <= n; i++)  ans = max(ans, min(f[i], g[i]));
    printf("%I64d\n", ans);
    return 0;
}
