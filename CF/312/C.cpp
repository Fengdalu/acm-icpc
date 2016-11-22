#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 100010
#define M 1000100

using namespace std;
int f[N], cnt[N];

void cal(int x, int q)
{
    int xx = x;
    int p = 1;
    cnt[x]++;
    x *= 2;
    while(x < N)    {
        if(cnt[x] == q){ f[x] += p; cnt[x]++; }
        p++; x *= 2;
    }
    x = xx; p = 1;
    while(x != 1)
    {
        if(x & 1)
        {
            int t = x / 2, pp = p;
            while(t < N)
            {
                if(cnt[t] == q) { f[t] += pp; cnt[t]++; }
                pp++; t *= 2;
            }
        }
        else
            if(cnt[x / 2] == q) {f[x / 2] += p; cnt[x / 2]++;}
        x /= 2;
        p++;
    }
}

int main()
{
    memset(f, 0, sizeof f);
    memset(cnt, 0, sizeof cnt);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x; scanf("%d", &x);
        cal(x, i);
    }
    int ans = 1000000000;
    for(int i = 0; i < N; i++) if(cnt[i] == n) ans = min(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
