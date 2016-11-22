#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define LL long long

int a[5000], b[5000];
int v, n;

int main()
{
    scanf("%d%d", &n, &v);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for(int i = 0; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        a[x] += y;
        b[x + 1] += y;
    }
    LL tot = 0;
    for(int i = 0; i < 5000; i++)
    {
        int t = v;
        if(b[i])
        {
            int d = min(t, b[i]);
            b[i] -= d;
            tot += d;
            t -= d;
        }
        if(a[i])
        {
            int d = min(t, a[i]);
            a[i] -= d;
            b[i + 1] -= d;
            tot += d;
        }
    }
    printf("%I64d\n", tot);
    return 0;
}
