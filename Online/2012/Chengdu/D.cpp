#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define S first
#define W second
#define N 100010
#define LL long long
#define INF 1e15

int n;
PII f[N];

int cmp(const PII &a, const PII &b)
{
    int m1 = max(-a.S, a.W - b.S);
    int m2 = max(-b.S, b.W - a.S);
    return m1 < m2;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) scanf("%d%d", &f[i].W, &f[i].S);
        sort(f, f + n, cmp);
        LL sum = 0;
        LL ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, sum - (LL)f[i].S);
            sum += (LL)f[i].W;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}