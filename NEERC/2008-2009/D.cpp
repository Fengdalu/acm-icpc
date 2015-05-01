#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 1000010
#define M 100010

LL c[N];
int a[M], b[M];
int n, m;

int main()
{
    freopen("deposits.in", "r", stdin);
    freopen("deposits.out", "w", stdout);
    memset(c, 0, sizeof c);

    scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m); for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(b, b + m);

    int x = b[0];
    int cc = 1;
    for(int i = 1; i < m; i++)
    {
        if(b[i] != b[i - 1])
        {
            for(int j = x; j < N; j += x) c[j] += (LL)cc;
            cc = 0; x = b[i];
        }
        cc++;
    }
    for(int j = x; j < N; j += x) c[j] += (LL)cc;
    LL ans = 0;
    for(int i = 0; i < n; i++)
        ans += c[a[i]];
    printf("%I64d\n", ans);
    fclose(stdout);
    return 0;
}