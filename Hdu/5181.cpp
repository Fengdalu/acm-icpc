#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 100010

using namespace std;

LL a[N], b[N];
int n, m;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);
        for(int i = 0; i < m; i++) scanf("%I64d", &b[i]);
        sort(a, a + n); sort(b, b + m);

        int i = n - 1, j = 0;
        LL ans = 0;
        while(i >= 0 && j < m)
        {
            if(a[i] >= b[j])
            {
                ans += (LL)((LL)a[i] - (LL)b[j]);
                i--;
                j++;
            }
            else break;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
