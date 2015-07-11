#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
#define LL long long
#define N 2000
#define INF 1e13

int n, p;
int c[N];
LL cal()
{
    LL ans = -INF;
    LL sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum < 0) sum = c[i];
        else sum = sum + c[i];
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &p);
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        LL ans = -INF;
        for(int i = 0; i < n; i++)
        {
            int tmp = c[i];
            c[i] = p;
            //cout << cal() << endl;
            ans = max(ans, cal());
            c[i] = tmp;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
